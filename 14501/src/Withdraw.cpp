#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<pii> talks;
vector<vector<int>> dp;
int maximum;

int dfs(int day, int talk){
    if(day + talks[talk].first <= N){
        dp[day][talk] = talks[talk].second + dfs(day + talks[talk].first, talk + 1);
    } 
    dp[day][talk] = max(dfs(day + 1, talk + 1), dp[day][talk]);
    return dp[day][talk];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    dp = vector<vector<int>>(N + 1);
    for(int i = 1; i <= N; i++){
        dp[i] = vector<int>(N + 1, 0);
    }
    talks = vector<pii>(N + 1);
    maximum = 0;
    for(int i = 1; i <= N; i++){
        cin >> talks[i].first >> talks[i].second;
    }
    for(int i = 1; i <= N; i++){
        cout << dfs(0, 1);
    }
    return 0;
}

