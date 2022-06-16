#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAX 987654321

struct Road{
    int dest, cost, num;
};

int N, M, K;
int origin, destination;
vector<Road> adj[1001];
vector<int> taxIncrease;
int dist[1001][1001];
int minDist[1001];
int minNum[1001];

bool cmp(Road a, Road b){
    if(a.cost < b.cost){
        return true;
    }
    else return false;
}

int dijkstra(){
    priority_queue<Road, vector<Road>, decltype(&cmp)> pq(cmp);
    Road road;
    road.cost = 0;
    road.dest = origin;
    road.num = 0;
    pq.push(road);
    dist[origin][0] = 0;
    minDist[origin] = 0;
    minNum[origin] = 0;
    while(!pq.empty()){
        int minNode = pq.top().dest;
        int cost = pq.top().cost;
        int numRoad = pq.top().num;
        pq.pop();
        if(minNum[minNode] < numRoad && minDist[minNode] < cost){
            continue;
        }
        if(dist[minNode][numRoad] < cost) continue;
        for(int i = 0; i < adj[minNode].size(); i++){
            Road newRoad;
            newRoad.dest = adj[minNode][i].dest;
            newRoad.cost = cost + adj[minNode][i].cost;
            newRoad.num = numRoad + 1;
            if(newRoad.num > N) continue;
//            cout << newRoad.dest << " " << newRoad.cost << " " << newRoad.num << "\n";
            if(dist[newRoad.dest][newRoad.num] > newRoad.cost){
                dist[newRoad.dest][newRoad.num] = newRoad.cost;
                pq.push(newRoad);
            }
            if(minDist[newRoad.dest] > newRoad.cost){
                minDist[newRoad.dest] = newRoad.cost;
                minNum[newRoad.dest] = newRoad.num;
            }
        }
    }
    
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    cin >> origin >> destination;
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            dist[i][j] = MAX;
        }
        minDist[i] = MAX;
        minNum[i] = MAX;
    }
    for(int i = 0; i < M; i++){
        int s, e, w;
        cin >> s >> e >> w;
        Road road;
        road.cost = w;
        road.num = 1;
        road.dest = e;
        adj[s].push_back(road);
        road.dest = s;
        adj[e].push_back(road);
    }
    for(int i = 0; i < K; i++){
        int tax;
        cin >> tax;
        taxIncrease.push_back(tax);
    }
    dijkstra();
    int minRoad = 1000;
    for(int tc = 0; tc < K; tc++){
        int minimum = INT_MAX;
        int currTax = taxIncrease[tc];
        for(int i = minRoad; i >= 0; i--){
            if(minimum > dist[destination][i]){
                minimum = dist[destination][i];
                minRoad = i;
            }
            dist[destination][i] = dist[destination][i] + i * currTax;
        }
        cout << minimum << "\n";
    }
    int minimum = INT_MAX;
    for(int i = minRoad; i >= 0; i--){
        if(minimum > dist[destination][i]){
            minimum = dist[destination][i];
            minRoad = i;
        }
    }
    cout << minimum;
}