#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[32001];
priority_queue <pair<int, int>> pq;
int inDegree[32001] = {0};
bool solved[32001];
queue<int> order;

int solve(int numNode){
	while(!pq.empty()){
		int weight = -pq.top().first;
		int start = pq.top().second;
		order.push(start);
		solved[start] = true;
		pq.pop();
		for(int i = 0; i < adj[start].size(); i++){
			int end = adj[start][i].second;
			int val = -adj[start][i].first;
			--inDegree[end];
			if(inDegree[end] == 0){
				pq.push(make_pair(val, end));
			}
		}
	}
	return 0;
}

int main() {
	int numNode, numEdge;
	cin >> numNode >> numEdge;
	for(int i = 0; i < numEdge; i++){
		int start, end;
		cin >> start >> end;
		adj[start].push_back(make_pair(end, end));
		inDegree[end]++;
	}
	for(int i = 1; i <= numNode; i++){
		solved[i] = false;
	}

	for(int i = 1; i <= numNode; i++){
		if(inDegree[i] == 0 && solved[i] == false){
			pq.push(make_pair(-i, i));
		}
	}
	solve(numNode);
	for(int i = 0; i < numNode; i++){
		cout << order.front() << " ";
		order.pop();
	}

}
