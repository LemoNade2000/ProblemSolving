#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Node{
    ll val;
    ll lazy;
};

int N, Q, height;
vector<ll> arr;
vector<ll> diff;
vector<Node> tree;

ll generateTree(int start, int end, int idx){
    if(start == end){
        tree[idx].lazy = 0;
        tree[idx].val = diff[start];
        return tree[idx].val;
    }
    int mid = (start + end) / 2;
    ll left = generateTree(start, mid, idx * 2);
    ll right = generateTree(mid + 1, end, idx * 2 + 1);
    tree[idx].lazy = 0;
    tree[idx].val = left + right;
    return tree[idx].val;
}

ll update(int start, int end, int left, int right, int idx, ll diff){
    if(tree[idx].lazy != 0){
        tree[idx].val += tree[idx].lazy * (end - start + 1);
        if(start != end){
            tree[idx * 2].lazy += tree[idx].lazy;
            tree[idx * 2 + 1].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }
    if(start > right || end < left){
        return 0;
    }
    else if(start >= left && end <= right){
        tree[idx].val = tree[idx].val + diff * (end - start + 1);
        if(start != end){
            tree[idx * 2].lazy += diff;
            tree[idx * 2 + 1].lazy += diff;
        }
        return 0;
    }
    int mid = (start + end) / 2;
    update(start, mid, left, right, idx * 2, diff);
    update(mid + 1, end, left, right, idx * 2 + 1, diff);
    tree[idx].val = tree[idx * 2].val + tree[idx * 2 + 1].val;
    return 0;
}

ll query(int start, int end, int left, int right, int idx){
    if(tree[idx].lazy != 0){
        tree[idx].val += (end - start + 1) * tree[idx].lazy;
        if(start != end){
            tree[idx * 2].lazy += tree[idx].lazy;
            tree[idx * 2 + 1].lazy += tree[idx].lazy;
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
    ll lVal = query(start, mid, left, right, idx * 2);
    ll rVal = query(mid + 1, end, left, right, idx * 2 + 1);
    return lVal + rVal;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr = vector<ll>(N + 1, 0);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    height = ceil(log2(N));
    tree.resize(1 << (height + 1));
    diff = vector<ll>(N + 1, 0);
    for(int i = 1; i <= N; i++){
        diff[i] = arr[i] - arr[i - 1];
    }
    generateTree(1, N, 1);
    cin >> Q;
    for(int q = 0; q < Q; q++){
        int op;
        cin >> op;
        if(op == 1){
            int L, R;
            cin >> L >> R;
            update(1, N, L, R, 1, 1);
            update(1, N, R + 1, R + 1, 1, -(R - L + 1));
        }
        else if(op == 2){
            int X;
            cin >> X;
            cout << query(1, N, 1, X, 1) << "\n";
        }
    }
    return 0;
}