#include <iostream>
#include <cstring>

using namespace std;

bool board[10][10];
bool cpyBoard[10][10];

void copyBoard(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			cpyBoard[i][j] = board[i][j];
		}
	}
	return;
}

int light(int r, int c){
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	cpyBoard[r][c] = !cpyBoard[r][c];
	for(int i = 0; i < 4; i++){
		int row = r + dx[i];
		int col = c + dy[i];
		if(row >= 0 && row <= 9 && col >= 0 && col <= 9){
			cpyBoard[row][col] = !cpyBoard[row][col];
		}
	}
	return 0;
}

bool check(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(cpyBoard[i][j]){
				return false;
			}
		}
	}
	return true;
}

int main() {
	int ans = 111;
	for(int i = 0; i < 10; i++){
		string s;
		cin >> s;
		for(int j = 0; j < 10; j++){
			if(s[j] == 'O'){
				board[i][j] = true;
			}
			else board[i][j] = false;
		}
	}
	for(int i = 0; i < (1 << 10); i++){
		copyBoard();
		int cnt = 0;
		for(int j = 0; j < 10; j++){ // first row
			if(i & (1 << j)){
				light(0, j);
				++cnt;
			}
		}
		for(int r = 1; r < 10; r++){
			for(int c = 0; c < 10; c++){
				if(cpyBoard[r-1][c] == true){
					light(r, c);
					++cnt;
				}
			}
		}
		if(check()){
			if(ans > cnt) ans = cnt;
		}
	}
	if(ans == 111) cout << -1;
	else cout << ans;
}
