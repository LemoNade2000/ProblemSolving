#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int V, E;
vector<int> adj[100001];
bool visited[100001];
int visitOrder[100001];
int cnt;
vector<pii> ans;

int cmp(pii a, pii b){
	if(a.first < b.first) return true;
	else if(a.first == b.first){
		return a.second <= b.second;
	}
	else if(a.first > b.first){
		return false;
	}
}

int dfs(int node, int prevNode){
	visitOrder[node] = cnt;
	cnt++;
	visited[node] = true;
	int ret = visitOrder[node];
	for(int i = 0; i < adj[node].size(); i++){
		int nextNode = adj[node][i];
		if(nextNode == prevNode){
			continue;
		}
		if(visited[nextNode] == true){
			ret = min(visitOrder[nextNode], ret);
			continue;
		}
		int maxPrevNode = dfs(nextNode, node);
		if(maxPrevNode > visitOrder[node]){
			ans.push_back(make_pair(min(node, nextNode), max(node, nextNode)));
		}
		ret = min(maxPrevNode, ret);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E;
	for(int i = 0; i < E; i++){
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		adj[end].push_back(start);
	}
	cnt = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= V; i++){
		if(visited[i] == false){
			dfs(i, 0);
		}
	}
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end(), cmp);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}
