#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N, M;

int solve(){
    cin >> N >> M;
    vector<int> adj[N + 1];
    vector<int> status;
    status.resize(N + 1);
    bool visited[N + 1];
    for(int i = 1; i <= N; i++){
        status[i] = -1;
        visited[i] = false;
    }
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<pii> q;
    bool answer = true;
    for(int i = 1; i <= N; i++){
        if(visited[i] == false){
            q.push({i, 0});
            visited[i] = true;
            while(!q.empty()){
                int node = q.front().first;
                int flag = q.front().second;
                q.pop();
                for(int j = 0; j < adj[node].size(); j++){
                    if(visited[adj[node][j]] == false){
                        q.push({adj[node][j], (1 ^ flag)});
                        status[adj[node][j]] = (1 ^ flag);
                        visited[adj[node][j]] = true;
                    }
                    else if(visited[adj[node][j]] == true){
                        if(status[adj[node][j]] == flag){
                            answer = false;
                            break;
                        }
                    }
                }
                if(answer == false){
                    break;
                }
            }
        }
    }
    if(answer == true){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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