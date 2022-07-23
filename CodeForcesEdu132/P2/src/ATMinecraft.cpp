#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
ll N, M;

int solve(){
    cin >> N >> M;
    vector<ll> arr(N + 2, 0);
    vector<ll> pref(N + 1, 0);
    vector<ll> revPref(N + 2, 0);
    arr[0] = 0;
    ll prev = 0;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    arr[N + 1] = arr[N];
    arr[0] = arr[1];
    prev = arr[0];
    for(int i = 1; i <= N; i++){
        pref[i] = pref[i - 1];
        if(arr[i] < prev){
            pref[i] += prev - arr[i];
        }
        prev = arr[i];
    }
    prev = arr[N + 1];
    for(int i = N; i >= 1; i--){
        revPref[i] = revPref[i + 1];
        if(arr[i] < prev){
            revPref[i] += prev - arr[i];
        }
        prev = arr[i];
    }
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        if(a > b){
            cout << revPref[b] - revPref[a] << "\n"; 
        }
        else if(a < b){
            cout << pref[b] - pref[a] << "\n";
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}