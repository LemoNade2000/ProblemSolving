#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<int> adj[10001];
vector<int> revAdj[10001];
vector<int> SCC[10001];
stack<int> s;
bool visited[10001];
int sccNum = 0;

int comp(vector<int> a, vector<int> b){
	return a[0] < b[0];
}

int dfs(int node){
	visited[node] = true;
	for(int i = 0; i < adj[node].size(); i++){
		int next = adj[node][i];
		if(visited[next] == false){
			dfs(next);
		}
	}
	s.push(node);
	return 0;
}

int dfs2(int node){
	visited[node] = true;
	SCC[sccNum].push_back(node);
	for(int i = 0; i < revAdj[node].size(); i++){
		int next = revAdj[node][i];
		if(visited[next] == false){
			dfs2(next);
		}
	}
	return 0;
}

int main() {
	memset(visited, false, sizeof(visited));
	cin >> V >> E;
	for(int i = 0; i < E; i++){
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		revAdj[end].push_back(start);
	}
	for(int i = 1; i <= V; i++){
		if(visited[i] == false){
			dfs(i);
		}
	}
	memset(visited, false, sizeof(visited));
	while(!s.empty()){
		int node = s.top();
		s.pop();
		if(visited[node] == false){
			++sccNum;
			dfs2(node);
		}
	}

	cout << sccNum << "\n";
	for(int i = 1; i <= sccNum; i++){
		sort(SCC[i].begin(), SCC[i].end());
	}
	sort(SCC+1, SCC+1+sccNum, comp);
	for(int i = 1; i <= sccNum; i++){
//		sort(SCC[i].begin(), SCC[i].end());
		for(int j = 0; j < SCC[i].size(); j++){
			cout << SCC[i][j] << " ";
 		}
		cout << "-1\n";
	}
	return 0;
}
