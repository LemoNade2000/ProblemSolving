#include <bits/stdc++.h>

using namespace std;

int TC, N;
vector<int> adj;
bool visited[100001];
vector<int> route;
vector<int> team;

int dfs(int node){
	visited[node] = true;
	route.push_back(node);
	if(visited[adj[node]] == true){
		for(int i = 0; i < route.size(); i++){
			if(adj[node] == route[i]){
				for(; i < route.size(); i++){
					team.push_back(route[i]);
				}
				route.clear();
				return 0;
			}
		}
		route.clear();
	}
	else{
		dfs(adj[node]);
	}
	return 0;
}

int solve(){
	cin >> N;
	adj.clear();
	team.clear();
	adj.push_back(-1);
	for(int i = 0; i < N; i++){
		int pref;
		cin >> pref;
		adj.push_back(pref);
	}
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= N; i++){
		if(visited[i] == true){
			continue;
		}
		dfs(i);
	}
	cout << N - team.size() << "\n";
	return 0;
}

int main() {
	cin >> TC;
	for(int tc = 0; tc < TC; tc++){
		solve();
	}
}
