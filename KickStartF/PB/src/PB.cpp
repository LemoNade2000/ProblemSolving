#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N, Q;
vector<vector<int>> adj;
vector<int> level;
vector<int> lvlCnt;

int solve(){
    cin >> N >> Q;
    adj = vector<vector<int>>(N + 1);
    level = vector<int>(N + 1, -1);
    lvlCnt = vector<int>(N + 1, 0);
    for(int i = 1; i <= N; i++){
        adj[i] = vector<int>(0);
    }
    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    level[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i = 0; i < adj[curr].size(); i++){
            if(level[adj[curr][i]] == -1){
                level[adj[curr][i]] = level[curr] + 1;
                q.push(adj[curr][i]);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        lvlCnt[level[i]]++;
    }
    int currLvl = 1;
    int ans = 0;
    for(int i = 1; i <= Q; i++){
        int n;
        cin >> n;
        lvlCnt[currLvl]--;
        if(lvlCnt[currLvl] == 0){
            currLvl++;
            ans = i;
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