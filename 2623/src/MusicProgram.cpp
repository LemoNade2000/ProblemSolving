#include <bits/stdc++.h>

using namespace std;

int N, M;
int adj[1001][1001];
int inDegree[1001];
queue<int> q;
queue<int> ans;

int main() {
	cin >> N >> M;
	memset(adj, 0, sizeof(adj));
	memset(inDegree, 0, sizeof(inDegree));
	for(int i = 0; i < M; i++){
		int numSing;
		cin >> numSing;
		int prev, curr;
		for(int j = 0; j < numSing; j++){
			int singer;
			cin >> singer;
			if(j == 0){
				prev = singer;
				continue;
			}
			else if(j != 0){
				curr = singer;
				if(adj[prev][curr] != 1){
					inDegree[curr]++;
					adj[prev][curr] = 1;
				}
				prev = singer;
			}
		}
	}
	for(int i = 1; i <= N; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int i = 1; i <= N; i++){
			if(adj[node][i] == 1){
				--inDegree[i];
				if(inDegree[i] == 0){
					q.push(i);
				}
			}
		}
		ans.push(node);
	}
	if(ans.size() == N){
		for(int i = 0; i < N; i++){
			cout << ans.front() << "\n";
			ans.pop();
		}
	}
	else {
		cout << 0;
	}

	return 0;
}
