#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> adj[20001];
int dist[20001];

int dijkstra(int node, int depart){
	for(int i = 0; i < 20001; i++){
		dist[i] = INT_MAX;
	}
	dist[depart] = 0;
	pq.push(make_pair(0, depart));
	while(!pq.empty()){

		int cost = -pq.top().first;
		int minNode = pq.top().second;
		pq.pop();

		if(dist[minNode] < cost){
			continue;
		}
		for(int j = 0; j < adj[minNode].size(); j++){
			int adjNode = adj[minNode][j].second;
			int temp = cost + adj[minNode][j].first;
			if(dist[adjNode] >= temp){
				dist[adjNode] = temp;
				pq.push(make_pair(-temp, adjNode));
			}
		}
	}
	return 0;
}

int main() {
	int numNode;
	int numEdge;
	cin >> numNode >> numEdge;
	int departure;
	cin >> departure;
	for(int i = 0; i < numEdge; i++){
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(weight, end));
	}
	dijkstra(numNode, departure);
	for(int i = 1; i <= numNode; i++){
		if(dist[i] == INT_MAX){
			cout << "INF\n";
		}
		else{
		cout << dist[i] << "\n";
		}
	}
	return 0;
}
