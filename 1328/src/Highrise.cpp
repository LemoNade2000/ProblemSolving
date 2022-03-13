#include <iostream>
using namespace std;

int main() {
	int N, L, R;
	cin >> N >> L >> R;
	unsigned long long memo[N+1][L+1][R+1];

	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= L; j++){
			for(int k = 0; k <= R; k++){
				memo[i][j][k] = 0;
				if((i == j && k == 1 )||(i == k && j == 1)){
					memo[i][j][k] = 1;
				}
			}
		}
	}

	memo[1][1][1] = 1;
	for(int i = 2; i <= N; i++){
		for(int j = 1; j <= L; j++){
			for(int k = 1; k <= R; k++){
				memo[i][j][k] = (memo[i-1][j-1][k] + memo[i-1][j][k-1] + (i-2) * memo[i-1][j][k]) % 1000000007;
			}
		}
	}
	cout << memo[N][L][R] % 1000000007;
}
