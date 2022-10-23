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

int N, M;
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> process;

bool dfs(int node){
    process[node] = true;
    for(auto dest : adj[node]){
        if(process[dest]){
            return false;
        }
        else if(!visited[dest]){
            if(!dfs(dest)){
                return false;
            }
        }
    }
    visited[node] = true;
    process[node] = false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    adj = vector<vector<int>>(N + 1);
    visited = vector<bool>(N + 1, false);
    process = vector<bool>(N + 1, false);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        if(u == v){
            continue;
        }
        adj[u].push_back(v);
    }
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            if(!dfs(i)){
                cout << "Ineligible";
                return 0;
            }
        }
    }
    cout << "Eligible";
    return 0;
}