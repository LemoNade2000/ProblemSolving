#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;
ll N, K;

int solve(){
    cin >> N >> K;
    vector<ll> arr, modArr;
    for(int i = 0; i < N; i++){
        ll n;
        cin >> n;
        arr.push_back(n);
        modArr.push_back(n);
    }
    vector<ll> sum;
    sum.resize(N);
    sum[N - 1] = arr[N - 1];
    for(int i = N - 2; i >= 0; i--){
        sum[i] = sum[i + 1] + arr[i];
    }
    ll maxCost = N * K;
    for(int i = 1; i <= min((ll)32, N); i++){
        ll newCost = 0;
        newCost += K * (N - i);
        for(int j = 0; j < i; j++){\
            modArr[N - 1 - j] = (modArr[N - 1 - j] >> 1);
            newCost += arr[N - 1 - j] - modArr[N - 1 - j];
        }
        maxCost = min(maxCost, newCost);
    }
    cout << sum[0] - maxCost << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        solve();
    }
    return 0;
}