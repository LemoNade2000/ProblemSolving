#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<int> adj[10001];
bool visited[10001];
int visitOrder[10001];
bool isCut[10001];
int cnt;
queue<int> ans;

int dfs(int node, bool isRoot){
	visitOrder[node] = cnt;
	cnt++;
	visited[node] = true;
	int childCnt = 0;
	int ret = visitOrder[node];
	for(int i = 0; i < adj[node].size(); i++){
		int nextNode = adj[node][i];
		if(visited[nextNode] == true){
			ret = min(visitOrder[nextNode], ret);
			continue;
		}
		childCnt++;
		int maxPrevNode = dfs(nextNode, false);
		if(isRoot == false && maxPrevNode >= visitOrder[node]){
			isCut[node] = true;
		}
		ret = min(maxPrevNode, ret);
	}
	if(isRoot == true && childCnt >= 2){
		isCut[node] = true;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E;
	for(int i = 1; i <= V; i++){
		visited[i] = false;
		isCut[i] = false;
	}
	cnt = 1;
	for(int i = 0; i < E; i++){
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		adj[end].push_back(start);
	}
	for(int i = 1; i <= V; i++){
		if(visited[i] == false){
			dfs(i, true);
		}
	}
	for(int i = 1; i <= V; i++){
		if(isCut[i] == true){
			ans.push(i);
		}
	}
	cout << ans.size() << "\n";
	while(!ans.empty()){
		cout << ans.front() << " ";
		ans.pop();
	}
}
