#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

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
    int num;
    int level;
    vector<Edge*> adj;
    int lastEdge;
    bool inQ;
    int dist;
    Node* parent;
    Edge* parentEdge;
    int visited;
    Node(int num){
        this->num = num;
        this->level = -1;   
        this->lastEdge = 0;
        this->inQ = false;
        this->dist = 0;
        this->parent = NULL;
        this->visited = 0;
        this->parentEdge = NULL;
    }
};

vector<Node*> firstLayer;
vector<Node*> secondLayer;
Node* source;
Node* sink;
int N, M;

bool bfs(){
    source->level = -1; sink->level = -1;
    for(int i = 0; i < N; i++){
        firstLayer[i]->level = -1;
        secondLayer[i]->level = -1;
    }
    queue<Node*> q;
    q.push(source);
    source->level = 1;
    while(!q.empty()){
        Node* node = q.front();
        // cout << node->num << " ";
        q.pop();
        for(auto next : node->adj){
            if((next->end)->level == -1 && next->cap - next->flow > 0){
                next->end->level = node->level + 1;
                q.push(next->end);
            }
        }
    }
    if(sink->level == -1){
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
    int ans = 0;
    while(bfs()){
        for(int i = 0; i < N; i++){
            firstLayer[i]->lastEdge = 0;
            secondLayer[i]->lastEdge = 0;
        }
        source->lastEdge = 0;
        sink->lastEdge = 0;
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


int solve(){
    cin >> N >> M;
    source = new Node(0);
    sink = new Node(N);
    firstLayer = vector<Node*>(N);
    secondLayer = vector<Node*>(N);
    for(int i = 0; i < N; i++){
        firstLayer[i] = new Node(i);
        secondLayer[i] = new Node(i);
        Edge* e = new Edge(source, firstLayer[i], 1, 0);
        Edge* re = new Edge(firstLayer[i], source, 0, 0);
        e->revEdge = re;
        re->revEdge = e;
        source->adj.push_back(e);
        firstLayer[i]->adj.push_back(re);
        Edge* se = new Edge(secondLayer[i], sink, 1, 0);
        Edge* rse = new Edge(sink, secondLayer[i], 0, 0);
        se->revEdge = rse;
        rse->revEdge = se;
        secondLayer[i]->adj.push_back(se);
        sink->adj.push_back(rse);
    }
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        Edge* e = new Edge(firstLayer[u], secondLayer[v], 1, 0);
        Edge* re = new Edge(secondLayer[v], firstLayer[u], 0, 0);
        e->revEdge = re;
        re->revEdge = e;
        firstLayer[u]->adj.push_back(e);
        secondLayer[v]->adj.push_back(re);
    }
    cout << dinic() << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        solve();
    }
    return 0;
}