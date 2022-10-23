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

ll M, K;
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
    cin >> M;
    ll tot = 0;
    for(int i = 0; i < M; i++){
        int n;
        cin >> n;
        arr.push_back(n);
        tot += n;
    }
    cin >> K;
    ll event, population;
    population = binom(tot, K);
    event = 0;
    for(int i = 0; i < M; i++){
        if(K <= arr[i]){
            event += binom(arr[i], K);
        }
    }
    double dVent = (double)event;
    for(ll i = 0; i < K; i++){
        dVent /= (tot - i);
        dVent *= (i + 1);
    }
    cout << fixed << setprecision(10);
    cout << dVent;
    return 0;
}