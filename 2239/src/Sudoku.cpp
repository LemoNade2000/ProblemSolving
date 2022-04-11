#include <iostream>
#include <cstring>
using namespace std;

int used = (1 << 9) - 1;
int board[9][9] = {0};
int ans[9][9] = {0};
int cnt;

void printboard(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << board[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
	exit(1);
	return;
}
int solve(int row, int col){
	if (row == 9 & cnt == 0){ // succesfully completed
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				ans[i][j] = board[i][j];
			}
		}
		printboard();
		cnt++;
		return 0;
	}
	if(cnt > 0){
		return 0;
	}
	if (col == 9){ // row solved
		return solve(row+1, 0);
	}
	if (board[row][col] != 0){ // number exists
		return solve(row, col+1);
	}
	if (board[row][col] == 0){
		//row
		int rowUsed = 0;
		for(int i = 0; i < 9; i++){
			if(board[row][i] != 0){
				rowUsed = (rowUsed | 1 << (board[row][i] - 1));
			}
		}
		rowUsed = (used ^ rowUsed); // stores numbers not used in row
		//col
		int colUsed = 0;
		for(int i = 0; i < 9; i++){
			if(board[i][col] != 0){
				colUsed = (colUsed | 1 << (board[i][col] - 1));
			}
		}
		colUsed = (used ^ colUsed);
		//square
		int sqUsed = 0;
		int sqR = row / 3;
		int sqC = col / 3;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(board[3*sqR + i][3*sqC + j] != 0){
					sqUsed = (sqUsed | 1 << (board[3*sqR + i][3*sqC + j] - 1));
				}
			}
		}
		sqUsed = (used ^ sqUsed);
		int usable = 0;
		usable = (rowUsed & colUsed & sqUsed); // numbers that are not used in any
		for(int i = 1; i <= 9; i++){
			if(usable % 2 == 1){
				board[row][col] = i;
				solve(row, col + 1);
				board[row][col] = 0;
				usable = (usable - 1) / 2;
			}
			else{
				usable /= 2;
			}
		}
	}
	return 0;
}

int main() {
	cnt = 0;
	for(int i = 0; i < 9; i++){
		string str;
		cin >> str;
		for(int j = 0; j < 9; j++){
			board[i][j] = str[j] - '0';
		}
	}
	solve(0, 0);
	return 0;
}
