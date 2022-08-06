#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 987654321

int TC;
int N, M, K;

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
    int character;
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
    int num;
    int level;
    vector<Edge*> adj[3];
    int lastEdge;
    bool inQ;
    int dist;
    Node* parent;
    Edge* parentEdge;
    int visited[3][4];
    int dp[3][4];
    int lastLen[3][4];
    Node(int num){
        this->num = num;
        this->level = -1;   
        this->lastEdge = 0;
        this->inQ = false;
        this->dist = 0;
        this->parent = NULL;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 4; j++){
                dp[i][j] = -2;
                visited[i][j] = 0;
                lastLen[i][j] = 0;
            }
        }
        this->parentEdge = NULL;
    }
};

vector<Node*> nodes;

int dfs(Node* node, int inC, int length, int left){
    if(node->dp[inC][left] != -2){
        return node->dp[inC][left];
    }
    if(node->visited[inC][left] > 0 || length >= M * 3){
        if(node->lastLen[inC][left] <= length - 3){
            return node->dp[inC][left] = MAX;
        }
        else return node->dp[inC][left] = 0;
    }
    node->visited[inC][left]++;
    node->lastLen[inC][left] = length;
    int nextC;
    if(inC == 0){
        nextC = 1;
    }
    else if(inC == 1){
        nextC = 2;
    }
    else if(inC == 2){
        nextC = 0;
    }
    int ret = 0;
    for(int i = 0; i < node->adj[nextC].size(); i++){
        Edge* nextEdge = node->adj[nextC][i];
        ret = max(dfs(nextEdge->end, nextC, length + 1, left) + 1, ret);
        if(ret == MAX){
            node->visited[inC][left]--;
            return node->dp[inC][left] = MAX;
        }
    }
    if(left == 3){
        for(int i = 0; i < node->adj[(nextC + 1) % 3].size(); i++){
            Edge* nextEdge = node->adj[(nextC + 1) % 3][i];
            ret = max(dfs(nextEdge->end, inC, length, left), ret);
            if(ret == MAX){
                node->visited[inC][left]--;
                return node->dp[inC][left] = MAX;
            }
        }
        for(int i = 0; i < node->adj[(nextC + 2) % 3].size(); i++){
            Edge* nextEdge = node->adj[(nextC + 2) % 3][i];
            ret = max(dfs(nextEdge->end, inC, length, left), ret);
            if(ret == MAX){
                node->visited[inC][left]--;
                return node->dp[inC][left] = MAX;
            }
        }
    }
    else if(left > 0 && left < 3){
        for(int i = 0; i < node->adj[(nextC + 1) % 3].size(); i++){
            Edge* nextEdge = node->adj[(nextC + 1) % 3][i];
            ret = max(dfs(nextEdge->end, inC, length, left - 1), ret);
            if(ret == MAX){
                node->visited[inC][left]--;
                return node->dp[inC][left] = MAX;
            }
        }
        for(int i = 0; i < node->adj[(nextC + 2) % 3].size(); i++){
            Edge* nextEdge = node->adj[(nextC + 2) % 3][i];
            ret = max(dfs(nextEdge->end, inC, length, left - 1), ret);
            if(ret == MAX){
                node->visited[inC][left]--;
                return node->dp[inC][left] = MAX;
            }
        }
    }
    node->visited[inC][left]--;
    return node->dp[inC][left] = ret;
}

int solve(){
    cin >> N >> M >>K;
    nodes = vector<Node*>(N + 1);
    for(int i = 1; i <= N; i++){
        Node* node = new Node(i);
        nodes[i] = node;
    }
    for(int i = 1; i <= M; i++){
        Edge* edge = new Edge;
        int a, b;
        char c;
        cin >> a >> b >> c;
        edge->start = nodes[a];
        edge->end = nodes[b];
        edge->character = (int)(c - 'A');
        nodes[a]->adj[edge->character].push_back(edge);
    }
    int ans = -1;
    if(K == -1){
        K = 3;
    }
    for(int i = 1; i <= N; i++){
        ans = max({dfs(nodes[i], 0, 0, K), dfs(nodes[i], 1, 0, K), dfs(nodes[i], 2, 0, K), ans});
    }
    if(ans >= MAX){
        cout << "-1" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
    cout << "Case #" << tc << endl;
    solve();
    }
    return 0;
}