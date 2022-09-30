#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[10001];
priority_queue<pair<int, int>> pq;

int result;
bool visited[10001];

int prim(){
	visited[1] = true;
	for(int i = 0; i < adj[1].size(); i++){
		pq.push(make_pair(-adj[1][i].first, adj[1][i].second));
	}
	while(!pq.empty()){
		int end = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		if(visited[end] == false){
			result += weight;
			visited[end] = true;
			for(int i = 0; i < adj[end].size(); i++){
				pq.push(make_pair(-adj[end][i].first, adj[end][i].second));
			}
		}
	}
    return 0;
}

int main() {
	int numNode, numEdge;
	cin >> numNode >> numEdge;
	for(int i = 0; i < numEdge; i++){
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(weight, end));
		adj[end].push_back(make_pair(weight, start));
	}
	result = 0;
	for(int i = 0; i <= numNode; i++){
		visited[i] = false;
	}
	prim();
	cout << result;
}
