#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int,int>> adj[10001];
vector<pair<int,int>> revAdj[10001];
int inDegree[10001];
int revDegree[10001];
int dist[10001];
queue<int> q;
int numPath[10001];
vector<int> used;
bool visited[10001];

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(weight, end));
		revAdj[end].push_back(make_pair(weight, start));
		inDegree[end]++;
		revDegree[start]++;
	}
	int departNode, destNode;
	cin >> departNode >> destNode;
	q.push(departNode);
	dist[departNode] = 0;
	int ansNum = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int i = 0; i < adj[node].size(); i++){
			int weight = adj[node][i].first;
			int dest = adj[node][i].second;
			dist[dest] = max(dist[dest], dist[node] + weight);
			--inDegree[dest];
			if(inDegree[dest] == 0){
				q.push(dest);
			}
		}
	}
	q.push(destNode);
	int ans = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int i = 0; i < revAdj[node].size(); i++){
			int weight = revAdj[node][i].first;
			int depart = revAdj[node][i].second;
			if(dist[node] == dist[depart] + weight){
				ans++;
				if(visited[depart] == false){
					q.push(depart);
					visited[depart] = true;
				}
			}
		}
	}
	cout << dist[destNode] << "\n" << ans;
}
