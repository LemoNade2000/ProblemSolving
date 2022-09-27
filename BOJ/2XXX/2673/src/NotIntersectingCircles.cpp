#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N;
vector<vector<int>> strings;
vector<vector<int>> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    strings = vector<vector<int>>(101);
    dp = vector<vector<int>>(101);
    for(int i = 0; i < 101; i++){
        strings[i] = vector<int>(1, -1);
        dp[i] = vector<int>(101, 0);
    }
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        strings[a][0] = b;
        strings[b][0] = a;
    }
    for(int i = 1; i < 101; i++){
        for(int j = 1; j + i < 101; j++){
            for(int k = 0; k < i; k++){
                if(strings[j][0] == j + i || strings[j + i][0] == j){
                    dp[j][j + i] = max(dp[j][j + i], 1 + dp[j][j + k] + dp[j + k][j + i]);
                }
                else{
                    dp[j][j + i] = max(dp[j][j + i], dp[j][j + k] + dp[j + k][j + i]);
                }
            }
        }
    }
    cout << dp[1][100];
    return 0;
}