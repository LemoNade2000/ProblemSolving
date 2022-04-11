#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> adj[1001];
vector<pair<int, int>> revAdj[1001];
int dist[1001];
int revDist[1001];
int dijkstra(int depart){
	for(int i = 0; i < 1001; i++){
		dist[i] = INT_MAX;
		revDist[i] = INT_MAX;
	}
	dist[depart] = 0;
	revDist[depart] = 0;

	pq.push(make_pair(0, depart));

	// node -> party
	while(!pq.empty()){
		int cost = -pq.top().first;
		int minNode = pq.top().second;
		pq.pop();

		if(dist[minNode] < cost){
			continue;
		}
		for(int j = 0; j < revAdj[minNode].size(); j++){
			int adjNode = revAdj[minNode][j].second;
			int temp = cost + revAdj[minNode][j].first;
			if(dist[adjNode] >= temp){
				dist[adjNode] = temp;
				pq.push(make_pair(-temp, adjNode));
			}
		}
	}

	pq.push(make_pair(0, depart));

	while(!pq.empty()){
		int cost = -pq.top().first;
		int minNode = pq.top().second;
		pq.pop();

		if(revDist[minNode] < cost){
			continue;
		}
		for(int j = 0; j < adj[minNode].size(); j++){
			int adjNode = adj[minNode][j].second;
			int temp = cost + adj[minNode][j].first;
			if(revDist[adjNode] >= temp){
				revDist[adjNode] = temp;
				pq.push(make_pair(-temp, adjNode));
			}
		}
	}
	// party -> node
}
int main() {
	int numNode;
	int numEdge;
	int partyNode;
	cin >> numNode >> numEdge >> partyNode;
	for(int i = 0; i < numEdge; i++){
		int start; int end; int weight;
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(weight, end));
		revAdj[end].push_back(make_pair(weight, start));
	}
	dijkstra(partyNode);

	int max = 0;
	for(int i = 0; i < 1001; i++){
		if(max < dist[i] + revDist[i]){
			max = dist[i] + revDist[i];
		}
	}
	cout << max;
}
