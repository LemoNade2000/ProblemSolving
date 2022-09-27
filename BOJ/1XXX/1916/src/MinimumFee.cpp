#include <iostream>
#include <limits.h>
using namespace std;

long long int dist[1001];
int graph[1001][1001];
bool visited[1001];

int dijkstra(int numNode, int start, int end){
	dist[start] = 0;
	for(int i = 0; i < numNode; i++){
		int minNode = -1;
		long long int min = LLONG_MAX;
		for(int j = 1; j <= numNode; j++){
			if(visited[j] == false && dist[j] < min){
				min = dist[j];
				minNode = j;
			}
		}
		if(minNode == -1){
			return 0;
		}
		if(minNode == end){
			return 0;
		}
		visited[minNode] = true;
		for(int j = 1; j <= numNode; j++){
			if(visited[j] == false
			&& graph[minNode][j] != INT_MAX
			&& dist[j] > dist[minNode] + graph[minNode][j]){
				dist[j] = dist[minNode] + graph[minNode][j];
			}
		}
	}
	return 0;
}

int main() {
	int numNode, numEdge;
	cin >> numNode >> numEdge;
	for(int i = 1; i <= numNode; i++){
		for(int j = 1; j <= numNode; j++){
			graph[i][j] = INT_MAX;
		}
	}
	for(int i = 0; i < 1001; i++){
		dist[i] = LLONG_MAX; visited[i] = false;
	}
	for(int i = 0; i < numEdge; i++){
		int start, end, fee;
		cin >> start >> end >> fee;
		if(graph[start][end] > fee){
			graph[start][end] = fee;
		}
	}
	int departure, destination;
	cin >> departure >> destination;
	dijkstra(numNode, departure, destination);
	cout << dist[destination];
}
