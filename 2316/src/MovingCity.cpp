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

int N, P;
int cnt, ans;
vector<Node*> city;
vector<Node*> inCity;

bool bfs(){
    for(int i = 1; i <= N; i++){
        city[i]->level = -1;
        inCity[i]->level = -1;
    }
    queue<Node*> q;
    q.push(city[1]);
    city[1]->level = 1;
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
    if(city[2]->level == -1){
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
        for(int i = 1; i <= N; i++){
            city[i]->lastEdge = 0;
            inCity[i]->lastEdge = 0;
        }
        while(true){
            int temp = dfs(city[1], city[2], INT_MAX);
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
    cin >> N >> P;
    city = vector<Node*>(N + 1);
    inCity = vector<Node*>(N + 1);
    city[1] = new Node(1);
    city[2] = new Node(2);
    for(int i = 3; i <= N; i++){
        city[i] = new Node(i);
        inCity[i] = new Node(i);
        Edge* e = new Edge(city[i], inCity[i], 1, 0);
        Edge* se = new Edge(inCity[i], city[i], 0, 0);
        e->revEdge = se;
        se->revEdge = e;
        city[i]->adj.push_back(e);
        inCity[i]->adj.push_back(se);
    }
    inCity[1] = city[1];
    inCity[2] = city[2];
    for(int i = 1; i <= P; i++){
        int a, b;
        cin >> a >> b;
        Edge* e = new Edge(inCity[a], city[b], 1, 0);
        Edge* re = new Edge(city[b], inCity[a], 0, 0);
        Edge* se = new Edge(inCity[b], city[a], 1, 0);
        Edge* rse = new Edge(city[a], inCity[b], 0, 0);
        e->revEdge = re;
        re->revEdge = e;
        se->revEdge = rse;
        rse->revEdge = se;
        inCity[a]->adj.push_back(e);
        city[b]->adj.push_back(re);
        inCity[b]->adj.push_back(se);
        city[a]->adj.push_back(rse);
    }
    cout << dinic();
    return 0;
}