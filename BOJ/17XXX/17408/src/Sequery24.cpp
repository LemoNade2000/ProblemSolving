#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, M;
vector<int> arr;
vector<pii> tree;

pii generateTree(int start, int end, int idx){
    if(start == end){
        tree[idx] = {0, arr[start]};
        return {0, arr[start]};
    }
    int mid = (start + end) / 2;
    pii left = generateTree(start, mid, idx << 1);
    pii right = generateTree(mid + 1, end, (idx << 1) + 1);
    priority_queue<int> pq;
    pq.push(left.first); pq.push(left.second); pq.push(right.first); pq.push(right.second);
    pii ret;
    ret.first = pq.top();
    pq.pop();
    ret.second = pq.top();
    tree[idx] = ret;
    return ret;
}

pii update(int start, int end, int idx, int pos, int val){
    if(start == pos && end == pos){
        tree[idx] = {0, val};
        return {0, val};
    }
    if(pos < start || pos > end){
        return tree[idx];
    }
    int mid = (start + end) / 2;
    pii left = update(start, mid, idx << 1, pos, val);
    pii right = update(mid + 1, end, (idx << 1) + 1, pos, val);
    priority_queue<int> pq;
    pq.push(left.first); pq.push(left.second); pq.push(right.first); pq.push(right.second);
    pii ret;
    ret.first = pq.top();
    pq.pop();
    ret.second = pq.top();
    tree[idx] = ret;
    return ret;
}

pii query(int start, int end, int left, int right, int idx){
    if(left > end || right < start){
        return {0, 0};
    }
    if(start >= left && end <= right){
        return tree[idx];
    }
    int mid = (start + end) / 2;
    pii leftRet = query(start, mid, left, right, idx << 1);
    pii rightRet = query(mid + 1, end, left, right, (idx << 1) + 1);
    priority_queue<int> pq;
    pq.push(leftRet.first); pq.push(leftRet.second); pq.push(rightRet.first); pq.push(rightRet.second);
    pii ret;
    ret.first = pq.top();
    pq.pop();
    ret.second = pq.top();
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int height = ceil(log2(N));
    tree = vector<pii>((1 << (height + 1)));
    arr = vector<int>(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    generateTree(1, N, 1);
    cin >> M;
    for(int tc = 0; tc < M; tc++){
        int op;
        cin >> op;
        if(op == 1){
            int i, v;
            cin >> i >> v;
            update(1, N, 1, i, v);
        }
        if(op == 2){
            int l, r;
            cin >> l >> r;
            pii result = query(1, N, l, r, 1);
            cout << result.first + result.second << "\n";
        }
    }
    return 0;
}