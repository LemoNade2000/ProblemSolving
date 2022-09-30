#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Seed{
    ll quantity;
    ll days;
    ll value;
};

int TC;
ll D, N ,X;
vector<Seed> seeds;
vector<ll> cap;

bool compVal(Seed &a, Seed &b){
    if(a.value > b.value){
        return true;
    }
    else if(a.value == b.value){
        if(a.days < b.days){
            return true;
        }
    }
    else return false;
}

int solve(){
    cin >> D >> N >> X;
    seeds = vector<Seed>(N);
    cap = vector<ll>(D + 1, X);
    for(int i = 0; i < N; i++){
        cin >> seeds[i].quantity >> seeds[i].days >> seeds[i].value;
    }
    sort(seeds.begin(), seeds.end(), compVal);
    ll ans = 0;
    set<ll> avail;
    avail.insert(-1);
    for(int i = 1; i <= D; i++){
        avail.insert(i);
    } 
    for(int i = 0; i < N; i++){
        Seed curr = seeds[i];
        ll latest = D - curr.days;
        auto it = avail.upper_bound(latest);
        it--;
        latest = *it;
        while(curr.quantity > 0 && latest >= 0 && !avail.empty()){
            // if(cap[latest] == 0){
            //     it--;
            //     continue;
            // }
            // else{
                if(cap[latest] > curr.quantity){
                    ans += curr.quantity * curr.value;
                    cap[latest] -= curr.quantity;
                    break;
                }
                else if(cap[latest] <= curr.quantity){
                    ans += cap[latest] * curr.value;
                    curr.quantity -= cap[latest];
                    cap[latest] = 0;
                    avail.erase(latest);
                    it--;
                    if(avail.empty()){
                        break;
                    }
                }
            // }
            latest = *it;
        }
    }
    cout << ans << "\n";
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
    cout << "Case #" << tc << ": ";
    solve();
    }
    return 0;
}