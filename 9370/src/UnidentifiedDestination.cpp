#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;

int solve(){
    int N, M, T;
    int S, G, H;
    cin >> N >> M >> T;
    cin >> S >> G >> H;
    vector<pii> adj[N + 1];
    int dist[N + 1];
    int gDist[N + 1];
    int hDist[N + 1];
    bool visited[N + 1];
    int intersect;
    for(int i = 1; i <= N; i++){
        dist[i] = INT_MAX;
        gDist[i] = INT_MAX;
        hDist[i] = INT_MAX;
        visited[i] = false;
    }
    for(int i = 0; i < M; i++){
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
        if((a == G && b == H)||(a == H && b == G)){
            intersect = d;
        }
    }
    vector<int> dest;
    for(int i = 0; i < T; i++){
        int d;
        cin >> d;
        dest.push_back(d);
    }
    sort(dest.begin(), dest.end());
    priority_queue<pii> pq;
    pq.push({0, S});
    while(!pq.empty()){
        int currNode = pq.top().second;
        int currDist = -pq.top().first;
        pq.pop();
        if(visited[currNode] == true){
            continue;
        }
        dist[currNode] = currDist;
        visited[currNode] = true;
        for(int i = 0; i < adj[currNode].size(); i++){
            int nextNode = adj[currNode][i].first;
            int newDist = currDist + adj[currNode][i].second;
            pq.push({-newDist, nextNode});
        }
    }
    for(int i = 1; i <= N; i++){
        visited[i] = false;
    }
    pq.push({0, H});
    while(!pq.empty()){
        int currNode = pq.top().second;
        int currDist = -pq.top().first;
        pq.pop();
        if(visited[currNode] == true){
            continue;
        }
        gDist[currNode] = currDist;
        visited[currNode] = true;
        for(int i = 0; i < adj[currNode].size(); i++){
            int nextNode = adj[currNode][i].first;
            int newDist = currDist + adj[currNode][i].second;
            pq.push({-newDist, nextNode});
        }
    }
    for(int i = 1; i <= N; i++){
        visited[i] = false;
    }
    pq.push({0, G});
    while(!pq.empty()){
        int currNode = pq.top().second;
        int currDist = -pq.top().first;
        pq.pop();
        if(visited[currNode] == true){
            continue;
        }
        hDist[currNode] = currDist;
        visited[currNode] = true;
        for(int i = 0; i < adj[currNode].size(); i++){
            int nextNode = adj[currNode][i].first;
            int newDist = currDist + adj[currNode][i].second;
            pq.push({-newDist, nextNode});
        }
    }
    for(auto i : dest){
        if(dist[G] + intersect + gDist[i] == dist[i] || dist[H] + intersect + hDist[i] == dist[i]){
            cout << i << " ";
        }
    }
    cout << "\n";
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