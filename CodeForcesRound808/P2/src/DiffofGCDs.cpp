#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
ll N, L, R;

vector<ll> conn;
map<ll, ll> revConn;
vector<bool> visited;

ll gcd(ll a, ll b)
{
    int c;
	while(b){
		c = a % b;
		a = b;
		b = c;
	}
    return a;
}

bool dfs(ll n){
    if(visited[n] == true) return false;
    visited[n] = true;
    ll start = L / n;
    if(start * n < L){
        start++;
    }
    for(; start * n <= R; start++){
        if(revConn.count(start * n) == 0 || dfs(revConn[start * n]) == true){
            conn[n] = start * n;
            revConn[start * n] = n;
            return true;
        }
    }
    return false;
}

int solve(){
    revConn.clear();
    visited.clear();
    cin >> N >> L >> R;
    conn = vector<ll>(N + 1, -1);
    vector<vector<int>> adj;
    adj.resize(N + 1);
    for(ll i = N; i >= 1; i--){
        visited = vector<bool>(N + 1, false);
        if(!dfs(i)){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(ll i = 1; i <= N; i++){
        cout << conn[i] << " ";
    }
    cout << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        solve();
    }
    return 0;
}