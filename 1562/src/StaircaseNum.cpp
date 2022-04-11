#include <iostream>
using namespace std;

#define MOD 1000000000
int dp[101][10][1 << 10];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= 9; i++){
		dp[1][i][1 << i] = 1;
	}
	int allUse = (1 << 10) - 1;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < (1 << 10); k++){
				if(j == 0){
					dp[i][j][k | (1 << 0)] = dp[i][j][k | (1 << 0)] + dp[i-1][1][k] % MOD;
				}
				else if(j == 9){
					dp[i][j][k | (1 << 9)] = dp[i][j][k | (1 << 9)] + dp[i-1][8][k] % MOD;
				}
				else{
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i-1][j-1][k]) % MOD;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i-1][j+1][k]) % MOD;
				}
			}
		}
	}
	int ans;
	for(int i = 0; i < 10; i++){
		ans += dp[n][i][allUse];
	}
	cout << ans;
}
