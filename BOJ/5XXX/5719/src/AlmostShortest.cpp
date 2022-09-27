#include <bits/stdc++.h>

using namespace std;

#define MAX 987654321
typedef pair<int, int> pii;

vector<pii> adj[500];
int V, E;
int start, dest;
int dist[500];
vector<pii> from[500];

int dijkstra(){
	for(int i = 0; i < V; i++){
		dist[i] = MAX;
		from[i].clear();
	}
	priority_queue<pii> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while(!pq.empty()){
		int cost = -pq.top().first;
		int minNode = pq.top().second;
		pq.pop();
		if(dist[minNode] < cost){
			continue;
		}
		for(int j = 0; j < adj[minNode].size(); j++){
			if(adj[minNode][j].second < 0){ // no edge from minNode to j
				continue;
			}
			int adjNode = adj[minNode][j].first;
			int temp = cost + adj[minNode][j].second;
			if(dist[adjNode] > temp){
				from[adjNode].clear();
				dist[adjNode] = temp;
				pq.push(make_pair(-temp, adjNode));
				from[adjNode].push_back(make_pair(minNode, j));
			}
			else if(dist[adjNode] == temp){
				from[adjNode].push_back(make_pair(minNode, j));
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		cin >> V >> E;
		if(V == 0 && E == 0){
			break;
		}
		for(int i = 0; i < V; i++){
			adj[i].clear();
		}
		cin >> start >> dest;
		for(int i = 0; i < E; i++){
			int u, v, p;
			cin >> u >> v >> p;
			adj[u].push_back(make_pair(v, p));
		}
		dijkstra();
		queue<int> q;
		q.push(dest);
		bool visited[V];
		for(int i = 0; i < V; i++){
			visited[i] = false;
		}
		while(!q.empty()){
			int ePoint = q.front();
			q.pop();
//			if(visited[ePoint] == true){
//				continue;
//			}
			visited[ePoint] = true;
			for(int i = 0; i < from[ePoint].size(); i++){
				int u = from[ePoint][i].first;
				int idx = from[ePoint][i].second;
				if(visited[u] == true){
					continue;
				}
				adj[u][idx].second = -1;
				q.push(u);
			}
		}
		dijkstra();
		if(dist[dest] >= MAX){
			cout << "-1\n";
		}
		else{
			cout << dist[dest] << "\n";
		}
	}
	return 0;
}
