#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> adj[100001];
int dist[100001];
bool visited[100001];

void dfs(int start, int distance){
	for(int i = 0; i < adj[start].size(); i++){
		int nextNode = adj[start][i].second;
		int nextDist = adj[start][i].first;
		if(!visited[nextNode]){
			visited[nextNode] = true;
			dist[nextNode] = distance + nextDist;
			dfs(nextNode, dist[nextNode]);
		}
	}
}

int main() {
	int numNodes;
	cin >> numNodes;
	for(int i = 1; i <= numNodes; i++){
		dist[i] = 0;
		visited[i] = false;
	}
	for(int i = 1; i < numNodes; i++){
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(weight, end));
		adj[end].push_back(make_pair(weight, start));
	}
	visited[1] = true;
	dfs(1,0);
	int temp = 0;
	int tempNode = 0;
	for(int i = 1; i <= numNodes; i++){
		if(temp < dist[i]){
			temp = dist[i];
			tempNode = i;
		}
		dist[i] = 0;
		visited[i] = false;
	}
	visited[tempNode] = true;
	dfs(tempNode,0);
	temp = 0;
	for(int i = 1; i <= numNodes; i++){
		if(temp < dist[i]){
			temp = dist[i];
			tempNode = i;
		}
	}
	cout << temp;
}
