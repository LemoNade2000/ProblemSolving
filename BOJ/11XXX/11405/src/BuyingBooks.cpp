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

int N, M;
int cnt, ans;
Node* root;
Node* dest;
vector<Node*> people;
vector<Node*> bookstore;

int mcmf(){
    cnt = 0;
    ans = 0;
    while(true){
        root->inQ = dest->inQ = false;
        root->dist = dest->dist = MAX;
        root->parent = dest->parent = NULL;
        root->visited = dest->visited = 0;
        for(int i = 1; i <= N; i++){
            people[i]->inQ = false;
            people[i]->dist = MAX;
            people[i]->parent = NULL;
            people[i]->visited = 0;
            people[i]->parentEdge = NULL;
        }
        for(int i = 1; i <= M; i++){
            bookstore[i]->inQ = false;
            bookstore[i]->dist = MAX;
            bookstore[i]->parent = NULL;
            bookstore[i]->visited = 0;
            bookstore[i]->parentEdge = NULL;
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
        int ret = MAX;
        for(Node* i = dest; i != root; i = i->parent){
            Edge* e = i->parentEdge;
            ret = min(ret, e->cap - e->flow);
        }
        for(Node* i = dest; i != root; i = i->parent){
            Edge* e = i->parentEdge;
            Edge* re = e->revEdge;
            ans += ret * e->cost;
            e->flow += ret;
            re->flow -= ret;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    root = new Node(0);
    dest = new Node(0);
    people = vector<Node*>(N + 1);
    bookstore = vector<Node*>(M + 1);
    for(int i = 1; i <= N; i++){
        int a;
        cin >> a;
        people[i] = new Node(i);
        Edge* e = new Edge(people[i], dest, a, 0);
        Edge* se = new Edge(dest, people[i], 0, 0);
        e->revEdge = se;
        se->revEdge = e;
        people[i]->adj.push_back(e);
        dest->adj.push_back(se);
    }
    for(int i = 1; i <= M; i++){
        int a;
        cin >> a;
        bookstore[i] = new Node(i);
        Edge* e = new Edge(root, bookstore[i], a, 0);
        Edge* se = new Edge(bookstore[i], root, 0, 0);
        e->revEdge = se;
        se->revEdge = e;
        root->adj.push_back(e);
        bookstore[i]->adj.push_back(se);
    }
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            int a;
            cin >> a;
            Edge* e = new Edge(bookstore[i], people[j], MAX, a);
            Edge* se = new Edge(people[j], bookstore[i], 0, -a);
            e->revEdge = se;
            se->revEdge = e;
            bookstore[i]->adj.push_back(e);
            people[j]->adj.push_back(se);
        }
    }
    mcmf();
    cout << ans;
    return 0;
}