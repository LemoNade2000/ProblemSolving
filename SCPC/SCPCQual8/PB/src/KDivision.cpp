#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N;
ll K, obj;


int solve(){
    cin >> N >> K;
    vector<ll> arr(N + 1);
    vector<ll> preSum(N + 1);
    vector<ll> modArr;
    preSum[0] = 0;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        preSum[i] = preSum[i - 1] + arr[i];
    }
    obj = preSum[N] / K;
    if(obj * K != preSum[N]){
        cout << "0\n";
        return 0;
    }
    int sum = 0;
    for(int i = 1; i <= N; i++){
        sum += arr[i];
        if(sum == 0 || sum == obj){
            modArr.push_back(sum);
            sum = 0;
        }
    }
    for(auto i : modArr){
        cout << i << " ";
    }
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