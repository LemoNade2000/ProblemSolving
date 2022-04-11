#include <iostream>
#include <vector>

using namespace std;

int board[10][10];
bool rd[20];
bool ld[20];
int ans[2] = {0};

int solve(int size, int cnt, int x, int y, int col){
	if(y >= size){
		if(cnt > ans[col]){
			ans[col] = cnt;
		}
		return 0;
	}
	if(x >= size){
		y++;
		if(x % 2 == 0){
			x = 1;
		}
		else{
			x = 0;
		}
	}
	if(board[x][y] == 1 && !rd[x-y+size] && !ld[x + y + 1]){
		rd[x-y+size] = true;
		ld[x+y+1] = true;
		solve(size, cnt+1, x+2, y, col);
		rd[x-y+size] = false;
		ld[x+y+1] = false;
	}
	solve(size, cnt, x+2, y, col);
	return 0;
}

int main() {
	int size;
	cin >> size;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < 20; i++){
		rd[i] = false;
		ld[i] = false;
	}
	solve(size, 0, 0, 0, 0);
	solve(size, 0, 1, 0, 1);
	cout << ans[0] + ans[1];
}
