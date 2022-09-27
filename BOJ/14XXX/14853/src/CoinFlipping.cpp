#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define MOD 1000000007

int TC;
pair<ld, ld> coinA, coinB;

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
    cin >> TC;
    cout << fixed << setprecision(5);
    for(int tc = 1; tc <= TC; tc++){
        cin >> coinA.first >> coinA.second >> coinB.first >> coinB.second;
        ld ans = 0;
        ld den;
        ld num;
        num = den = 0;
        ld temp = 1;
        for(int i = 0; i <= coinA.second; i++){
            temp = temp * (coinA.first + 1 - i) / (coinA.first + coinB.first + 2 - i);
        }
        num += temp;
        for(int i = 1; i <= coinB.second; i++){
            temp = temp * ((ld)(coinA.second + i) / (ld)(i)) * ((ld)(coinB.first + 2 - i) / (ld)(coinA.first + coinB.first + 2 - coinA.second - i));
            num += temp;
        }
        cout << num << "\n";
    }
    return 0;
}