#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 987654321

int N;
vector<int> arr;
int dp[51][505050];
vector<int> sum;

int fill(int idx, int hDiff){
    if(idx > 0 && hDiff > sum[N - 1] - sum[idx - 1]){
        return -MAX;
    }
    if(idx == N){
        if(hDiff == 0){
            return 0;
        }
        else{
            return -MAX;
        }
    }
    if(dp[idx][hDiff] != -1){
        return dp[idx][hDiff];
    }
    int ret = -MAX;
    ret = max({ret, fill(idx + 1, hDiff), fill(idx + 1, hDiff + arr[idx]), min(arr[idx], hDiff) + fill(idx + 1, abs(hDiff - arr[idx]))});
    return dp[idx][hDiff] = ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    arr = vector<int>(N);
    sum = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(i == 0){
            sum[i] = arr[i];
        }
        else{
            sum[i] += sum[i - 1] + arr[i];
        }
    }
    fill(0, 0);
    if(dp[0][0] > 0){
        cout << dp[0][0];
    }
    else{
        cout << "-1\n";
    }
    return 0;
}