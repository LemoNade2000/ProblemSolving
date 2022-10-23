# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int N;
vector<int> firstTest;
vector<int> secondTest;
vector<int> arr;
vector<int> firstPos;
vector<int> secondPos;

int queryMin(int start, int end, int left, int right, int idx, vector<int> &tree){
    if(start > right || end < left){
        return INT_MAX;
    }
    else if(start >= left && end <= right){
        return tree[idx];
    }
    int mid = (start + end) / 2;
    return min(queryMin(start, mid, left, right, idx << 1, tree), queryMin(mid + 1, end, left, right, (idx << 1) + 1, tree));
}

int update(int start, int end, int pos, int val, int idx, vector<int> &tree){
    if(start > pos || end < pos){
        return tree[idx];
    }
    else if(start == pos && end == pos){
        return tree[idx] = min(tree[idx], val);
    }
    int mid = (start + end) / 2;
    return tree[idx] = min(update(start, mid, pos, val, idx << 1, tree), update(mid + 1, end, pos, val, (idx << 1) + 1, tree));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int height = ceil(log2(N)) + 1;
    firstTest = vector<int>(1 << height, INT_MAX);
    arr = vector<int>(N + 1);
    firstPos = vector<int>(N + 1);
    secondPos = vector<int>(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        firstPos[arr[i]] = i;
    }
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        secondPos[arr[i]] = i;
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        if(queryMin(1, N, 1, firstPos[arr[i]], 1, firstTest) > secondPos[arr[i]]){
            ans++;
        }
        update(1, N, firstPos[arr[i]], secondPos[arr[i]], 1, firstTest);
    }
    cout << ans << "\n";
    return 0;
}