#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[1000001];
int dp[1000001][2];
bool visited[1000001];

int solve(int node){
	visited[node] = true;
	dp[node][1] = 1;
	for(int i = 0; i < adj[node].size(); i++){
		int child = adj[node][i];
		if(visited[child] == false){
			solve(child);
			dp[node][1] += min(dp[child][0], dp[child][1]);
			dp[node][0] += dp[child][1];
		}
	}
	return 0;
}

int main() {
	cin >> N;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i < N; i++){
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		adj[end].push_back(start);
	}
	solve(1);
	cout << min(dp[1][0], dp[1][1]);
}
