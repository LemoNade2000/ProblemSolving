#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[100001];
priority_queue<pair<int, int>> pq;
long long int costSum;
bool visited[100001];
vector<int> vNodes;
int maxEdge;

int prim(int node, int depart){
	costSum = 0;
	pq.push(make_pair(0, depart));
	while(!pq.empty()){
		int cost = -pq.top().first;
		int minNode = pq.top().second;
		pq.pop();

		if(visited[minNode] == true){
			continue;
		}
		vNodes.push_back(minNode);
		visited[minNode] = true;
		costSum += cost;
		if(cost > maxEdge) maxEdge = cost;
		if(vNodes.size() == node) break;
		for(int j = 0; j < adj[minNode].size(); j++){
			int adjNode = adj[minNode][j].second;
			int weight = adj[minNode][j].first;
			if(visited[adjNode] == true){
				continue;
			}
			pq.push(make_pair(-weight, adjNode));
		}
	}
	return 0;
}

int main() {
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(weight, end));
		adj[end].push_back(make_pair(weight, start));
	}
	maxEdge = 0;
	prim(N, 1);
	cout << costSum - maxEdge;
}
