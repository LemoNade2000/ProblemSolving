#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 987654321

struct Node;
struct Edge;

struct Edge{
    Node* start;
    Node* end;
    Edge* revEdge;
    int cap;
    int flow;
    int revFlow;
    int cost;
    Edge(){
        start = NULL;
        end = NULL;
        cost = cap = flow = revFlow = 0;
    }
    Edge(Node* start, Node* end, int cap, int cost){
        this->start = start;
        this->end = end;
        this->cap = cap;
        this->cost = cost;
        this->flow = this->revFlow = 0;
    }
};

struct Node{
    int row, col;
    int level;
    vector<Edge*> adj;
    int lastEdge;
    bool inQ;
    int dist;
    Node* parent;
    Edge* parentEdge;
    int visited;
    char c;
    Node(int row, int col, char c){
        this->row = row;
        this->col = col;
        this->c = c;
        this->level = -1;   
        this->lastEdge = 0;
        this->inQ = false;
        this->dist = 0;
        this->parent = NULL;
        this->visited = 0;
        this->parentEdge = NULL;
    }
};

int N, M;
int cnt, ans;
Node* root;
Node* dest;
vector<vector<char>> board;
vector<vector<Node*>> boardNodesA;
vector<vector<Node*>> boardNodesB;

bool bfs(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            boardNodesA[i][j]->level = -1;
            boardNodesB[i][j]->level = -1;
        }
    }
    queue<Node*> q;
    q.push(root);
    root->level = 1;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        for(auto next : node->adj){
            if((next->end)->level == -1 && next->cap - next->flow > 0){
                next->end->level = node->level + 1;
                q.push(next->end);
            }
        }
    }
    if(dest->level == -1){
        return false;
    }
    return true;
}

int dfs(Node* curr, Node* end, int minF){
    if(curr == end){
        return minF;
    }
//    cout << curr->num << " " << curr->level << "\n";
    for(int &i = curr->lastEdge; i < curr->adj.size(); i++){
        Edge* next = curr->adj[i];
    //    cout << next->flow << "\n";
        if(next->end->level == curr->level + 1 && next->cap - next->flow > 0){
            int ret = dfs(next->end, end, min(minF, next->cap - next->flow));
            if(ret > 0){
                next->flow += ret;
                next->revEdge->flow -= ret;
                return ret;
            }
        }
    }
    curr->lastEdge = curr->adj.size();
    return 0;
}

int dinic(){
    ans = 0;
    while(bfs()){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                boardNodesA[i][j]->lastEdge = 0;
                boardNodesB[i][j]->lastEdge = 0;
            }
        } 
        while(true){
            int temp = dfs(root, dest, INT_MAX);
            if(temp == 0){
                break;
            }
            ans += temp;
        }
    }
    return ans;
}

void generateGraph(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == '#'){
                continue;
            }
            if(j < M - 1 && board[i][j + 1] != '#'){
                Edge* e = new Edge(boardNodesB[i][j], boardNodesA[i][j + 1], 1, 0);
                Edge* se = new Edge(boardNodesA[i][j + 1], boardNodesB[i][j], 0, 0);
                e->revEdge = se;
                se->revEdge = e;
                boardNodesB[i][j]->adj.push_back(e);
                boardNodesA[i][j + 1]->adj.push_back(se);
                Edge* re = new Edge(boardNodesB[i][j + 1], boardNodesA[i][j], 1, 0);
                Edge* rse = new Edge(boardNodesA[i][j], boardNodesB[i][j + 1], 0, 0);
                re->revEdge = rse;
                rse->revEdge = re;
                boardNodesB[i][j + 1]->adj.push_back(re);
                boardNodesA[i][j]->adj.push_back(rse);
            }
            if(i < N - 1 && board[i + 1][j] != '#'){
                Edge* e = new Edge(boardNodesB[i][j], boardNodesA[i + 1][j], 1, 0);
                Edge* se = new Edge(boardNodesA[i + 1][j], boardNodesB[i][j], 0, 0);
                e->revEdge = se;
                se->revEdge = e;
                boardNodesB[i][j]->adj.push_back(e);
                boardNodesA[i + 1][j]->adj.push_back(se);
                Edge* re = new Edge(boardNodesB[i + 1][j], boardNodesA[i][j], 1, 0);
                Edge* rse = new Edge(boardNodesA[i][j], boardNodesB[i + 1][j], 0, 0);
                re->revEdge = rse;
                rse->revEdge = re;
                boardNodesB[i + 1][j]->adj.push_back(re);
                boardNodesA[i][j]->adj.push_back(rse);
            }
            // if(j > 0 && board[i][j - 1] != '#'){
            //     Edge* e = new Edge(boardNodes[i][j], boardNodes[i][j - 1], 1, 0);
            //     Edge* se = new Edge(boardNodes[i][j - 1], boardNodes[i][j], 0, 0);
            //     e->revEdge = se;
            //     se->revEdge = e;
            //     boardNodes[i][j]->adj.push_back(e);
            //     boardNodes[i][j - 1]->adj.push_back(se);
            // }
            // if(i > 0 && board[i - 1][j] != '#'){
            //     Edge* e = new Edge(boardNodes[i][j], boardNodes[i - 1][j], 1, 0);
            //     Edge* se = new Edge(boardNodes[i - 1][j], boardNodes[i][j], 0, 0);
            //     e->revEdge = se;
            //     se->revEdge = e;
            //     boardNodes[i][j]->adj.push_back(e);
            //     boardNodes[i - 1][j]->adj.push_back(se);
            // }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    ans = 0;
    board = vector<vector<char>>(N);
    boardNodesA = boardNodesB = vector<vector<Node*>>(N);
    pii start;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        board[i] = vector<char>(M);
        boardNodesA[i] = boardNodesB[i] = vector<Node*>(M);
        for(int j = 0; j < M; j++){
            board[i][j] = str[j];
            boardNodesA[i][j] = new Node(i, j, str[j]);
            boardNodesB[i][j] = new Node(i, j, str[j]);
            Edge* e = new Edge(boardNodesA[i][j], boardNodesB[i][j], 1, 0);
            Edge* re = new Edge(boardNodesB[i][j], boardNodesA[i][j], 0, 0);
            e->revEdge = re;
            re->revEdge = e;
            boardNodesA[i][j]->adj.push_back(e);
            boardNodesB[i][j]->adj.push_back(re);
            if(str[j] == 'K'){
                root = boardNodesB[i][j];
                start.first = i; start.second = j;
            }
            else if(str[j] == 'H'){
                dest = boardNodesA[i][j];
            }
        }
    }
    generateGraph();
    for(auto i : boardNodesB[start.first][start.second]->adj){
        if(i->end == dest){
            cout << "-1";
            return 0;
        }
    }
    dinic();
    cout << ans;
    return 0;
}