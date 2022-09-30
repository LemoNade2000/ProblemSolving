#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAX 987654321

struct Edge{
    int u, v, w;
};

int N, M;
int dist[201][201];
vector<Edge> edges;
bool inProcess[20001];
bool completed[20001];
bool visited[201];

void floWar(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

double burnTime(int root){
    double maxTime = 0;
    for(Edge edge : edges){
        double edgeBurn;
        double burnStart = min(dist[root][edge.u], dist[root][edge.v]);
        double burnLateStart = max(dist[root][edge.u], dist[root][edge.v]);
        if(burnStart + edge.w < burnLateStart){
            edgeBurn = burnStart + edge.w;
        }
        else{
            double diff = burnLateStart - burnStart;
            double remain = edge.w - diff;
            edgeBurn = burnLateStart + (remain / 2);
        }
        maxTime = max(edgeBurn, maxTime);
    }
    return maxTime;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dist[i][j] = MAX;
        }
    }
    for(int i = 1; i <= N; i++){
        dist[i][i] = 0;
    }
    for(int i = 1; i <= M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        dist[u][v] = min(w, dist[u][v]);
        dist[v][u] = min(w, dist[u][v]);
    }
    floWar();
    double minimum = DBL_MAX;
    for(int i = 1; i <= N; i++){
        minimum = min(minimum, burnTime(i));
    }
    cout << fixed << setprecision(1);
    cout << minimum;
}