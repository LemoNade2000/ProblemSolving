#include <bits/stdc++.h>

using namespace std;

#define MAX 200002
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int N, M;

int generateTree(int start, int end, int idx, vector<int> &tree, vector<int> &arr){
    if(start == end){
        if(arr[start] != 0){
            return tree[idx] = 1;
        }
        else{
            return tree[idx] = 0;
        }
    }
    int mid = (start + end) / 2;
    int ans = 0;
    ans += generateTree(start, mid, idx * 2, tree, arr);
    ans += generateTree(mid + 1, end, idx * 2 + 1, tree, arr);
    return tree[idx] = ans;
}

int getSum(int start, int end, int left, int right, int idx, vector<int> &tree){
    if(start > right || end < left){
        return 0;
    }
    else if(start >= left && end <= right){
        return tree[idx];
    }
    int mid = (start + end) / 2;
    return getSum(start, mid, left, right, idx * 2, tree) + getSum(mid + 1, end, left, right, idx * 2 + 1, tree);
}

int update(int start, int end, int diff, int updatePos, int idx, vector<int> &tree){
    if(updatePos > end || updatePos < start){
        return 0;
    }
    if(start == end){
        return tree[idx] += diff;
    }
    tree[idx] += diff;
    int mid = (start + end) / 2;
    update(start, mid, diff, updatePos, idx * 2, tree);
    update(mid + 1, end, diff, updatePos, idx * 2 + 1, tree);
    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    int depth = ceil(log2(MAX));
    for(int tc = 0; tc < TC; tc++){
        cin >> N >> M;
        vector<int> arr;
        arr.resize(N + M + 1);
        int pos[N + 1];
        vector<int> tree;
        for(int i = 1; i <= N; i++){
            arr[M + i] = i;
            pos[i] = M + i; 
        }
        tree.resize(1 << (depth + 1));
        generateTree(1, N + M, 1, tree, arr);
        for(int i = M; i >= 1; i--){
            int movie;
            cin >> movie;
            int currPos = pos[movie];
            pos[movie] = i;
            arr[currPos] = i;
            arr[i] = movie;
            cout << getSum(1, N + M, 1, currPos - 1, 1, tree) << " ";
            update(1, N + M, -1, currPos, 1, tree);
            update(1, N + M, 1, i, 1, tree);
        }
        cout << "\n";
    }
    return 0;
}
