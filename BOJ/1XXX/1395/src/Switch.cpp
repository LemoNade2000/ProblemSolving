#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

struct Node{
    int val;
    int lazy;
    Node(){
        this->lazy = 0;
        this->val = 0;
    }
};

int N, M;
vector<Node> tree;

int query(int start, int end, int left, int right, int idx){
    if(tree[idx].lazy != 0){
        if(tree[idx].lazy & 1){
            tree[idx].val = (end - start + 1) - tree[idx].val;
        }
        if(start != end){
            tree[idx << 1].lazy += tree[idx].lazy;
            tree[(idx << 1)+ 1].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }
    if(start > right || end < left){
        return 0;
    }
    else if(start >= left && end <= right){
        return tree[idx].val;
    }
    int mid = (start + end) / 2;
    int lVal = query(start, mid, left, right, idx << 1);
    int rVal = query(mid + 1, end, left, right, (idx << 1) + 1);
    return lVal + rVal;
}

int update(int start, int end, int left, int right, int idx){
    if(tree[idx].lazy != 0){
        if(tree[idx].lazy & 1){
            tree[idx].val = (end - start + 1) - tree[idx].val;
        }
        if(start != end){
             tree[idx << 1].lazy += tree[idx].lazy;
             tree[(idx << 1) + 1].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }
    if(start > right || end < left){
        return tree[idx].val;
    }
    else if(start >= left && end <= right){
        tree[idx].val = (end - start + 1) - tree[idx].val;
        if(start != end){
            tree[idx << 1].lazy += 1;
            tree[(idx << 1) + 1].lazy += 1;
        }
        return tree[idx].val;
    }
    int mid = (start + end) / 2;
    return tree[idx].val = update(start, mid, left, right, idx << 1) + update(mid + 1, end, left, right, (idx << 1) + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int height = ceil(log2(N));
    tree = vector<Node>(1 << (1 + height));
    for(int i = 0; i < M; i++){
        int op, s, t;
        cin >> op >> s >> t;
        if(op == 0){
            update(1, N, s, t, 1);
        }
        else{
            cout << query(1, N, s, t, 1) << "\n";
        }
        // for(auto i : tree){
        //     cout << i.val << " ";
        // }
        // cout << "\n";
    }
    return 0;
}