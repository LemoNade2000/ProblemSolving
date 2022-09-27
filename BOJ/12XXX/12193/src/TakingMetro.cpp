#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 987654321

int TC;
int N, M, Q;
int w[101];
int s[101];
vector<pair<pii, int>> adj[101][2020];

int dijkstra(int mA, int sA, int mB, int sB){
    if(mA == mB && sA == sB){
        return 0;
    }
    int dist[101][2020];
    bool visited[101][2020];
    memset(dist, -1, sizeof(dist));
    memset(visited, false, sizeof(visited));
    priority_queue<pair<int, pii>> pq;
    pq.push({0, {mA, sA * 2 + 1}});
    adj[mA][sA * 2 + 1].push_back({{mA, sA * 2}, w[mA]});
    adj[mA][sA * 2].push_back({{mA, sA * 2 + 1}, 0});
    dist[mA][sA * 2 + 1] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        pii station = pq.top().second;
        pq.pop();
        if(visited[station.first][station.second] == true){
            continue;
        }
        dist[station.first][station.second] = cost;
        visited[station.first][station.second] = true;
        if(station.first == mB && (station.second == sB * 2 || station.second == sB * 2 + 1)){
            break;
        }
        for(int i = 0; i < adj[station.first][station.second].size(); i++){
            pii nextStation = adj[station.first][station.second][i].first;
            int nextCost = adj[station.first][station.second][i].second;
            int nextDist = cost + nextCost;
            pq.push({-nextDist, nextStation});
        }
    }
    if(dist[mB][sB * 2] == -1 && dist[mB][sB * 2 + 1] == -1){
        cout << "-1\n";
        return 0;
    }
    else{
        if(dist[mB][sB * 2] == -1){
            dist[mB][sB * 2] = INT_MAX;
        }
        if(dist[mB][sB * 2 + 1] == -1){
            dist[mB][sB * 2 + 1] = INT_MAX;
        }
        cout << min(dist[mB][sB * 2 + 1], dist[mB][sB * 2]) << "\n";
    }
    return 0;
}

int solve(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        int SN, W;
        cin >> SN >> W;
        w[i] = W; s[i] = SN;
        for(int j = 1; j < SN; j++){
            int t;
            cin >> t;
            adj[i][j * 2].push_back({{i, (j + 1) * 2}, t});
            adj[i][(j + 1) * 2].push_back({{i, j * 2}, t});
        }
    }
    cin >> M;
    for(int i = 1; i <= M; i++){
        int mA, sA, mB, sB, t;
        cin >> mA >> sA >> mB >> sB >> t;
        adj[mA][sA * 2 + 1].push_back({{mB, sB * 2 + 1}, t});
        adj[mB][sB * 2 + 1].push_back({{mA, sA * 2 + 1}, t});
        adj[mA][sA * 2 + 1].push_back({{mA, sA * 2}, w[mA]});
        adj[mA][sA * 2].push_back({{mA, sA * 2 + 1}, 0});
        adj[mB][sB * 2 + 1].push_back({{mB, sB * 2}, w[mB]});
        adj[mB][sB * 2].push_back({{mB, sB * 2 + 1}, 0});
    }
    cin >> Q;
    for(int i = 1; i <= Q; i++){
        int mA, sA, mB, sB;
        cin >> mA >> sA >> mB >> sB;
        dijkstra(mA, sA, mB, sB);
    }
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 2020; j++){
            adj[i][j].clear();
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        cout << "Case #" << tc << ":\n";
        solve();
    }
    return 0;
}