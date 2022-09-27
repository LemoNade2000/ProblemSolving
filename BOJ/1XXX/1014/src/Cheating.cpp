#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 987654321

int N, M;
string seat[10];
int dp[10][(1<<10)];
vector<pair<int, int>> seatCombinations; // first = seatBeat, second = count;

bool validSeat(int a){
	bool curr, next;
	curr = a % 2;
	for(int i = 0; i < M-1; i++){
		a /= 2;
		next = a % 2;
		if(!(curr ^ next) && curr == true){ // same adjacent bit
			return false;
		}
		curr = next;
	}
	return true;
}

bool seatCheck(int seatBit, int line){
	if(line >= N){
		return true;
	}
	for(int i = 0; i < M; i++){
		if(seat[line][i] == 'x'){
			if(seatBit & (1 << i)){
				return false;
			}
		}
	}
	return true;
}

bool collateralCheck(int prevSeatBit, int nextSeatBit){
	for(int i = 0; i < M; i++){
		if(nextSeatBit & (1 << i)){ // sitting in next line
			if(i != 0){ // not right-most seat
				if(prevSeatBit & (1 << (i - 1))){
					return false; // seating in diagonal-right
				}
			}
			if(i != M - 1){ // not left-most seat
				if(prevSeatBit & (1 << (i + 1))){
					return false;
				}
			}
		}
	}
	return true;
}

int dfs(int line, int seatBit){
	if(dp[line][seatBit] != -1){
		return dp[line][seatBit];
	}
	if(line >= (N - 1)){
		return 0;
	}
	int result = -1;
	for(int i = 0; i < seatCombinations.size(); i++){
		int nextSeatBit = seatCombinations[i].first;
		int nextSeatCount = seatCombinations[i].second;
		if(collateralCheck(seatBit, nextSeatBit) && seatCheck(nextSeatBit, line+1)){ // if the combination doesn't collide with the current one and next line
			result = max(result, nextSeatCount + dfs(line+1, nextSeatBit));
		}
	}
	dp[line][seatBit] = result;
	return result;
}

int solve(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> seat[i];
	}
	seatCombinations.clear();
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < (1 << M); i++){
		if(validSeat(i)){
			seatCombinations.push_back(make_pair(i, __builtin_popcount(i)));
		}
	}
	int answer = 0;
	for(int i = 0; i < seatCombinations.size(); i++){
		int seatBit = seatCombinations[i].first;
		int seatCount = seatCombinations[i].second;
		if(seatCheck(seatBit, 0)){
			answer = max(answer, seatCount + dfs(0, seatBit));
		}
	}
	cout << answer;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; tc++){
		solve();
		cout << "\n";
	}
}
