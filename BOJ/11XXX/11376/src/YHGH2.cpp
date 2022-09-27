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
};

struct Node{
    int num;
    int level;
    vector<Edge*> adj;
    int lastEdge;
};

int N, M;
Node* root;
Node* dest;
vector<Node*> people;
vector<Node*> work;
vector<int> canDo[1001];

bool bfs(){
    root->level = -1; dest->level = -1;
    for(int i = 1; i <= N; i++){
        people[i]->level = -1;
    }
    for(int i = 1; i <= M; i++){
        work[i]->level = -1;
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
                Edge* e = new Edge;
                e->start = next->end;
                e->end = next->start;
                e->cap = ret;
                e->flow = e->revFlow = 0;
                next->end->adj.push_back(e);
            //    cout << "flow" << next->flow << "\n";
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
        for(int i = 1; i <= M; i++){
            work[i]->lastEdge = 0;
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
    cin >> N >> M;
    root = new Node;
    root->num = 0; root->lastEdge = 0;
    dest = new Node;
    dest->num = 0; dest->lastEdge = 0;
    people = vector<Node*>(N + 1);
    work = vector<Node*>(M + 1);
    for(int i = 1; i <= N; i++){
        people[i] = new Node;
        people[i]->num = i;
        people[i]->lastEdge = 0;
        Edge* e = new Edge;
        e->start = root;
        e->end = people[i];
        e->cap = 2;
        e->flow = e->revFlow = 0;
        root->adj.push_back(e);
    }
    for(int i = 1; i <= M; i++){
        work[i] = new Node;
        work[i]->num = i;
        work[i]->lastEdge = 0;
        Edge* e = new Edge;
        e->start = work[i];
        e->end = dest;
        e->cap = 1;
        e->flow = e->revFlow = 0;
        work[i]->adj.push_back(e);
    }
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int k;
            cin >> k;
            Edge* e = new Edge;
            e->start = people[i];
            e->end = work[k];
            e->cap = 1;
            e->flow = e->revFlow = 0;
            people[i]->adj.push_back(e);
        }
    }
    cout << dinic();
    return 0;
}