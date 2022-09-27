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
    int cap;
    int flow;
    int revFlow;
    Edge(){
        start = nullptr;
        end = nullptr;
        cap = flow = revFlow = 0;
    }
    Edge(Node* start, Node* end, int cap){
        this->start = start;
        this->end = end;
        this->cap = cap;
        this->flow = this->revFlow = 0;
    }
};

struct Node{
    int num;
    int level;
    vector<Edge*> adj;
    int lastEdge;
    Node(int num){
        this->num = num;
        this->level = -1;
        this->lastEdge = 0;
    }
};

int N, D, K;
Node* root;
Node* dest;
vector<Node*> people;
vector<Node*> dish;
vector<int> canDo[201];

bool bfs(){
    dest->level = -1;
    for(int i = 1; i <= N; i++){
        people[i]->level = -1;
    }
    for(int i = 1; i <= D; i++){
        dish[i]->level = -1;
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
    for(int &i = curr->lastEdge; i < curr->adj.size(); i++){
        Edge* next = curr->adj[i];
        if(next->end->level == curr->level + 1 && next->cap - next->flow > 0){
            int ret = dfs(next->end, end, min(minF, next->cap - next->flow));
            if(ret > 0){
                next->flow += ret;
                Edge* e = new Edge(next->end, next->start, ret);
                next->end->adj.push_back(e);
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
        root->lastEdge = dest->lastEdge = 0;
        for(int i = 1; i <= N; i++){
            people[i]->lastEdge = 0;
        }
        for(int i = 1; i <= D; i++){
            dish[i]->lastEdge = 0;
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> D;
    root = new Node(0);
    dest = new Node(0);
    people = vector<Node*>(N + 1);
    dish = vector<Node*>(D + 1);
    for(int i = 1; i <= D; i++){
        int n;
        cin >> n;
        dish[i] = new Node(i);
        Edge* e = new Edge(dish[i], dest, n);
        dish[i]->adj.push_back(e);
    }
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        people[i] = new Node(i);
        Edge* r = new Edge(root, people[i], K);
        root->adj.push_back(r);
        for(int j = 0; j < n; j++){
            int d;
            cin >> d;
            Edge* e = new Edge(people[i], dish[d], 1);
            people[i]->adj.push_back(e);
        }
    }
    cout << dinic();
    /*
    for(int i = 1; i <= N; i++){
        for(auto i : people[i]->adj){
            if(i->end->num != 0){
                cout << i->end->num << " " << i->flow << "\n";
            }
        }
    }
    */
    return 0;
}