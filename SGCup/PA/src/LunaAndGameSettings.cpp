#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MOD 1000000007

int N, K;
vector<int> arr;

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

ll getModInv(ll a){
    return power(a, MOD - 2);
}

ll binom(ll n, ll k){
    ll res = 1;
    for(ll i = 0; i < k; i++){
        res = (res * (n - i)) % MOD;
        ll inv = getModInv(i + 1);
        res = (res * inv) % MOD;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    arr.resize(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << (binom(N, K) * power(2, K - 1)) % MOD << "\n";
    return 0;
}