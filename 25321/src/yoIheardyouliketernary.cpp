#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

string str;
stack<ll> st;

int dp[300001];

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

ll catalan(ll n){
    if(dp[n] != 0){
        return dp[n];
    }
    ll res = (binom(2 * n, n) * getModInv(n + 1)) % MOD;
    dp[n] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        char c = str[i];
        if(c == '?'){
            st.push(-1);
        }
        else if(c == ':'){
            ll arrSize = 0;
            ll product = 1;
            while(st.top() != -1){ // number
                product = (product * st.top()) % MOD;
                arrSize++;
                st.pop();
            }
            st.pop();
            st.push((catalan(arrSize) * product) % MOD);
        }
    }
    ll prod = 1;
    ll arrSize = 0;
    while(!st.empty()){
        prod = (prod * st.top()) % MOD;
        arrSize++;
        st.pop();
    }
    ll ans = (prod * catalan(arrSize)) % MOD;
    cout << ans;
    return 0;
}