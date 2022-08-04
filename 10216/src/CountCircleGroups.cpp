#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;

struct Node{
    int num;
    int x, y;
    int radius;
    vector<Node*> adj;
    bool visited;
    Node(int num){
        this->num = num;
        visited = false;
        adj = vector<Node*>(0);
    }
};

int N;
vector<Node*> bases;

bool overlap(Node* a, Node* b){
    int dist = abs(a->x - b->x) * abs(a->x - b->x) + abs(a->y - b->y) * abs(a->y - b->y);
    int radSum = a->radius + b->radius;
    radSum = radSum * radSum;
    if(dist <= radSum){
        return true;
    }
    else{
        return false;
    }
}

int dfs(Node* a){
    priority_queue<int> pq;
    pq.push(a->num);
    while(!pq.empty()){
        Node* currNode = bases[pq.top()];
        pq.pop();
        if(currNode->visited == true){
            continue;
        }
        currNode->visited = true;
        for(auto i : currNode->adj){
            if(i->visited == false){
                pq.push(i->num);
            }
        }
    }
    return 0;
}

int solve(){
    cin >> N;
    bases = vector<Node*>(N);
    for(int i = 0; i < N; i++){
        Node* node = new Node(i);
        int x, y, r;
        cin >> x >> y >> r;
        node->x = x; node->y = y;
        node->radius = r;
        bases[i] = node;
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(overlap(bases[i], bases[j])){
                bases[i]->adj.push_back(bases[j]);
                bases[j]->adj.push_back(bases[i]);
            }
        }
    }
    int cnt = 0;
    // for(auto i : bases){
    //     for(auto j : i->adj){
    //         cout << j->num << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 0; i < N; i++){
        if(bases[i]->visited == false){
            dfs(bases[i]);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        solve();
    }
    return 0;
}