#include <bits/stdc++.h>

using namespace std;

#define MAX 987654321

typedef long long ll;
typedef pair<int, int> pii;

int TC;

int N, M;

vector<vector<int>> pos;
vector<vector<int>> dp;
vector<int> arr;

int fillDP(int p, int order){
    if(dp[p][order] != MAX){
        return dp[p][order];
    }
    if(order >= arr.size()){
        return 0;
    }
    int left, right;
    left = -1; right = MAX;
    for(int i = 0; i < pos[arr[order]].size(); i++){
        if(pos[arr[order]][i] < p){
            left = max(left, pos[arr[order]][i]);
        }
        else if(pos[arr[order]][i] > p){
            right = min(right, pos[arr[order]][i]);
        }
    }
    int a, b;
    a = b = MAX;
    if(left != -1){
        a = abs(p - left) + fillDP(left, order + 1);
    }
    if(right != MAX){
        b = abs(right - p) + fillDP(right, order + 1);
    }
    return dp[p][order] = min(a, b);
}

int solve(){
    pos.clear();
    dp.clear();
    arr.clear();
    cin >> N;
    int temp = -1;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        if(n == temp){
            continue;
        }
        temp = n;
        arr.push_back(n);
    }
    pos.resize(2501);
    dp.resize(2501);
    for(int i = 0; i < 2501; i++){
        dp[i].resize(2501, MAX);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        int n;
        cin >> n;
        pos[n].push_back(i);
    }
    int ans = INT_MAX;
    for(int i = 0; i < pos[arr[0]].size(); i++){
        ans = min(ans, fillDP(pos[arr[0]][i], 1));
    }
    cout << ans << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}