#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr.resize(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    int maximum = 0;
    int dp[N + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    maximum = arr[1];
    int sum = 2;
    for(int i = 2; i <= N; i++){
        if(arr[i] > maximum){
            maximum = arr[i];
            dp[i] = sum;
        }
        else{
            dp[i] = dp[i - 1] % MOD;
        }
        sum = (sum + dp[i]) % MOD;
    }
    cout << dp[N];
}