#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 998244353

int TC;

ll P, N, K;
ll tot;
vector<ll> arr;
vector<ll> prob;
vector<ll> newProb;
vector<ll> ans;

ll power(ll a, ll pow){
    ll res = 1;
    if(a == 1) return 1;
    while(pow > 0){
        if(pow & 1 == 1){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        pow = pow >> 1;
    }
    return res % MOD;
}

int solve(){
    cin >> N >> K;
    P = 0;
    arr = vector<ll>(N, 0);
    prob = vector<ll>(N, 0);
    newProb = vector<ll>(N, 0);
    ans = vector<ll>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        P += arr[i];
    }
    tot = P;
    for(int i = 0; i < N; i++){
        prob[i] = P - arr[i];
        newProb[i] = prob[i];
    }
    ll ans = 0;
    for(int i = 1; i <= K; i++){
        ll KP = P * N;
        // cout << K << " " << P << " ";
        for(int j = 0; j < N; j++){
            KP -= newProb[j];
            newProb[j] *= prob[j];
            newProb[j] %= MOD;
            if(newProb[j] < 0){
                newProb[j] += MOD;
            }
        }
        KP %= MOD;
        while(KP < 0){
            KP += MOD;
        }
        // cout << KP << "\n";
        P *= tot;
        P %= MOD;
        if(P < 0){
            P += MOD;
        }
        ans ^= KP;
    }
    while(ans < 0){
        ans += MOD;
    }
    cout << ans << endl;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
    cout << "Case #" << tc << endl;
    solve();
    }
    return 0;
}