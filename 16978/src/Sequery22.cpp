#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007


struct sumQuery{
    int order;
    int updateNum;
    int left, right;
    ll sum;
};
struct upQuery{
    int upPos, upNum;
};
int N, M;
vector<ll> tree;
vector<ll> arr;
vector<sumQuery> sQuery;
vector<upQuery> uQuery;

ll generateTree(int start, int end, int idx){
    if(start == end){
        tree[idx] = arr[start];
        return tree[idx];
    }
    int mid = (start + end) / 2;
    return tree[idx] = generateTree(start, mid, idx * 2) + generateTree(mid + 1, end, idx * 2 + 1);
}

ll update(int start, int end, int pos, int diff, int idx){
    if(pos < start || pos > end){
        return 0;
    }
    if(start == end){
        tree[idx] += diff;
        arr[start] += diff;
        return tree[idx];
    }
    if(pos <= end && pos >= start){
        int mid = (start + end) / 2;
        tree[idx] += diff;
        update(start, mid, pos, diff, idx * 2);
        update(mid + 1, end, pos, diff, idx * 2 + 1);
    }
    return tree[idx];
}

ll getSum(int start, int end, int left, int right, int idx){
    if(left > end || right < start){
        return 0;
    }
    if(start >= left && end <= right){
        return tree[idx];
    }
    int mid = (start + end) / 2;
    return getSum(start, mid, left, right, idx * 2) + getSum(mid + 1, end, left, right, idx * 2 + 1);
}

bool compUp(sumQuery a, sumQuery b){
    if(a.updateNum < b.updateNum){
        return true;
    }
    else return false;
}

bool compOr(sumQuery a, sumQuery b){
    if(a.order < b.order){
        return true;
    }
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr = vector<ll>(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }   
    int height = ceil(log2(N));
    tree.resize((1 << (height + 1)));
    generateTree(1, N, 1);
    cin >> M;
    for(int i = 0; i < M; i++){
        int op;
        cin >> op;
        if(op == 1){
            int i, v;
            cin >> i >> v;
            uQuery.push_back({i, v});
        }
        else{
            int k, l, r;
            cin >> k >> l >> r;
            sQuery.push_back({i, k, l, r, 0});
        }
    }
    sort(sQuery.begin(), sQuery.end(), compUp);
    int up = 0;
    for(int i = 0; i < sQuery.size(); i++){
        int j = sQuery[i].updateNum;
        for(; up < j; up++){
            int i, v;
            i = uQuery[up].upPos;
            v = uQuery[up].upNum;
            update(1, N, i, v - arr[i], 1);
        }
        sQuery[i].sum = getSum(1, N, sQuery[i].left, sQuery[i].right, 1);
    }
    sort(sQuery.begin(), sQuery.end(), compOr);
    for(auto i : sQuery){
        cout << i.sum << "\n";
    }
    return 0;
}