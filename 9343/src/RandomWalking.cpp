#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

vector<ll> inv;
vector<ll> facto;

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
        ll getinv = inv[i + 1];
        res = (res * getinv) % MOD;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    inv.push_back(0);
    for(int i = 1; i <= 1000001; i++){
        inv.push_back(getModInv(i));
    }
    facto = vector<ll>(1000001, 0);
    facto[1] = 2;
    ll temp = 2;
    for(ll i = 2; i <= 1000000; i++){
        temp = (temp * (i << 1)) % MOD;
        temp = (temp * ((i << 1) - 1)) % MOD;
        temp = (temp * inv[i]) % MOD;
        temp = (temp * inv[i]) % MOD;
        facto[i] = temp;
    }
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        ll coeff = facto[num];
        ll modinv = inv[num + 1];
        ll ans = (coeff * modinv) % MOD;
        cout << ans << "\n";
    }
    return 0;
}