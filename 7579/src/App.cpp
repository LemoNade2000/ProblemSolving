#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> memory;
vector<int> cost;
int costSum;
int dp[101][10001];

int max(int a, int b){
	if(a > b){
		return a;
	}
	else return b;
}

int main() {
	cin >> N >> M;
	memory.push_back(0);
	for(int i = 0; i < N; i++){
		int mem;
		cin >> mem;
		memory.push_back(mem);
	}
	cost.push_back(0);
	for(int i = 0; i < N; i++){
		int c;
		cin >> c;
		cost.push_back(c);
		costSum += c;
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= costSum; j++){
			if(j - cost[i] >= 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + memory[i]);
			}
			dp[i][j] = max(dp[i-1][j], dp[i][j]);
		}
	}
	for(int i = 0; i <= costSum; i++){
		if(dp[N][i] >= M){
			cout << i;
			return 0;
		}
	}
}
