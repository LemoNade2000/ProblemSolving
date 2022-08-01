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

int N, M, K;
Node* root;
Node* secRoot;
Node* origin;
Node* dest;
vector<Node*> people;
vector<Node*> work;
vector<int> canDo[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    root = new Node;
    root->num = 0; root->lastEdge = 0;
    dest = new Node;
    dest->num = 0; dest->lastEdge = 0;
    secRoot = new Node;
    secRoot->num = 1; secRoot->lastEdge = 0;
    people = vector<Node*>(N + 1);
    work = vector<Node*>(M + 1);
    origin = new Node;
    Edge* e = new Edge;
    e->start = origin; e->end = root;
    e->cap = N;
    e->flow = e->revFlow = 0;
    origin->adj.push_back(e);
    Edge* secE = new Edge;
    secE->start = origin; secE->end = secRoot;
    secE->cap = K;
    secE->flow = secE->revFlow = 0;
    origin->adj.push_back(secE);
    for(int i = 1; i <= N; i++){
        people[i] = new Node;
        people[i]->num = i;
        people[i]->lastEdge = 0;
        Edge* e = new Edge;
        e->start = root;
        e->end = people[i];
        e->cap = 1;
        e->flow = e->revFlow = 0;
        Edge* secE = new Edge;
        secE->start = secRoot;
        secE->end = people[i];
        secE->cap = 1;
        secE->flow = secE->revFlow = 0;
        root->adj.push_back(e);
        secRoot->adj.push_back(secE);
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