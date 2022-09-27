#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;
int N;

bool comp(pii a, pii b){
    if(a.first < b.first){
        return true;
    }
    else return false;
}

int solve(){
    cin >> N;
    vector<pii> arr;
    vector<int> sorted;
    arr.push_back({-1, -1});
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        if(n >= i){
            continue;
        }
        arr.push_back({n, i});
        sorted.push_back(n);
    }
    sort(sorted.begin(), sorted.end());
    ll ans = 0;
    for(auto p : arr){
        if(p.first == -1){
            continue;
        }
        auto it = lower_bound(sorted.begin(), sorted.end(), p.second + 1);
        ans += sorted.end() - it; 
    }
    cout << ans << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        solve();
    }
    return 0;
}