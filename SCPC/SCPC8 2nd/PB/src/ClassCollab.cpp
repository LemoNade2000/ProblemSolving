#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

typedef tree<
    ll,
    null_type,
    less<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

int TC;
int N;
vector<ll> line;
vector<vector<ll>> locations;
vector<ll> numPairs;
vector<pii> pairs;

int solve(){
    cin >> N;
    line = vector<ll>(N, 0);
    locations = vector<vector<ll>>(N + 1);
    numPairs = vector<ll>(N + 1, 0);
    ordered_set app;
    for(int i = 0; i < N; i++){
        cin >> line[i];
        locations[line[i]].push_back(i);
    }
    ll score = 0;
    ll totalPairs = 0;
    for(int i = N - 1; i >= 0; i--){
        ll c = line[i];
        if(numPairs[c] < (locations[c].size() >> 1) && 
        locations[c][locations[c].size() - 1 - numPairs[c]] != locations[c][numPairs[c]]){
            ll right = locations[c][locations[c].size() - 1 - numPairs[c]];
            ll left = locations[c][numPairs[c]];
            ll largeRight, largeLeft;
            largeRight = app.order_of_key(right);
            largeLeft = app.order_of_key(left);
            ll rightIdx = right - largeRight;
            ll leftIdx = left - largeLeft;
            score += abs(rightIdx - leftIdx);
            app.insert(right);
            app.insert(left);
            numPairs[c]++;
        }
    }
    cout << score << "\n";
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