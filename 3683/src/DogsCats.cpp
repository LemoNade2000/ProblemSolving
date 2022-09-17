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
    Edge(Node* start, Node* end, int cap){
        this->start = start;
        this->end = end;
        this->cap = cap;
        this->flow = this->revFlow = 0;
    }
};

struct Node{
    int idx;
    int level;
    vector<Edge*> adj;
    int lastEdge;
    bool inQ;
    int dist;
    Node* parent;
    Edge* parentEdge;
    int visited;
    char c;
    Node(int idx){
        this->level = -1;   
        this->lastEdge = 0;
        this->inQ = false;
        this->dist = 0;
        this->parent = NULL;
        this->visited = 0;
        this->parentEdge = NULL;
    }
};

int C, D, V;
int cnt, ans;
Node* root;
Node* dest;
vector<Node*> cats;
vector<Node*> dogs;

bool bfs(){
    root->level = -1; dest->level = -1;
    for(auto i : dogs){
        i->level = -1;
    }
    for(auto i : cats){
        i->level = -1;
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
                next->revEdge->flow -= ret;
                return ret;
            }
        }
    }
    curr->lastEdge = curr->adj.size();
    return 0;
}

int dinic(){
    ans = 0;
    while(bfs()){
        root->lastEdge = 0;
        dest->lastEdge = 0;
        for(auto i : dogs){
            i->lastEdge = 0;
        }
        for(auto i : cats){
            i->lastEdge = 0;
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

int solve(){
    cats.clear();
    dogs.clear();
    cin >> C >> D >> V;
    vector<pii> catList;
    vector<pii> dogList;
    root = new Node(0);
    dest = new Node(V + 1);
    for(int i = 0; i < V; i++){
        string s1, s2;
        cin >> s1 >> s2;
        if(s1[0] == 'C'){
            Node* node = new Node(cats.size());
            cats.push_back(node);
            Edge* e = new Edge(root, node, 1);
            Edge* re = new Edge(node, root, 0);
            e->revEdge = re; re->revEdge = e;
            root->adj.push_back(e); node->adj.push_back(re);
            s1.erase(0, 1); s2.erase(0, 1);
            pii currVote = {stoi(s1), stoi(s2)};
            catList.push_back(currVote);
            for(int j = 0; j < dogList.size(); j++){
                if(currVote.first == dogList[j].second || currVote.second == dogList[j].first){
                    Edge* se = new Edge(node, dogs[j], 1);
                    Edge* rse = new Edge(dogs[j], node, 0);
                    se->revEdge = rse; rse->revEdge = se;
                    node->adj.push_back(se);
                    dogs[j]->adj.push_back(rse);
                }
            }
        }
        else{
            Node* node = new Node(dogs.size());
            dogs.push_back(node);
            Edge* e = new Edge(node, dest, 1);
            Edge* re = new Edge(dest, node, 0);
            e->revEdge = re; re->revEdge = e;
            node->adj.push_back(e); dest->adj.push_back(re);
            s1.erase(0, 1); s2.erase(0, 1);
            pii currVote = {stoi(s1), stoi(s2)};
            dogList.push_back(currVote);
            for(int j = 0; j < catList.size(); j++){
                if(currVote.first == catList[j].second || currVote.second == catList[j].first){
                    Edge* se = new Edge(cats[j], node, 1);
                    Edge* rse = new Edge(node, cats[j], 0);
                    se->revEdge = rse; rse->revEdge = se;
                    node->adj.push_back(rse);
                    cats[j]->adj.push_back(se);
                }
            }
        }
    }
    cout << V - dinic() << "\n";
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