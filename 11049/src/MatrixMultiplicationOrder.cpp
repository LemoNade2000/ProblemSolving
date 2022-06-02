#include <bits/stdc++.h>

using namespace std;

int N;
int dp[501][501];
vector<pair<int, int>> mat;

int main() {
	cin >> N;
	for(int i = 0; i < N; i++){
		int start, end;
		cin >> start >> end;
		mat.push_back(make_pair(start, end));
	}
//	memset(dp, 50, sizeof(dp));
	for(int i = 0; i < N; i++){
		dp[i][i] = 0;
	}
	for(int i = 0; i < N - 1; i++){
		dp[i][i + 1] = mat[i].first * mat[i].second * mat[i + 1].second;
	}
	for(int i = 2; i < mat.size(); i++){
		for(int j = 0; j + i < mat.size(); j++){
			int sum;
			dp[j][j + i] = INT_MAX;
			for(int k = 0; k < i; k++){
				sum = dp[j][j + k] + dp[j + k + 1][j + i] + mat[j].first * mat[j + k].second * mat[j + i].second;
				if(dp[j][i + j] > sum){
					dp[j][i + j] = sum;
				}
			}
		}
	}
	cout << dp[0][N - 1];
}
