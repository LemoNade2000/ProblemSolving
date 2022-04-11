
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits.h>
#include <stack>

using namespace std;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> adj[1001];
int dist[1001];
int route[1001];

int dijkstra(int depart){
	for(int i = 0; i < 1001; i++){
		dist[i] = INT_MAX;
		route[i] = -1;
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
			if(dist[adjNode] > temp){
				dist[adjNode] = temp;
				route[adjNode] = minNode;
				pq.push(make_pair(-temp, adjNode));
			}
		}
	}
	return 0;
}
int main(){
	int numNode;
	int numEdge;
	cin >> numNode >> numEdge;
	int adjMat[numNode + 1][numNode + 1];
	for(int i = 1; i <= numNode; i++){
		for(int j = 1; j <= numNode; j++){
			adjMat[i][j] = INT_MAX;
		}
	}
	for(int i = 0; i < numEdge; i++){
		int start, end, weight;
		cin >> start >> end >> weight;
		if(adjMat[start][end] > weight){
			adjMat[start][end] = weight;
		}
	}
	for(int i = 1; i <= numNode; i++){
		for(int j = 1; j <= numNode; j++){
			if(adjMat[i][j] < INT_MAX){
				adj[i].push_back(make_pair(adjMat[i][j], j));
			}
		}
	}
	int depart, dest;
	cin >> depart >> dest;
	dijkstra(depart);
	int i = dest;
	stack<int> routeInfo;
	routeInfo.push(dest);
	while(route[i] != depart){
		routeInfo.push(route[i]);
		i = route[i];
	}
	routeInfo.push(depart);
	cout << dist[dest] << "\n";
	cout << routeInfo.size() << "\n";
	while(!routeInfo.empty()){
		cout << routeInfo.top() << " ";
		routeInfo.pop();
	}
}
