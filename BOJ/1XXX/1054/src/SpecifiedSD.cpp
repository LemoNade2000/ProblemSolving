
#include <iostream>
#include <limits.h>

long long int shortestDist(int node,long long int *graph, int start, int end){
	long long int dist[node];
	bool visited[node];
	for(int i = 0; i < node; i++){
		dist[i] = LLONG_MAX; visited[i] = false;
	}
	dist[start] = 0;
	for(int i = 0; i < node; i++){
		int minimumNode;
		int minNode = -1;
		long long int min = LLONG_MAX;
		for(int j = 0; j < node; j++){
			if(visited[j] == false && dist[j] < min){
				min = dist[j];
				minNode = j;
			}
		}
		if(minNode == -1){
			break;
		}
		visited[minNode] = true;
		for(int j = 0; j < node; j++){
			if(visited[j] == false && *(graph + (minNode * node) + j) != LLONG_MAX && dist[j] > dist[minNode] + *(graph + (minNode * node) + j)){
				dist[j] = dist[minNode] + *(graph + (minNode * node) + j);
			}
		}
	}
	return dist[end];
}

int main() {
	int nodeNum, edgeNum;
	std::cin >> nodeNum >> edgeNum;
	long long int graph[nodeNum][nodeNum];
	for(int i = 0; i < nodeNum; i++){
		for(int j = 0; j < nodeNum; j++){
			graph[i][j] = LLONG_MAX;
			if(i == j){
				graph[i][j] = 0;
			}
		}
	}
	for(int i = 0; i < edgeNum; i++){
		int start, end;
		int weight;
		std::cin >> start >> end;
		std::cin >> weight;
		graph[start-1][end-1] = weight;
		graph[end-1][start-1] = weight;
	}
	int dest1, dest2;
	std::cin >> dest1 >> dest2;
	long long int OA = shortestDist(nodeNum,(long long int *)graph, 0, dest1-1);
	long long int OB = shortestDist(nodeNum,(long long int *)graph, 0, dest2-1);
	long long int ON = shortestDist(nodeNum,(long long int *)graph, 0, nodeNum-1);
	long long int AB = shortestDist(nodeNum,(long long int *)graph, dest1-1, dest2-1);
	long long int AN = shortestDist(nodeNum,(long long int *)graph, dest1-1, nodeNum-1);
	long long int BN = shortestDist(nodeNum,(long long int *)graph, dest2-1, nodeNum-1);



	long long int min = LLONG_MAX;
	if(min > (2*OA + OB + BN) && (2*OA + OB + BN) >= 0) min = (2*OA + OB + BN);
	if(min > (OA + AB + BN) && (OA + AB + BN) >= 0) min = (OA + AB + BN);
	if(min > (2*OB + OA + AN) && (2*OB + OA + AN) >= 0) min = (2*OB + OA + AN);
	if(min > (OB + AB + AN) && (OB + AB + AN) >= 0) min = (OB + AB + AN);
	if(min > (2*OA + 2*OB + ON) && (2*OA + 2*OB + ON) >= 0) min = (2*OA + 2*OB + ON);

	if(ON == LLONG_MAX || OB == LLONG_MAX || OA == LLONG_MAX){
		std::cout << "-1";
		return 0;
	}

	std::cout << min;
	return 0;
}
