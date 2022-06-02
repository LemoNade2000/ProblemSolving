#include <bits/stdc++.h>

using namespace std;

int N;
int parent[100001][21]; // Nth node's 2^M'th parent
vector<int> adj[100001];
bool visited[100001];
int depth[100001];

void dfs(int start, int currDepth){
	visited[start] = true;
	depth[start] = currDepth;
	for(int i = 0; i < adj[start].size(); i++){
		int dest = adj[start][i];
		if(visited[dest] == false){
			parent[dest][0] = start;
			dfs(dest, currDepth + 1);
		}
	}
}

void memo(){
	for(int i = 1; i < 21; i++){
		for(int node = 1; node <= N; node++){
			int prevParent = parent[node][i-1];
			parent[node][i] = parent[prevParent][i-1];
			if(parent[prevParent][i-1] == 0){
				continue;
			}
		}
	}
}

int lca(int firstNode, int secondNode){
	if(depth[secondNode] > depth[firstNode]){
		int temp = secondNode;
		secondNode = firstNode;
		firstNode = temp;
	}
	for(int i = 21; i >= 0; i--){
		int diff = 1 << i;
		if(depth[firstNode] - depth[secondNode] >= diff){
			firstNode = parent[firstNode][i];
		}
	}
	if(firstNode == secondNode) return firstNode;
	else{
		for(int i = 20; i >= 0; i--){
			if(parent[firstNode][i] == parent[secondNode][i]){
				continue;
			}
			firstNode = parent[firstNode][i];
			secondNode = parent[secondNode][i];
		}
	}
	return firstNode[parent][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i = 1; i < N; i++){
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		adj[end].push_back(start);
	}
	dfs(1, 0);
	memo();
	int M;
	int start, end;

	cin >> M;
	for(int tc = 0; tc < M; tc++){
		cin >> start >> end;
		cout << lca(start, end) <<"\n";
	}

}
