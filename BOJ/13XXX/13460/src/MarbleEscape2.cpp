#include <bits/stdc++.h>

using namespace std;

int H, W;

struct Position{
	int redRow;
	int redCol;
	int blueRow;
	int blueCol;
};

struct Board{
	char** gameBoard;
	int redRow;
	int redCol;
	int blueRow;
	int blueCol;
	char state = 'n';
};

void deepCopy(Board prevBoard, Board &newBoard){
	newBoard.blueCol = prevBoard.blueCol;
	newBoard.blueRow = prevBoard.blueRow;
	newBoard.redCol = prevBoard.redCol;
	newBoard.redRow = prevBoard.redRow;
	char** newGameBoard = new char*[H];
	for(int i = 0; i < H; i++){
		newGameBoard[i] = new char[W];
	}
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			newGameBoard[i][j] = prevBoard.gameBoard[i][j];
		}
	}
	newBoard.gameBoard = newGameBoard;
}

Board left(Board prevBoard){
	Board newBoard;
	deepCopy(prevBoard, newBoard);
	if(newBoard.redCol <= newBoard.blueCol){
		while(true){
			if(newBoard.gameBoard[newBoard.redRow][newBoard.redCol - 1] == 'O'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow = -1;
				newBoard.redCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.redRow][newBoard.redCol - 1] == '.'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redCol--;
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = 'R';
			}
			else {
				break;
			}
		}
		while(true){
			if(newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol - 1] == 'O'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow = -1;
				newBoard.blueCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol - 1] == '.'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueCol--;
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = 'B';
			}
			else {
				break;
			}
		}
	}
	else{
		while(true){
			if(newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol - 1] == 'O'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow = -1;
				newBoard.blueCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol - 1] == '.'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueCol--;
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = 'B';
			}
			else {
				break;
			}
	}

		while(true){
			if(newBoard.gameBoard[newBoard.redRow][newBoard.redCol - 1] == 'O'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow = -1;
				newBoard.redCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.redRow][newBoard.redCol - 1] == '.'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redCol--;
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = 'R';
			}
			else {
				break;
			}
		}
	}
	newBoard.state = 'l';
	return newBoard;
}

Board right(Board prevBoard){
	Board newBoard;
	deepCopy(prevBoard, newBoard);
	if(newBoard.redCol >= newBoard.blueCol){
		while(true){
			if(newBoard.gameBoard[newBoard.redRow][newBoard.redCol + 1] == 'O'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow = -1;
				newBoard.redCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.redRow][newBoard.redCol + 1] == '.'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redCol++;
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = 'R';
			}
			else {
				break;
			}
		}
		while(true){
			if(newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol + 1] == 'O'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow = -1;
				newBoard.blueCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol + 1] == '.'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueCol++;
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = 'B';
			}
			else {
				break;
			}
		}
	}
	else{
		while(true){
			if(newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol + 1] == 'O'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow = -1;
				newBoard.blueCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol + 1] == '.'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueCol++;
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = 'B';
			}
			else {
				break;
			}
	}

		while(true){
			if(newBoard.gameBoard[newBoard.redRow][newBoard.redCol + 1] == 'O'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow = -1;
				newBoard.redCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.redRow][newBoard.redCol + 1] == '.'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redCol++;
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = 'R';
			}
			else {
				break;
			}
		}
	}
	newBoard.state = 'r';
	return newBoard;
}

Board up(Board prevBoard){
	Board newBoard;
	deepCopy(prevBoard, newBoard);
	if(newBoard.redRow <= newBoard.blueRow){
		while(true){
			if(newBoard.gameBoard[newBoard.redRow - 1][newBoard.redCol] == 'O'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow = -1;
				newBoard.redCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.redRow - 1][newBoard.redCol] == '.'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow--;
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = 'R';
			}
			else {
				break;
			}
		}
		while(true){
			if(newBoard.gameBoard[newBoard.blueRow - 1][newBoard.blueCol] == 'O'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow = -1;
				newBoard.blueCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.blueRow - 1][newBoard.blueCol] == '.'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow--;
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = 'B';
			}
			else {
				break;
			}
		}
	}
	else{
		while(true){
			if(newBoard.gameBoard[newBoard.blueRow - 1][newBoard.blueCol] == 'O'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow = -1;
				newBoard.blueCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.blueRow - 1][newBoard.blueCol] == '.'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow--;
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = 'B';
			}
			else {
				break;
			}
		}
		while(true){
			if(newBoard.gameBoard[newBoard.redRow - 1][newBoard.redCol] == 'O'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow = -1;
				newBoard.redCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.redRow - 1][newBoard.redCol] == '.'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow--;
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = 'R';
			}
			else {
				break;
			}
		}
	}
	newBoard.state = 'u';
	return newBoard;
}

