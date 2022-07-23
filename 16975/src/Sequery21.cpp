#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAX 1000001

int N, M, K;

struct Node{
    ll val;
    ll lazy;
};

vector<Node> tree;
vector<ll> arr;

ll generateTree(int start, int end, int idx){
    if(start == end){
        tree[idx].lazy = 0;
        tree[idx].val = arr[start];
        return tree[idx].val;
    }
    int mid = (start + end) / 2;
    ll left = generateTree(start, mid, idx * 2);
    ll right = generateTree(mid + 1, end, idx * 2 + 1);
    tree[idx].val = left + right;
    tree[idx].lazy = 0;
    return tree[idx].val;
}

int update(int left, int right, int start, int end, int idx, ll diff){
    if(tree[idx].lazy != 0){
        tree[idx].val = tree[idx].val + (end - start + 1) * tree[idx].lazy;
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
        tree[idx].val = tree[idx].val + (end - start + 1) * diff;
        if(start != end){
            tree[idx * 2].lazy += diff;
            tree[idx * 2 + 1].lazy += diff;
        }
        return 0;
    }
    int mid = (start + end) / 2;
    update(left, right, start, mid, idx * 2, diff);
    update(left, right, mid + 1, end, idx * 2 + 1, diff);
    tree[idx].val = tree[idx * 2].val + tree[idx * 2 + 1].val;
    return 0;
}

ll query(int left, int right, int start, int end, int idx){
    if(tree[idx].lazy != 0){
        tree[idx].val = tree[idx].val + (end - start + 1) * tree[idx].lazy;
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
    ll lVal = query(left, right, start, mid, idx * 2);
    ll rVal = query(left, right, mid + 1, end, idx * 2 + 1);
    return lVal + rVal;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int depth = ceil(log2(MAX));
    tree.resize(1 << (depth + 1));
    arr.resize(N + 1, 0);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    generateTree(1, N, 1);
    cin >> M;
    for(int i = 0; i < M; i++){
        int op;
        cin >> op;
        if(op == 1){
            int b, c;
            ll d;
            cin >> b >> c >> d;
            update(b, c, 1, N, 1, d);
        }
        else{
            int b, c;
            cin >> b;
            cout << query(b, b, 1, N, 1) << "\n";
        }
    }
    return 0;
}