#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int TC;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    vector<int> arr = vector<int>(10101010, 0);
    vector<int> sum = vector<int>(10101010, 0);
    arr[3]= 1;
    sum[3] = 1;
    arr[4] = 3;
    sum[4] = 4;
    for(int i = 5; i <= 10000000; i++){
        arr[i] += arr[i - 1];
        arr[i] += i - 2;
        arr[i] %= MOD;
        sum[i] = (sum[i - 1] + arr[i]) % MOD;
    }
    for(int tc = 1; tc <= TC; tc++){
        int a, b;
        cin >> a >> b;
        int ans = (sum[b] - sum[a - 1]);
        while(ans < 0){
            ans += MOD;
        }
        cout << ans << "\n";
    }   
    return 0;
}