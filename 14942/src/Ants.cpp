#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
int parent[100001][18];
int cost[100001][18];
vector<pii> adj[100001];
vector<int> antEnergy;
int depth[100001];
bool visited[100001];

int dfs(int node, int treeDepth){
    visited[node] = true;
    depth[node] = treeDepth;
    for(auto childNode : adj[node]){
        if(!visited[childNode.first]){
            parent[childNode.first][0] = node;
            cost[childNode.first][0] = childNode.second;
            dfs(childNode.first, treeDepth + 1);
        }
    }
    return 0;
}

void memo(){
    for(int i = 1; i < 18; i++){
        for(int node = 1; node <= N; node++){
            int prevParent = parent[node][i - 1];
            if(parent[prevParent][i - 1] == 0){
                continue;
            }
            parent[node][i] = parent[prevParent][i - 1];
            cost[node][i] = cost[node][i - 1] + cost[prevParent][i - 1];
        }
    }
    return;
}

int travel(int node, int energy){
//    cout << node << " " << energy << "\n";
    if(cost[node][0] > energy){
        return node;
    }
    else if(node == 1){
        return node;
    }
    for(int i = 17; i >= 0; i--){
        if(depth[node] < (1 << i)){
            continue;
        }
        if(cost[node][i] <= energy){
            return travel(parent[node][i], energy - cost[node][i]);
        }
    }
    return node;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    memset(visited, false, sizeof(visited));
//    memset(cost, 999999, sizeof(cost));
    for(int i = 0; i < N; i++){
        int nrg;
        cin >> nrg;
        antEnergy.push_back(nrg);
    }
    for(int i = 1; i < N; i++){
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].push_back(make_pair(v, l));
        adj[v].push_back(make_pair(u, l));
    }
    dfs(1, 0);
    memo();
    for(int i = 1; i <= N; i++){
        cout << travel(i, antEnergy[i - 1]) << "\n";
    }
    return 0;
}

