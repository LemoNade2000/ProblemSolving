#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N;
int parent[100001][21]; // Nth node's 2^M'th parent
int minRoad[100001][21];
int maxRoad[100001][21];
vector<pii> adj[100001];
bool visited[100001];
int depth[100001];

void dfs(int start, int currDepth){
	visited[start] = true;
	depth[start] = currDepth;
	for(int i = 0; i < adj[start].size(); i++){
		int dest = adj[start][i].first;
		if(visited[dest] == false){
			parent[dest][0] = start;
			minRoad[dest][0] = adj[start][i].second;
			maxRoad[dest][0] = adj[start][i].second;
			dfs(dest, currDepth + 1);
		}
	}
	return;
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

void memo(){
	for(int i = 1; i < 21; i++){
		for(int node = 2; node <= N; node++){
			int prevParent = parent[node][i-1];
			parent[node][i] = parent[prevParent][i-1];
			minRoad[node][i] = min(minRoad[node][i - 1], minRoad[prevParent][i - 1]);
			maxRoad[node][i] = max(maxRoad[node][i - 1], maxRoad[prevParent][i - 1]);
			if(parent[prevParent][i-1] == 0){
				continue;
			}
		}
	}
}

pii lca(int firstNode, int secondNode){
	int maximum = 0;
	int minimum = 1000001;
	if(depth[secondNode] > depth[firstNode]){
		int temp = secondNode;
		secondNode = firstNode;
		firstNode = temp;
	}
	for(int i = 21; i >= 0; i--){
		int diff = 1 << i;
		if(depth[firstNode] - depth[secondNode] >= diff){
			minimum = min(minimum, minRoad[firstNode][i]);
			maximum = max(maximum, maxRoad[firstNode][i]);
			firstNode = parent[firstNode][i];
		}
	}
	if(firstNode == secondNode) return make_pair(minimum, maximum);
	else{
		for(int i = 20; i >= 0; i--){
			if(parent[firstNode][i] == parent[secondNode][i]){
				continue;
			}
			minimum = min(minimum, minRoad[firstNode][i]);
			maximum = max(maximum, maxRoad[firstNode][i]);
			firstNode = parent[firstNode][i];
			minimum = min(minimum, minRoad[secondNode][i]);
			maximum = max(maximum, maxRoad[secondNode][i]);
			secondNode = parent[secondNode][i];
		}
	}
	minimum = min(minimum, minRoad[firstNode][0]);
	maximum = max(maximum, maxRoad[firstNode][0]);
	minimum = min(minimum, minRoad[secondNode][0]);
	maximum = max(maximum, maxRoad[secondNode][0]);
	return make_pair(minimum, maximum);
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
		pii ans = lca(start, end);
		cout << ans.first << " " << ans.second <<"\n";
	}
}
