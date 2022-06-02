#include <iostream>
#include <cstring>

using namespace std;

int N;
int adj[15][15];
int memo[15][(1 << 15)][10] = {0};

int max(int a, int b){
	if(a > b){
		return a;
	}
	else return b;
}

int solve(int node, int visited, int last_price){
	if(memo[node][visited][last_price] != 0){
		return memo[node][visited][last_price];
	}
	if(visited == (1<<N) - 1){
		return 1;
	}
	int result = 1;
	for(int dest = 0; dest < N; dest++){
		if(visited & (1 << dest)){
			continue;
		}
		if(adj[node][dest] >= last_price){
			result = max(result, 1 + solve(dest, (visited | (1 << dest)), adj[node][dest]));
		}
	}
	memo[node][visited][last_price] = result;
	return result;
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		for(int j = 0; j < N; j++){
		adj[i][j] = str[j] - '0';
		}
	}
	cout << solve(0, (1 << 0), 0);
	return 0;
}
