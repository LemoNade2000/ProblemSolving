#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

string str;
int dp[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < str.size() - 1; i++){
        dp[i][i] = 1;
        if(str[i] == str[i + 1]){
            dp[i][i + 1] = 3;
        }
        else{
            dp[i][i + 1] = 2;
        }
    }
    dp[str.size() - 1][str.size() - 1] = 1;
    for(int i = 3; i <= str.size(); i++){
        int left = 0;
        int right = i - 1;
        while(right < str.size()){
            dp[left][right] = dp[left + 1][right] + dp[left][right - 1] - dp[left + 1][right - 1];
            if(str[left] == str[right]){
                dp[left][right] += 1 + dp[left + 1][right - 1];
            }
            dp[left][right] %= 10007;
            if(dp[left][right] < 0){
                dp[left][right] += 10007;
            }
            left++;
            right++;
        }
    }
    cout << dp[0][str.size() - 1] % 10007;
    return 0;
}