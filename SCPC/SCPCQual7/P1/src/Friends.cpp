#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N;
bool visited[100001];
vector<int> link[100001];

int dfs(int node){
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto i : link[curr]){
            if(visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return 0;
}

int solve(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        visited[i] = false;
        link[i].clear();
    }
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        if(i + n <= N){
            link[i].push_back(i + n);
            link[i + n].push_back(i);
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(visited[i] == false){
            ans++;
            dfs(i);
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
    cout << "Case #" << tc << "\n";
    solve();
    }
}