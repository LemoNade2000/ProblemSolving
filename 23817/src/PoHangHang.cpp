#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
string str[4];
int dp[(1 << 20)];
int distanceDP[4][1000][21];

int solve(int row, int col, int bitStatus){
}

int generateGraph(int row, int col, int destination){
	if(distanceDP[row][col][destination] != -1){
		return distanceDP[row][col][destination];
	}

}

int main() {
	cin >> N >> M;
	pair<int, int> start;
	for(int i = 0; i < N; i++){
		cin >> str[i];
		for(int j = 0; j < M; j++){
			if(str[i][j] == 'S'){
				start.first = i;
				start.second = j;
			}
		}
	}
	memset(dp, -1, sizeof(dp));

	int ans = solve(start.first, start.second, 0);
}
