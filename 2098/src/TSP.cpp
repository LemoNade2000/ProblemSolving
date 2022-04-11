#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define MAX 999999999;

int numCity;
int visited;
int adj[16][16];

int dp[16][(1 << 16) - 1];

int min(int a, int b){
	if(a < b){
		return a;
	}
	else return b;
}

int TSP(int city, int bit){
	int ret = dp[city][bit];
	if(ret != 0)
		return ret;
	if(bit == (1 << numCity) - 1){
		if(adj[city][0] != 0){
			return adj[city][0];
		}
		else return MAX;
	}
	ret = MAX;
	for(int i = 0; i < numCity; i++){
		if(adj[city][i] == 0 || (bit & (1 << i))){
			continue;
		}
		ret = min(ret, adj[city][i] + TSP(i, bit | (1 << i)));
	}
	dp[city][bit] = ret;
	return ret;
}

int main() {
	cin.tie(NULL);
	cin >> numCity;
	for(int i = 0; i < numCity; i++){
		for(int j = 0; j < numCity; j++){
			int weight;
			cin >> weight;
			adj[i][j] = weight;
		}
	}
	cout << TSP(0, 1);
}
