#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

class Node;
class Edge;

class Node{
    public:
    int idx;
    vector<Edge*> adj;
    vector<Edge*> revAdj;
    bool visited;
    bool finished;
    bool red;
    int sccNum;
    int boolVal;
    Node(int idx, bool red){
        this->idx = idx;
        this->visited = false;
        this->finished = false;
        this->sccNum = -1;
        this->boolVal = -1;
        this->red = red;
    }
};

class Edge{
    public:
    Node* start;
    Node* end;
    Node* revEdge;
    Edge(Node* start, Node* end){
        this->start = start;
        this->end = end;
    }
};

int K, N;
vector<vector<Node*>> lights;
int sccCnt;
stack<Node*> s;
vector<vector<Node*>> SCC;

int dfs(Node* node){
    node->visited = true;
    for(auto nextEdge : node->adj){
        Node* nextNode = nextEdge->end;
        if(!nextNode->visited){
            dfs(nextNode);
        }
    }
    s.push(node);
    return 0;
}

int revDfs(Node* node){
    node->finished = true;
    node->sccNum = sccCnt;
    SCC[sccCnt].push_back(node);
    for(auto nextEdge : node->revAdj){
        Node* nextNode = nextEdge->end;
        if(!nextNode->finished){
            revDfs(nextNode);
        }
    }
    return 0;
}

bool compSCC(Node* a, Node* b){
    if(a->sccNum < b->sccNum){
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> N;
    lights = vector<vector<Node*>>(2);
    SCC = vector<vector<Node*>>(2 * K + 1);
    lights[0] = vector<Node*>(K);
    lights[1] = vector<Node*>(K);
    for(int i = 0; i < K; i++){
        lights[0][i] = new Node(i, false);
        lights[1][i] = new Node(i, true);
    }
    for(int i = 0; i < N; i++){
        int idx[3]; char c[3]; bool val[3];
        for(int j = 0; j < 3; j++){
            cin >> idx[j] >> c[j];
            if(c[j] == 'R'){
                val[j] = 1;
            }
            else{
                val[j] = 0;
            }
            idx[j]--;
        }
        for(int j = 0; j < 3; j++){
            int k = (j + 1) % 3;
            Edge* e = new Edge(lights[!val[j]][idx[j]], lights[val[k]][idx[k]]);
            lights[!val[j]][idx[j]]->adj.push_back(e);
            Edge* re = new Edge(lights[!val[k]][idx[k]], lights[val[j]][idx[j]]);
            lights[!val[k]][idx[k]]->adj.push_back(re);
            Edge * se = new Edge(lights[val[k]][idx[k]], lights[!val[j]][idx[j]]);
            lights[val[k]][idx[k]]->revAdj.push_back(se);
            Edge* rse = new Edge(lights[val[j]][idx[j]], lights[!val[k]][idx[k]]);
            lights[val[j]][idx[j]]->revAdj.push_back(rse);
        }
    }
    sccCnt = 0;
    vector<Node*> integrated;
    for(int i = 0; i < K; i++){
        integrated.push_back(lights[0][i]);
        integrated.push_back(lights[1][i]);
    }
    for(auto node : integrated){
        if(!node->visited){
            dfs(node);
        }
    }
    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        if(!node->finished){
            revDfs(node);
            sccCnt++;
        }
        // cout << sccCnt;
    }
    // for(auto i : SCC){
    //     for(auto j : i){
    //         cout << j->idx << " " << j->red << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 0; i < K; i++){
        if(lights[0][i]->sccNum == lights[1][i]->sccNum){
            cout << "-1";
            return 0;
        }
    }
    sort(integrated.begin(), integrated.end(), compSCC);
    for(auto node : integrated){
        // cout << node->sccNum << " ";
        if(lights[1][node->idx]->boolVal == -1){
            if(!node->red){
                lights[1][node->idx]->boolVal = 1;
            }
            else lights[1][node->idx]->boolVal = 0;
        }
    }
    for(auto node : lights[1]){
        if(node->boolVal == 0){
            cout << "B";
        }
        else cout << "R";
    }
    return 0;
}