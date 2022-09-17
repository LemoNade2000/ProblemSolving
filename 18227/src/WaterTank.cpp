#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

struct Node{
    int idx;
    Node* parent;
    int eulerStart;
    int eulerEnd;
    int depth;
    vector<Node*> adj;
    bool visited;
    Node(int idx){
        this->idx = idx;
        this->parent = nullptr;
        this->eulerStart = this->eulerEnd = this->depth = 0;
        bool visited = false;
    }
};

struct Tree{
    int lazy;
    int val;
    Tree(){
        this->lazy = 0;
        this->val = 0;
    }
};

int N, C, Q;
vector<Node*> city;
vector<Tree> tree;
int order;

void dfs(Node* node, int d){
    node->depth = d;
    node->visited = true;
    node->eulerStart = order;
    for(int i = 0; i < node->adj.size(); i++){
        if(node->adj[i]->visited == false){
            order++;
            dfs(node->adj[i], d + 1);
        }
    }
    node->eulerEnd = order;
    return;
}

int update(int start, int end, int left, int right, int idx, int diff){
    if(start > right || end < left){
        return 0;
    }
    else if(start >= left && end <= right){
        tree[idx].val += 1;
        return 0;
    }
    int mid = (start + end) / 2;
    update(start, mid, left, right, (idx << 1), diff);
    update(mid + 1, end, left, right, (idx << 1) + 1, diff);
    tree[idx].val = tree[idx << 1].val + tree[(idx << 1) + 1].val;
    return 0;
}

int query(int start, int end, int left, int right, int idx){
    if(start > right || end < left){
        return 0;
    }
    else if(start >= left && end <= right){
        return tree[idx].val;
    }
    int mid = (start + end) / 2;
    return query(start, mid, left, right, idx << 1) + query(mid + 1, end, left, right, (idx << 1) + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> C;
    city = vector<Node*>(N + 1);
    for(int i = 1; i <= N; i++){
        city[i] = new Node(i);
    }
    order = 1;
    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        city[u]->adj.push_back(city[v]);
        city[v]->adj.push_back(city[u]);
    }
    dfs(city[C], 1);
    int maxDepth = ceil(log2(N));
    tree = vector<Tree>(1 << (maxDepth + 1));
    cin >> Q;
    for(int q = 0; q < Q; q++){
        int op;
        cin >> op;
        if(op == 1){
            int f;
            cin >> f;
            update(1, N, city[f]->eulerStart, city[f]->eulerStart, 1, 1);
        }
        else if(op == 2){
            int f;
            cin >> f;
            ll ans = query(1, N, city[f]->eulerStart, city[f]->eulerEnd, 1);
            ans *= city[f]->depth;
            cout << ans << "\n";
        }
    }
    return 0;
}