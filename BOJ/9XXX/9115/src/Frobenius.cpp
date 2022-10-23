#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;

int solve(){
    vector<int> arr;
    arr = vector<int>(4);
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    vector<int> dp(5000000);
    int maxi = 0;
    int cnt = 0;
    dp[0] = 1;
    for(int i = 1; i < 5000000; i++){
        if(i - arr[0] >= 0){
            dp[i] = max(dp[i], dp[i - arr[0]]);
        }
        if(i - arr[1] >= 0){
            dp[i] = max(dp[i], dp[i - arr[1]]);
        }
        if(i - arr[2] >= 0){
            dp[i] = max(dp[i], dp[i - arr[2]]);
        }
        if(i - arr[3] >= 0){
            dp[i] = max(dp[i], dp[i - arr[3]]);
        }
        if(dp[i] == 0){
            maxi = i;
        }
        else{
            if(i <= 1000000) cnt++;
        }
    }
    cout << 1000000 - cnt << "\n";
    if(maxi > 1000000){
        cout << "-1\n";
        return 0;
    }
    cout << maxi << "\n";
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