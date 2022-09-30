#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, M;
vector<int> arr;
vector<vector<int>*> tree;

vector<int>* generateTree(int start, int end, int idx){
    if(start == end){
        tree[idx] = new vector<int>;
        tree[idx]->push_back(arr[start]);
        return tree[idx];
    }
    tree[idx] = new vector<int>(end - start + 1);
    int mid = (start + end) / 2;
    vector<int>* left = generateTree(start, mid, idx * 2);
    vector<int>* right = generateTree(mid + 1, end, idx * 2 + 1);
    merge(left->begin(), left->end(), right->begin(), right->end(), tree[idx]->begin());
    return tree[idx];
}

int getLarge(int left, int right, int k, int start, int end, int idx){
    if(left > end || right < start){
        return 0;
    }
    if(start >= left && end <= right){
        auto it = lower_bound(tree[idx]->begin(), tree[idx]->end(), k + 1);
        return tree[idx]->end() - it;
    }
    int mid = (start + end) / 2;
    return getLarge(left, right, k, start, mid, idx * 2) + getLarge(left, right, k, mid + 1, end, idx * 2 + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int height = ceil(log2(N));
    tree = vector<vector<int>*>(1 << (height + 1));
    arr = vector<int>(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    generateTree(1, N, 1);
    cin >> M;
    int last = 0;
    for(int i = 0; i < M; i++){
        int a, b, c;
        int left, right, k;
        cin >> a >> b >> c;
        left = a ^ last;
        right = b ^ last;
        k = c ^ last;
        last = getLarge(left, right, k, 1, N, 1);
        cout << last << "\n";
    }
    return 0;
}