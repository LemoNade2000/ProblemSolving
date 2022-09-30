#include <iostream>
#include <cstring>
using namespace std;

int row, col;
char board[21][21];
int answer = 0;
bool visited[30];

int dfs(int x, int y, int step){
	if(step > answer) answer = step;
	if(x < col - 1 && visited[board[y][x+1] - 'A'] == false){
		visited[board[y][x+1] - 'A'] = true;
		dfs(x+1, y, step+1);
		visited[board[y][x+1] - 'A'] = false;
	}
	if(x > 0 && visited[board[y][x-1] - 'A'] == false){
		visited[board[y][x-1] - 'A'] = true;
		dfs(x-1, y, step+1);
		visited[board[y][x-1] - 'A'] = false;
	}
	if(y < row - 1 && visited[board[y+1][x] - 'A'] == false){
		visited[board[y+1][x] - 'A'] = true;
		dfs(x, y+1, step+1);
		visited[board[y+1][x] - 'A'] = false;
	}
	if(y > 0 && visited[board[y-1][x] - 'A'] == false){
		visited[board[y-1][x] - 'A'] = true;
		dfs(x, y-1, step+1);
		visited[board[y-1][x] - 'A'] = false;
	}
}

int main() {
	cin >> row >> col;
	string str;
	for(int i = 0; i < row; i++){
		cin >> str;
		for(int j = 0; j < col; j++){
			board[i][j] = str[j];
		}
	}
	for(int i = 0; i < 30; i++){
		visited[i] = false;
	}
	visited[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << answer;
}
