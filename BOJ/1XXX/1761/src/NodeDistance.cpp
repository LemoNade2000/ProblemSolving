#include <bits/stdc++.h>

using namespace std;

int N;
int dist[40001][16];
int parent[40001][16]; // distance from Nth node to 2^Mth parent
vector<pair<int, int>> adj[40001];
bool visited[40001];
int depth[40001];

void dfs(int start, int currDepth){
	visited[start] = true;
	depth[start] = currDepth;
	for(int i = 0; i < adj[start].size(); i++){
		int dest = adj[start][i].first;
		int weight = adj[start][i].second;
		if(visited[dest] == false){
			dist[dest][0] = weight;
			parent[dest][0] = start;
			dfs(dest, currDepth + 1);
		}
	}
}

void memo(){
	for(int i = 1; i < 16; i++){
		for(int node = 1; node <= N; node++){
			int prevParent = parent[node][i-1];
			parent[node][i] = parent[prevParent][i-1];
			if(parent[prevParent][i-1] == 0){
				continue;
			}
			dist[node][i] = dist[node][i-1] + dist[prevParent][i-1];
		}
	}
}

int lca(int firstNode, int secondNode){
	if(depth[secondNode] > depth[firstNode]){
		int temp = secondNode;
		secondNode = firstNode;
		firstNode = temp;
	}
	int length = 0;
	for(int i = 15; i >= 0; i--){
		int diff = 1 << i;
		if(depth[firstNode] - depth[secondNode] >= diff){
			length += dist[firstNode][i];
			firstNode = parent[firstNode][i];
		}
	}
	if(firstNode == secondNode) return length;
	else{
		for(int i = 15; i >= 0; i--){
			if(parent[firstNode][i] == parent[secondNode][i]){
				continue;
			}
			length += dist[firstNode][i] + dist[secondNode][i];
			firstNode = parent[firstNode][i];
			secondNode = parent[secondNode][i];
		}
		length += dist[firstNode][0] + dist[secondNode][0];
	}
	return length;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i = 1; i < N; i++){
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(end, weight));
		adj[end].push_back(make_pair(start, weight));
	}
	dfs(1, 0);
	memo();
	int M;
	int start, end;

	cin >> M;
	for(int tc = 0; tc < M; tc++){
		cin >> start >> end;
		cout << lca(start, end) << "\n";
	}

}
