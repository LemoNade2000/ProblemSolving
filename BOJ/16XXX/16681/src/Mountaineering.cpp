#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 987654321

vector<pair<int, ll>> adj[101010];
ll N, M, D, E;
vector<ll> incDist;
vector<ll> decDist;
vector<ll> height;

int climbDijkstra(int start, int dest){
    incDist = vector<ll>(N + 1, -10);
    priority_queue<pair<ll, int>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int node = pq.top().second;
        ll currDist = -pq.top().first;
        pq.pop();
        if(incDist[node] != -10){
            continue;
        }
        incDist[node] = currDist;
        for(auto edge : adj[node]){
            if(height[node] < height[edge.first]){
                pq.push({-(currDist + edge.second), edge.first});
            }
        }
    }
    return 0;
}

int declineDijkstra(int start, int dest){
    decDist = vector<ll>(N + 1, -10);
    priority_queue<pair<ll, int>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int node = pq.top().second;
        ll currDist = -pq.top().first;
        pq.pop();
        if(decDist[node] != -10){
            continue;
        }
        decDist[node] = currDist;
        for(auto edge : adj[node]){
            if(height[node] < height[edge.first]){
                pq.push({-(currDist + edge.second), edge.first});
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> D >> E;
    height = vector<ll>(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> height[i];
    }
    for(int i = 0; i < M; i++){
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    ll ans = LLONG_MIN;
    climbDijkstra(1, N);
    declineDijkstra(N, 1);
    for(int i = 2; i < N ; i++){
        ll climb = incDist[i];
        ll desc = decDist[i];
        if(climb == -10 || desc == -10){
            continue;
        }
        ans = max(ans, height[i] * E - (climb + desc) * D);
    }
    if(ans == LLONG_MIN){
        cout << "Impossible";
        return 0;
    }
    cout << ans << "\n";
    return 0;
}