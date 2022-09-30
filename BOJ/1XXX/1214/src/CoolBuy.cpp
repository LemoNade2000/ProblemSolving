#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

ll D, P ,Q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> D >> P >> Q;
    if(P < Q){
        ll temp = Q;
        Q = P;
        P = temp;
    }
    if(P == 1 || Q == 1){
        cout << D;
        return 0;
    }
    ll pCount = ceil((long double)D / (long double)P);
    ll qCount = 0;
    ll minCost = LLONG_MAX;
    ll currBal = pCount * P;
    for(; pCount >= 0; pCount--){
        if(currBal < D){
            qCount = ceil((D - (pCount * P)) / (long double) Q);
            currBal = pCount * P + qCount * Q;
        }
        if(minCost == pCount * P + qCount * Q || minCost == D){
            cout << minCost;
            return 0;
        }
        minCost = min(minCost, pCount * P + qCount * Q);
        currBal -= P;
    }
    cout << minCost;
    return 0;
}