#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Node;
struct Edge;

struct Node{
    int idx;
    int level;
    int lastEdge;
    vector<Edge*> adj;
    Node(int idx){
        this->idx = idx;
        level = lastEdge = -1;
    }
};

struct Edge{
    Node* start;
    Node* end;
    Edge* revEdge;
    int cap;
    int flow;
    int revFlow;
    Edge(){
        start = end = nullptr;
        cap = flow = revFlow = 0;
    }
};

int N;
vector<int> rowSum, colSum;
vector<Node*> row;
vector<Node*> col;
Node* source;
Node* sink;
int low, high;

void init(){
    for(int i = 0; i < N; i++){
        row[i]->lastEdge = -1;
        row[i]->level = -1;
        col[i]->lastEdge = -1;
        col[i]->level = -1;
        source->level = -1;
        source->lastEdge = -1;
        sink->level = -1;
        sink->lastEdge = -1;
    }
    return;
}

void constEdge(Node* start, Node* end, int cap){
        Edge* e = new Edge();
        e->start = start;
        e->end = end;
        e->cap = cap;
        start->adj.push_back(e);
        Edge* re = new Edge();
        re->start = end;
        re->end = start;
        re->cap = 0;
        end->adj.push_back(re);
        e->revEdge = re;
        re->revEdge = e;
        return;
}

void edgeCap(int flow){
    for(auto edge : source->adj){
        edge->flow = 0;
        edge->revFlow = 0;
        edge->revEdge->flow = 0;
        edge->revEdge->revFlow = 0;
    }
    for(int i = 0; i < N; i++){
        for(auto edge : row[i]->adj){
            if(edge->end == source){
                continue;
            }
            edge->cap = flow;
            edge->flow = 0;
            edge->revFlow = 0;
            edge->revEdge->flow = 0;
            edge->revEdge->revFlow = 0;
        }
        for(auto edge: sink->adj){
            edge->flow = 0;
            edge->revFlow = 0;
            edge->revEdge->flow = 0;
            edge->revEdge->revFlow = 0;
        }
    }
    return;
}

bool bfs(){
    source->level = 1;
    sink->level = -1;
    for(int i = 0; i < N; i++){
        row[i]->level = -1;
        col[i]->level = -1;
    }
    queue<Node*> q;
    q.push(source);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        for(auto edge : node->adj){
            if(edge->end->level == -1 && edge->cap - edge->flow > 0){ // dest is not yet explored, and flow can further increase
                edge->end->level = node->level + 1;
                q.push(edge->end);
            }
        }
    }
    if(sink->level == -1){ // dest cannot be reached
        return false;
    }
    else return true;
}

int dfs(Node* curr, Node* end, int minFlow){
    if(curr == end){
        return minFlow;
    }
    for(int &i = curr->lastEdge; i < curr->adj.size(); i++){
        Edge* edge = curr->adj[i];
        if(edge->end->level == curr->level + 1 && edge->cap - edge->flow > 0){ // can further flow and neighbor by 1 level
            int ret = dfs(edge->end, end, min(minFlow, edge->cap - edge->flow));
            if(ret > 0){
                edge->flow += ret;
                edge->revEdge->flow -= ret;
                return ret;
            }
        }
    }
    curr->lastEdge = curr->adj.size();
    return 0;
}

int dinic(){
    int ans = 0;
    while(bfs()){
        source->lastEdge = sink->lastEdge = 0;
        for(int i = 0; i < N; i++){
            row[i]->lastEdge = 0;
            col[i]->lastEdge = 0;
        }
        while(true){
            int temp = dfs(source, sink, INT_MAX);
            if(temp == 0){
                break;
            }
            ans += temp;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    rowSum = vector<int>(N);
    colSum = vector<int>(N);
    row = vector<Node*>(N);
    col = vector<Node*>(N);
    for(int i = 0; i < N; i++){
        row[i] = new Node(i);
        col[i] = new Node(i);
    }
    source = new Node(0);
    sink = new Node(N);
    int sum = 0;
    vector<vector<int>> board(N);
    for(int i = 0; i < N; i++){
        board[i] = vector<int>(N);
    }
    for(int i = 0; i < N; i++){
        cin >> rowSum[i];
        constEdge(source, row[i], rowSum[i]);
        for(int j = 0; j < N; j++){
            constEdge(row[i], col[j], 0);
        }
        row[i]->idx = i;
        sum += rowSum[i];
    }
    for(int i = 0; i < N; i++){
        cin >> colSum[i];
        constEdge(col[i], sink, colSum[i]);
        col[i]->idx = i;
    }
    // source -> rowsum -> colsum -> sink
    low = 0; high = 10000;
    int max = 10001;
    while(low < high){
        init();
        int mid = (low + high) / 2;
        edgeCap(mid);
        int flow = dinic();
        if(flow == sum){
            max = min(max, mid);
            high = mid;
            for(int i = 0; i < N; i++){
                for(auto edge : row[i]->adj){
                    if(edge->end == source){
                        continue;
                    }
                    board[i][edge->end->idx] = edge->flow;
                }
            }
        }
        else{
            low = mid + 1;
        }
    }
    cout << max << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}