#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[32001];
int inDegree[32001] = {0};
queue<int> q;
queue<int> ans;
int main() {
	int numNode, numEdge;
	cin >> numNode >> numEdge;
	for(int i = 0; i < numEdge; i++){
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		inDegree[end]++;
	}
	for(int i = 1; i <= numNode; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		ans.push(node);
		for(int i = 0; i < adj[node].size(); i++){
			inDegree[adj[node][i]]--;
			if(inDegree[adj[node][i]] == 0){
				q.push(adj[node][i]);
			}
		}
	}
	for(int i = 0; i < numNode; i++){
		cout << ans.front() << " ";
		ans.pop();
	}
}
