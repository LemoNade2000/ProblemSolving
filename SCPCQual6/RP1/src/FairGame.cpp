#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;
int N;
vector<int> A, B;

int solve(){
    cin >> N;
    A.resize(N, 0);
    B.resize(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll dp[N][4];
    dp[0][0] = abs(A[0] - B[0]);
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 0;
    for(int i = 1; i < N; i++){
        dp[i][0] = dp[i - 1][0] + abs(A[i] - B[i]);
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + abs(A[i] - B[i - 1]));
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][2] + abs(A[i - 1] - B[i]));
        dp[i][3] = min({dp[i][1], dp[i][2], dp[i - 1][3] + abs(A[i] - B[i])});
    }
    cout << min(dp[N - 1][0], dp[N - 1][3]) << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        cout << "Case #" << tc << "\n";
        solve();
    }
    return 0;
}