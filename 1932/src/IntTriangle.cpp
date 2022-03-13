
#include <iostream>
using namespace std;

int triangle[501][501];
int dp[501][501];

int max(int a, int b){
	if(a >= b){
		return a;
	}
	else return b;
}

int main() {
	int size;
	cin >> size;
	for(int i = 0; i < size; i++){
		for(int j = 0; j <= i; j++){
			cin >> triangle[i][j];
			dp[i][j] = 0;
		}
	}
	int temp = 0;
	dp[0][0] = triangle[0][0];
	for(int i = 1; i < size; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0){
				dp[i][j] = dp[i-1][0] + triangle[i][j];
			}
			else if(j == i){
				dp[i][j] = dp[i-1][j-1] + triangle[i][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
			}
		}
	}
	for(int i = 0; i < size; i++){
		if(temp < dp[size-1][i]){
			temp = dp[size-1][i];
		}
	}
	cout << temp;
}
