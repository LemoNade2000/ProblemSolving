#include <iostream>
#include <cstring>

using namespace std;

int max(int a, int b){
	if(a >= b) return a;
	else return b;
}

int main() {

	int numObj; int maxWeight;
	cin >> numObj >> maxWeight;
	int weight[numObj];
	int value[numObj];
	for(int i = 0; i < numObj; i++){
		cin >> weight[i] >> value[i];
	}
	int dp[numObj][maxWeight + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i <= maxWeight; i++){
		if(i >= weight[0]){
			dp[0][i] = value[0];
		}
	}
	for(int i = 1; i < numObj; i++){
		for(int j = 0; j <= maxWeight; j++){
			dp[i][j] = dp[i-1][j];
			if(j >= weight[i]){
				dp[i][j] = max(dp[i-1][j-weight[i]] + value[i], dp[i-1][j]);
			}
		}
	}
	cout << dp[numObj-1][maxWeight];
}
