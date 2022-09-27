#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N, W;
vector<pii> cases;
int dp[1001][1001];
vector<bool> car;

int solve(int car1Last, int car2Last, int caseNum, int dist){
	int row1, col1, row2, col2, caseRow, caseCol;
	if(caseNum > W){
		return 0;
	}
	if(dp[car1Last][car2Last] != 0){
		return dp[car1Last][car2Last];
	}
	if(car1Last == 0){
		row1 = 1;
		col1 = 1;
	}
	else{
		row1 = cases[car1Last].first;
		col1 = cases[car1Last].second;
	}
	if(car2Last == 0){
		row2 = N;
		col2 = N;
	}
	else{
		row2 = cases[car2Last].first;
		col2 = cases[car2Last].second;
	}
	caseRow = cases[caseNum].first;
	caseCol = cases[caseNum].second;
	int dist1 = abs(row1 - caseRow) + abs(col1 - caseCol);
	int dist2 = abs(row2 - caseRow) + abs(col2 - caseCol);
	int car1 = dist1 + solve(caseNum, car2Last, caseNum + 1, dist + dist1);
	int car2 = dist2 + solve(car1Last, caseNum, caseNum + 1, dist + dist2);
	return dp[car1Last][car2Last] = min(car1, car2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> W;
	cases.resize(W + 1);
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= W; i++){
		int row, col;
		cin >> row >> col;
		cases[i].first = row;
		cases[i].second = col;
	}
	cout << solve(0, 0, 1, 0) << "\n";
	int row1, col1, row2, col2, caseRow, caseCol;
	row1 = 1; col1 = 1;
	row2 = N; col2 = N;
	int left = 0;
	int right = 0;
	for(int caseNum = 1; caseNum <= W; caseNum++){
		caseRow = cases[caseNum].first;
		caseCol = cases[caseNum].second;
		int dist1 = abs(row1 - caseRow) + abs(col1 - caseCol);
		int dist2 = abs(row2 - caseRow) + abs(col2 - caseCol);
		if(dp[left][right] == dist1 + dp[caseNum][right]){
			cout << "1\n";
			left = caseNum;
			row1 = caseRow;
			col1 = caseCol;
		}
		else if(dp[left][right] == dist2 + dp[left][caseNum]){
			cout << "2\n";
			right = caseNum;
			row2 = caseRow;
			col2 = caseCol;
		}
	}
}
