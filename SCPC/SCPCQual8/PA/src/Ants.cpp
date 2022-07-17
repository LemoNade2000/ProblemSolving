#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N;

int solve(){
    cin >> N;
    vector<int> P;
    vector<pii> V;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        P.push_back(n);
    }
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        V.push_back({n, i});
    }
    sort(V.begin(), V.end());
    ll sum = 0;
    for(int i = 0; i < N; i++){
        sum += abs(P[V[i].second] - P[i]);
    }
    cout << sum << "\n";
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