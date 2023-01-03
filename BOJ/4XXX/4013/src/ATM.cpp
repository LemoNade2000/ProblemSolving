#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Node{
    int idx;
    bool visited;
    bool finished;
    int sccIdx;
    vector<int> adj;
    int parent;
    int money;
    bool isRestaurant;
    int counter;
    int inDegree;
    int maxCash;
    set<int> duplicates;
    Node(int idx){
        this->idx = idx;
        visited = false;
        finished = false;
        sccIdx = -1;
        isRestaurant = false;
        inDegree = 0;
        maxCash = 0;
        money = 0;
    }
};

int N, M;
vector<Node*> nodes;
vector<Node*> sccNodes;
vector<vector<Node*>> scc;
stack<Node*> s;
int S, P;
int sccCnt = 0;
int vertCnt = 0;
int maximum = 0;

int dfs(int node){
    Node* currNode = nodes[node];
    s.push(currNode);
    currNode->visited = true;
    currNode->counter = vertCnt++;
    int ret = currNode->counter;
    for(int i = 0; i < currNode->adj.size(); i++){
        int nextNode = currNode->adj[i];
        if(nodes[nextNode]->visited == false){
            ret = min(ret, dfs(nextNode));
        }
        else if(nodes[nextNode]->finished == false){
            ret = min(ret, nodes[nextNode]->counter);
        }
    }
    if(ret == currNode->counter){
        vector<Node*> v;
        while(true){
            Node* n = s.top();
            s.pop();
            v.push_back(n);
            n->finished = true;
            n->sccIdx = sccCnt;
            if(n->idx == node){
                break;
            }
        }
        scc.push_back(v);
        sccCnt++;
    }
    return ret;
}


void constructSCC(){
    dfs(S);
    sccNodes = vector<Node*>(scc.size());
    for(int i = 0; i < sccNodes.size(); i++){
        sccNodes[i] = new Node(i);
        for(auto node : scc[i]){
            sccNodes[i]->money += node->money;
            if(node->isRestaurant){
                sccNodes[i]->isRestaurant = true;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        if(nodes[i]->sccIdx == -1){
            continue;
        }
        int currSCC = nodes[i]->sccIdx;
        for(int j = 0; j < nodes[i]->adj.size(); j++){
            int nextNode = nodes[i]->adj[j];
            int nextSCC = nodes[nextNode]->sccIdx;
            // if(sccNodes[currSCC]->duplicates.count(nextSCC) > 0){
            //     continue;
            // }
            if(currSCC != nextSCC){
                sccNodes[currSCC]->adj.push_back(nextSCC);
                sccNodes[nextSCC]->inDegree += 1;
                sccNodes[currSCC]->duplicates.insert(nextSCC);
            }
        }
    }
    return;
}

void solve(){
    queue<Node*> q;
    q.push(sccNodes[nodes[S]->sccIdx]);
    sccNodes[nodes[S]->sccIdx]->maxCash = sccNodes[nodes[S]->sccIdx]->money;
    while(!q.empty()){
        Node* currNode = q.front();
        q.pop();
        if(currNode->isRestaurant){
            maximum = max(maximum, currNode->maxCash);
        }
        for(int i = 0; i < currNode->adj.size(); i++){
            int nextNodeI = currNode->adj[i];
            Node* nextNode = sccNodes[nextNodeI];
            nextNode->maxCash = max(nextNode->maxCash, currNode->maxCash + nextNode->money);
            nextNode->inDegree--;
            if(nextNode->inDegree == 0){
                q.push(nextNode);
            } 
        }
    }
    cout << maximum;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    nodes = vector<Node*>(N + 1);
    for(int i = 1; i <= N; i++){
        Node* n = new Node(i);
        nodes[i] = n;
    }
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        nodes[a]->adj.push_back(b);
    }
    for(int i = 1; i <= N; i++){
        int p;
        cin >> p;
        nodes[i]->money = p;
    }
    cin >> S >> P;
    for(int i = 0; i < P; i++){
        int a;
        cin >> a;
        nodes[a]->isRestaurant = true;
    }
    sccCnt = 0;
    constructSCC();
    solve();
    return 0;
}