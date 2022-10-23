# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<int> prime;

ll power(ld a, ll pow){
    ld res = 1;
    if(a == 1) return 1;
    while(pow > 0){
        if(pow & 1 == 1){
            res = (res * a);
        }
        a = (a * a);
        pow = pow >> 1;
    }
    return res;
}

ll binom(ll n, ll k){
    ll res = 1;
    ll div = 1;
    if(k * 2 > n){
        k = n - k;
    }
    for(ll i = 0; i < k; i++){
        res = (res * (n - i));
        div *= (i + 1);
        if(res % div == 0){
            res = res / div;
            div = 1;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B;
    cin >> A >> B;
    ld aProb = A / 100.0;
    ld bProb = B / 100.0;
    for(int i = 2; i < 19; i++){
        bool flag = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            prime.push_back(i);
        }
    }
    ld aPrimeProb = 0;
    ld bPrimeProb = 0;
    for(auto i : prime){
        ll coeff = binom(18, i);
        ld dEff = (ld)coeff;
        for(int j = 0; j < i; j++){
            dEff *= aProb;
        }
        for(int j = 0; j < 18 - i; j++){
            dEff *= (1.0 - aProb);
        }
        aPrimeProb += dEff;
        dEff = (ld)coeff;
        for(int j = 0; j < i; j++){
            dEff *= bProb;
        }
        for(int j = 0; j < 18 - i; j++){
            dEff *= (1.0 - bProb);
        }
        bPrimeProb += dEff;
    }
    cout << fixed << setprecision(8);
    cout << aPrimeProb + bPrimeProb - (aPrimeProb * bPrimeProb);
    return 0;
}