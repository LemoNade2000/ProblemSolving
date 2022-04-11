#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int buildTime[1001];
int inDegree[1001];
int dist[1001];
queue<int> q;


int main() {
	int testCase;
	cin >> testCase;
	for(int x = 0; x < testCase; x++){
		vector<pair<int, int>> adj[1001];
		int numNode, numEdge;
		cin >> numNode >> numEdge;
		for(int i = 1; i <= numNode; i++){
			cin >> buildTime[i];
			inDegree[i] = 0;
			dist[i] = 0;
		}
		for(int i = 0; i < numEdge; i++){
			int pre, post;
			cin >> pre >> post;
			adj[pre].push_back(make_pair(buildTime[pre], post));
			inDegree[post]++;
		}
		int obj;
		cin >> obj;
		for(int i = 1; i <= numNode; i++){
			if(inDegree[i] == 0){
				q.push(i);
			}
		}
		while(!q.empty()){
			int node;
			node = q.front();
			q.pop();
			for(int i = 0; i < adj[node].size(); i++){
				int dest = adj[node][i].second;
				int time = adj[node][i].first;
				--inDegree[dest];
				if(inDegree[dest] == 0){
					q.push(dest);
				}
				if(dist[dest] < dist[node] + time){
					dist[dest] = dist[node] + time;
				}

			}
		}
		cout << dist[obj] + buildTime[obj] << "\n";
	}
}