Board down(Board prevBoard){
	Board newBoard;
	deepCopy(prevBoard, newBoard);
	if(newBoard.redRow >= newBoard.blueRow){
		while(true){
			if(newBoard.gameBoard[newBoard.redRow + 1][newBoard.redCol] == 'O'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow = -1;
				newBoard.redCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.redRow + 1][newBoard.redCol] == '.'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow++;
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = 'R';
			}
			else {
				break;
			}
		}
		while(true){
			if(newBoard.gameBoard[newBoard.blueRow + 1][newBoard.blueCol] == 'O'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow = -1;
				newBoard.blueCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.blueRow + 1][newBoard.blueCol] == '.'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow++;
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = 'B';
			}
			else {
				break;
			}
		}
	}
	else{
		while(true){
			if(newBoard.gameBoard[newBoard.blueRow + 1][newBoard.blueCol] == 'O'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow = -1;
				newBoard.blueCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.blueRow + 1][newBoard.blueCol] == '.'){
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = '.';
				newBoard.blueRow++;
				newBoard.gameBoard[newBoard.blueRow][newBoard.blueCol] = 'B';
			}
			else {
				break;
			}
		}
		while(true){
			if(newBoard.gameBoard[newBoard.redRow + 1][newBoard.redCol] == 'O'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow = -1;
				newBoard.redCol = -1;
				break;
			}
			else if(newBoard.gameBoard[newBoard.redRow + 1][newBoard.redCol] == '.'){
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = '.';
				newBoard.redRow++;
				newBoard.gameBoard[newBoard.redRow][newBoard.redCol] = 'R';
			}
			else {
				break;
			}
		}
	}
	newBoard.state = 'd';
	return newBoard;
}

int solve(int depth, queue<Board> board){
	bool solved = false;
	queue<Board> q;
	while(!board.empty()){
		Board prevBoard = board.front();
		board.pop();
		if(prevBoard.redCol == -1 || prevBoard.blueCol == -1){
			if(prevBoard.blueCol == -1){
				continue;
			}
			else if(prevBoard.blueCol != -1){
				cout << depth << "\n";
				solved = true;
				break;
			}
		}
		/*
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				cout << prevBoard.gameBoard[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
		if(prevBoard.state == 'n'){
			q.push(left(prevBoard));
			q.push(right(prevBoard));
			q.push(up(prevBoard));
			q.push(down(prevBoard));
		}
		if(prevBoard.state == 'u' || prevBoard.state == 'd'){
			q.push(left(prevBoard));
			q.push(right(prevBoard));
		}
		if(prevBoard.state == 'l' || prevBoard.state == 'r'){
			q.push(up(prevBoard));
			q.push(down(prevBoard));
		}
	}
	if(solved == false){
		if(depth == 10){
			cout << -1;
			return 0;
		}
		depth++;
		solve(depth, q);
	}
	return 0;
}

int main() {
	cin >> H >> W;
	char** initBoard = new char*[H];
	for(int i = 0; i < H; i++){
		initBoard[i] = new char[W];
	}
	Board init;
	init.gameBoard = initBoard;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			char b;
			cin >> b;
			if(b == 'R'){
				init.redRow = i;
				init.redCol = j;
			}
			if(b == 'B'){
				init.blueRow = i;
				init.blueCol = j;
			}
			initBoard[i][j] = b;
		}
	}
	init.state = 'n';
	queue<Board> initQ;
	initQ.push(init);
	solve(0, initQ);
}
