#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, M;
vector<int> adj[1010];
vector<int> conn;
vector<int> revConn;
vector<bool> visited;

bool dfs(int n){
    if(visited[n] == true) return false;
    visited[n] = true;
    for(auto i : adj[n]){
        if(revConn[i] == -1 || dfs(revConn[i])){
            conn[n] = i;
            revConn[i] = n;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    conn = vector<int>(N + 1, -1);
    revConn = vector<int>(M + 1, -1);
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int k;
            cin >> k;
            adj[i].push_back(k);
        }
    }
    for(int i = 1; i <= N; i++){
        visited = vector<bool>(N + 1, false);
        dfs(i);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(conn[i] != -1){
            ans++;
        }
    }
    cout << ans;
    return 0;
}