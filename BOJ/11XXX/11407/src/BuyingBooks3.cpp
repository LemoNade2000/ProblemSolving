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
    void init(){
        this->inQ = false;
        this->dist = MAX;
        this->parent = nullptr;
        this->visited = 0;
        this->parentEdge = nullptr;
    }
};

int N, M;
int ans, maxFlow;
Node* root;
Node* dest;
vector<Node*> people;
vector<Node*> bookstore;
vector<vector<int>> cMat;
vector<vector<int>> dMat;

int mcmf(){
    maxFlow = ans = 0;
    while(true){
        root->inQ = dest->inQ = false;
        root->dist = dest->dist = MAX;
        root->parent = dest->parent = nullptr;
        root->visited = dest->visited = 0;
        for(Node* i : people){
            i->init();
        }
        for(Node* i : bookstore){
            i->init();
        }
        queue<Node*> q;
        root->dist = 0;
        root->inQ = true;
        q.push(root);
        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();
            currNode->inQ = false;
            for(auto currEdge : currNode->adj){
                Node* nextNode = currEdge->end;
                if(currEdge->cap - currEdge->flow > 0 && currNode->dist + currEdge->cost < nextNode->dist){
                    nextNode->dist = currNode->dist + currEdge->cost;
                    nextNode->parent = currNode;
                    nextNode->parentEdge = currEdge;
                    if(nextNode->inQ == false){
                        q.push(nextNode);
                        nextNode->inQ = true;
                    }
                }
            }
        }
        if(!dest->parent){
            break;
        }
        int flow = MAX;
        for(Node* i = dest; i != root; i = i->parent){
            Edge* e = i->parentEdge;
            flow = min(flow, e->cap - e->flow);
        }
        maxFlow += flow;
        for(Node* i = dest; i != root; i = i->parent){
            Edge* e = i->parentEdge;
            Edge* re = e->revEdge;
            ans += flow * e->cost;
            e->flow += flow;
            re->flow -= flow;
        }
    }
    cout << maxFlow << "\n" << ans << "\n";
    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    people = vector<Node*>(N);
    bookstore = vector<Node*>(M);
    root = new Node(0);
    dest = new Node(N + 1);
    for(int i = 0; i < N; i++){
        int books;
        cin >> books;
        people[i] = new Node(i);
        Edge* e = new Edge(people[i], dest, books, 0);
        Edge* re = new Edge(dest, people[i], 0, 0);
        e->revEdge = re;
        re->revEdge = e;
        people[i]->adj.push_back(e);
        dest->adj.push_back(re);
    }
    for(int i = 0; i < M; i++){
        int books;
        cin >> books;
        bookstore[i] = new Node(i);
        Edge* e = new Edge(root, bookstore[i], books, 0);
        Edge* re = new Edge(bookstore[i], root, 0, 0);
        e->revEdge = re;
        re->revEdge = e;
        root->adj.push_back(e);
        bookstore[i]->adj.push_back(re);
    }
    cMat = vector<vector<int>>(M);
    for(int i = 0; i < M; i++){
        cMat[i] = vector<int>(N);
        for(int j = 0; j < N; j++){
            cin >> cMat[i][j];
        }
    }
    dMat = vector<vector<int>>(M);
    for(int i = 0; i < M; i++){
        dMat[i] = vector<int>(N);
        for(int j = 0; j < N; j++){
            cin >> dMat[i][j];
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            Edge* e = new Edge(people[j], bookstore[i], 0, -dMat[i][j]);
            Edge* re = new Edge(bookstore[i], people[j], cMat[i][j], dMat[i][j]);
            e->revEdge = re;
            re->revEdge = e;
            people[j]->adj.push_back(e);
            bookstore[i]->adj.push_back(re);
        }
    }
    mcmf();
    return 0;
}