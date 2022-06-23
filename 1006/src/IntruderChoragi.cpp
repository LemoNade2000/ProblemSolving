#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAX 987654321

void fill(vector<int> dp[3], int N, int W, vector<int> onetagon[2]){
    for(int i = 2; i <= N; i++){
        int vertical, upper, lower;
        vertical = upper = lower = 2;
        if(onetagon[0][i - 1] + onetagon[1][i - 1] <= W){
            vertical = 1;
        }
        if(onetagon[0][i - 2] + onetagon[0][i - 1] <= W){
            lower = 1;
        }
        if(onetagon[1][i - 2] + onetagon[1][i - 1] <= W){
            upper = 1;
        }
        dp[i][0] = min({dp[i - 2][0] + upper + lower, dp[i - 1][0] + vertical, dp[i - 1][1] + upper + 1, dp[i - 1][2] + lower + 1});
        dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][2] + lower);
        dp[i][2] = min(dp[i - 1][0] + 1, dp[i - 1][1] + upper);
    }
    return;
}

int solve(){
    int ans = INT_MAX;
    int N, W;
    cin >> N >> W;
    vector<int> onetagon[2];
    if(N == 1){
        int n1, n2;
        cin >> n1 >> n2;
        if(n1 + n2 <= W){
            cout << "1\n";
            return 0;
        }
        else{
            cout << "2\n";
            return 0;
        }
    }
    vector<int> dp[N + 1];
    for(int i = 0; i < N + 1; i++){
        dp[i].resize(3, 0);
    }
    int fnum;
    cin >> fnum;
    onetagon[0].push_back(fnum);
    for(int i = 1; i < N; i++){
        int num;
        cin >> num;
        onetagon[0].push_back(num);
    }
    onetagon[0].push_back(fnum);
    cin >> fnum;
    onetagon[1].push_back(fnum);
    for(int i = 1; i < N; i++){
        int num;
        cin >> num;
        onetagon[1].push_back(num);
    }
    onetagon[1].push_back(fnum);
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    int first[2] = {onetagon[0][0], onetagon[1][0]};
    // case 1 : both outer and inner connected
    if(onetagon[0][N] + onetagon[0][N - 1] <= W && onetagon[1][N] + onetagon[1][N - 1] <= W){
        dp[1][0] = 2; dp[1][1] = 1; dp[1][2] = 1;
        onetagon[0][0] = onetagon[1][0] = MAX;
       fill(dp, N, W, onetagon);
        ans = min(ans, dp[N - 1][0]);
        onetagon[0][0] = first[0];
        onetagon[1][0] = first[1];
    }

    // case 2 : only outer connected
    if(onetagon[1][N] + onetagon[1][N - 1] <= W){
        dp[1][0] = 2; dp[1][1] = 1; dp[1][2] = 1;
        onetagon[1][0] = MAX;
        fill(dp, N, W, onetagon);
        ans = min(ans, dp[N][1]);
        onetagon[1][0] = first[1];
    }
    // case 3 : only inner connected
    if(onetagon[0][N] + onetagon[0][N - 1] <= W){
        dp[1][0] = 2; dp[1][1] = 1; dp[1][2] = 1;
        onetagon[0][0] = MAX;
        fill(dp, N, W, onetagon);
        ans = min(ans, dp[N][2]);
        onetagon[0][0] = first[0];
    }

    // case 4 : both outer and inner not connected
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    dp[1][0] = 2; dp[1][1] = 1; dp[1][2] = 1;
    if(onetagon[0][0] + onetagon[1][0] <= W) dp[1][0] = 1;
    fill(dp, N, W, onetagon);
    ans = min(ans, dp[N][0]);
    cout << ans << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        solve();
    }
}