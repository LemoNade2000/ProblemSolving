#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAX 987654321

typedef long long ll;
typedef pair<int, int> pii;

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

int V, E;
int cnt, ans;
vector<Node*> nodes;
vector<Node*> pNodes;
Node* src;
Node* sink;

void init(){
    nodes = vector<Node*>(V + 1, 0);
    pNodes = vector<Node*>(V + 1, 0);
    nodes[1] = new Node(1);
    nodes[V] = new Node(V);
    src = new Node(0); sink = new Node(V + 1);
    Edge* e = new Edge(src, pNodes[1], 2, 0);
    Edge* re = new Edge(pNodes[1], src, 0, 0);
    e->revEdge = re;
    re->revEdge = e;
    src->adj.push_back(e);
    pNodes[1]->adj.push_back(re);
    Edge* se = new Edge(nodes[V], sink, 2, 0);
    Edge* rse = new Edge(sink, nodes[V], 0, 0);
    se->revEdge = rse;
    rse->revEdge = se;
    nodes[V]->adj.push_back(se);
    sink->adj.push_back(rse);
    for(int i = 1; i <= V; i++){
        nodes[i] = new Node(i);
        pNodes[i] = new Node(i);
        Edge* edge = new Edge(nodes[i], pNodes[i], 1, 0);
        Edge* rEdge = new Edge(pNodes[i], nodes[i], 0, 0);
        nodes[i]->adj.push_back(edge);
        pNodes[i]->adj.push_back(rEdge);
    }
    return;
}

int mcmf(){
    cnt = 0;
    ans = 0;
    while(true){
        src->inQ = sink->inQ = false;
        src->dist = sink->dist = MAX;
        src->parent = sink->parent = nullptr;
        src->visited = sink->visited = 0;
        for(int i = 1; i <= V; i++){
            pNodes[i] = nodes[i]->inQ = false;
            pNodes[i] = nodes[i]->dist = MAX;
            pNodes[i] = nodes[i]->parent = nullptr;
            pNodes[i] = nodes[i]->visited = 0;
            pNodes[i] = nodes[i]->parentEdge = nullptr;
        }
        queue<Node*> q;
        src->dist = 0;
        src->inQ = true;
        q.push(src);
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
        if(!sink->parent){
            break;
        }
        int ret = MAX;
        for(Node* i = sink; i != src; i = i->parent){
            Edge* e = i->parentEdge;
            ret = min(ret, e->cap - e->flow);
        }
        for(Node* i = sink; i != src; i = i->parent){
            Edge* e = i->parentEdge;
            Edge* re = e->revEdge;
            ans += ret * e->cost;
            e->flow += ret;
            re->flow -= ret;
        }
        cnt++;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> V >> E){
        init();
        for(int i = 0; i < E; i++){
            int start, end, cost;
            cin >> start >> end >> cost;
            Edge* e = new Edge(nodes[start], pNodes[end], 1, cost);
            Edge* re = new Edge(pNodes[end], nodes[start], 0, -cost);
            nodes[start]->adj.push_back(e);
            pNodes[end]->adj.push_back(re);
        }

    }
    return 0;
}