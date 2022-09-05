#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

struct Node{
    int num;
    Node* parent;
    vector<Node*> child;
    int start, end;
    Node(int num){
        this->start = this->end = 0;
        this->num = num;
    }
};
struct Tree{
    int idx;
    int lazy;
    int val;
    Tree(int idx){
        this->idx = idx;
    }
}

typedef long long ll;
typedef pair<int, int> pii;


int N, M;
vector<Node*> sales;
vector<Tree*> tree;
int cnt;

void dfs(int node){
    sales[node]->start = cnt;
    for(auto i : sales[node]->child){
        cnt++;
        dfs(i->num);
    }
    sales[node]->end = cnt;
    return;
}

int update(int start, int end, int left, int right, int idx, int diff){
    if(tree[idx]->lazy != 0){
        tree[idx]->val += (end - start + 1) * tree[idx]->lazy;
        if(start != end){
            tree[idx << 1]->lazy += tree[idx]->lazy;
            tree[(idx << 1) + 1]->lazy += tree[idx]->lazy;
        }
        tree[idx]->lazy = 0;
    }
    if(start > right || end < left){
        return 0;
    }
    if(start >= left && end <= right){
        tree[idx]->val += (end - start + 1) * diff;
        if(start != end){
            tree[idx << 1]->lazy += diff;
            tree[(idx << 1) + 1]->lazy += diff;
        }
        return 0;
    }
    int mid = (start + end) / 2;
    update(start, mid, left, right, (idx << 1) , diff);
    update(mid + 1, end, left, right, (idx << 1) + 1, diff);
    tree[idx]->val = tree[idx << 1]->val + tree[(idx << 1) + 1]->val;
    return 0;
}

int query(int start, int end, int point, int idx){
    if(tree[idx]->lazy != 0){
        tree[idx]
    }
    if(point < start || point > end){
        return 0;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    sales = vector<Node*>(N + 1);
    for(int i = 1; i <= N; i++){
        sales[i] = new Node(i);
    }
    for(int i = 1; i <= N; i++){
        int par;
        cin >> par;
        if(par == -1){
            continue;
        }
        sales[par]->child.push_back(sales[i]);
        sales[i]->parent = sales[par];
    }
    cnt = 1;
    dfs(1);
    int height = ceil(log2(N));
    tree = vector<Tree*>((1 << (height + 1)));
    int tN = 1;
    for(auto i : tree){
        i = new Tree(tN);
        tN++;
    }
    for(int q = 0; q < M; q++){
        int op;
        cin >> op;
        if(op == 1){
            int s, diff;
            cin >> s >> diff;
            update(1, N, sales[s]->start, sales[s]->end, 1, diff);
        }
        else if(op == 2){
            int s;
            cin >> s;
            query(1, N, s, 1);
        }
    }
    return 0;
}