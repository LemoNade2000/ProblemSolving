#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N, Q;
vector<int> test;
int dp[101010][100];

int dfs(int day, int failed){
    if(day == N || failed == Q){
        return 0;
    }
    if(dp[day][failed]!= 0){
        return dp[day][failed];
    }
    if(Q - failed >= test[day]){
        return dp[day][failed] = dfs(day + 1, failed) + 1;
    }
    else if(Q - failed < test[day]){
        return dp[day][failed] = max(dfs(day + 1, failed + 1) + 1, dfs(day + 1, failed));
    }
}

int solve(){
    cin >> N >> Q;
    test = vector<int>(N);
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++){
        cin >> test[i];
    }
    cout << dfs(0, 0);
    int failed = 0;
    for(int i = 0; i < N; i++){
        if(dp[i][failed] > dp[i][failed + 1]
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        solve();
    }
    return 0;
}