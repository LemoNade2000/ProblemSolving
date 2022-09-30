#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

struct Node{
    vector<int> adj;
    int start; int end;
    int idx;
    int state;
    Node(){
        this->start = 0;
        this->end = 0;
        this->idx = 0;
        this->state;
    }
};

struct Tree{
    int lazy;
    int val;
};

int order;
int N, Q;
vector<Node> nodes;
vector<int> tree;

int dfs(int node){
    nodes[node].start = order;
    for(int i = 0; i < nodes[node].adj.size(); i++){
        int next = nodes[node].adj[i];
        if(nodes[next].start == 0){
            order++;
            dfs(next);
        }
    }
    nodes[node].end = order;
    return 0;
}

int update(int start, int end, int left, int right, int idx, int pos){
    if(right < start || left > end){
        return tree[idx];
    }
    if(start == end){
        if(nodes[pos].state == 0){
            nodes[pos].state = 1;
            return 
        }
        else{
            nodes[pos].state = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    int height = ceil(log2(N));
    tree = vector<int>(1 << (1 + height), -1);
    nodes = vector<Node>(N + 1);
    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        nodes[u].adj.push_back(v);
        nodes[v].adj.push_back(u);
    }
    order = 1;
    dfs(1);
    for(int i = 0; i < Q; i++){
        int op;
        cin >> op;
        if(op == 0){
            int pos;
            cin >> pos;
            if(nodes[pos].state == 0){
                updateWhite(1, N, nodes[pos].start, nodes[pos].end, 1, pos);
            }
            else{
                updateBlack(1, N, nodes[pos].start)
            }
        }
        else if(op == 1){

        }
    }
    return 0;
}