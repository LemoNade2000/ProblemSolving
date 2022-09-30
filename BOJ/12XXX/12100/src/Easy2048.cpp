#include <bits/stdc++.h>

using namespace std;

int N;
int maximum;

int** left(int **prevBoard){
	int** newBoard = new int*[N];
	for(int i = 0; i < N; i++){
		newBoard[i] = new int[N];
	}
	for(int i = 0; i < N; i++){
		int idx = 0;
		queue<int> line;
		int prev = -1;
		for(int j = 0; j < N; j++){
			int num = prevBoard[i][j];
			if(num == 0){
				continue;
			}
			else if(prev == -1){
				prev = num;
			}
			else if(num == prev){
				line.push(prev*2);
				prev = -1;
			}
			else if(num != prev){
				line.push(prev);
				prev = num;
			}
		}
		if(prev != -1){
			line.push(prev);
		}
		for(int k = 0; k < N; k++){
			if(!line.empty()){
				newBoard[i][idx] = line.front();
				line.pop();
			}
			else{
				newBoard[i][idx] = 0;
			}
			idx++;
		}
	}
	return newBoard;
}

int** right(int **prevBoard){
	int** newBoard = new int*[N];
	for(int i = 0; i < N; i++){
		newBoard[i] = new int[N];
	}
	for(int i = 0; i < N; i++){
		int idx = N - 1;
		queue<int> line;
		int prev = -1;
		for(int j = N - 1; j >= 0; j--){
			int num = prevBoard[i][j];
			if(num == 0){
				continue;
			}
			else if(prev == -1){
				prev = num;
			}
			else if(num == prev){
				line.push(prev*2);
				prev = -1;
			}
			else if(num != prev){
				line.push(prev);
				prev = num;
			}
		}
		if(prev != -1){
			line.push(prev);
		}
		for(int k = 0; k < N; k++){
			if(!line.empty()){
				newBoard[i][idx] = line.front();
				line.pop();
			}
			else{
				newBoard[i][idx] = 0;
			}
			idx--;
		}
	}
	return newBoard;
}

int** up(int **prevBoard){
	int** newBoard = new int*[N];
	for(int i = 0; i < N; i++){
		newBoard[i] = new int[N];
	}
	for(int i = 0; i < N; i++){
		int idx = 0;
		queue<int> line;
		int prev = -1;
		for(int j = 0; j < N; j++){
			int num = prevBoard[j][i];
			if(num == 0){
				continue;
			}
			else if(prev == -1){
				prev = num;
			}
			else if(num == prev){
				line.push(prev*2);
				prev = -1;
			}
			else if(num != prev){
				line.push(prev);
				prev = num;
			}
		}
		if(prev != -1){
			line.push(prev);
		}
		for(int k = 0; k < N; k++){
			if(!line.empty()){
				newBoard[idx][i] = line.front();
				line.pop();
			}
			else{
				newBoard[idx][i] = 0;
			}
			idx++;
		}
	}
	return newBoard;
}

int** down(int **prevBoard){
	int** newBoard = new int*[N];
	for(int i = 0; i < N; i++){
		newBoard[i] = new int[N];
	}
	for(int i = 0; i < N; i++){
		int idx = N - 1;
		queue<int> line;
		int prev = -1;
		for(int j = N - 1; j >= 0; j--){
			int num = prevBoard[j][i];
			if(num == 0){
				continue;
			}
			else if(prev == -1){
				prev = num;
			}
			else if(num == prev){
				line.push(prev*2);
				prev = -1;
			}
			else if(num != prev){
				line.push(prev);
				prev = num;
			}
		}
		if(prev != -1){
			line.push(prev);
		}
		for(int k = 0; k < N; k++){
			if(!line.empty()){
				newBoard[idx][i] = line.front();
				line.pop();
			}
			else{
				newBoard[idx][i] = 0;
			}
			idx--;
		}
	}
	return newBoard;
}

int solve(int depth, int **board){
	/*
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	if(depth == 5){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(board[i][j] > maximum){
					maximum = board[i][j];
				}
			}
		}
		return 0;
	}
	depth++;
	solve(depth, left(board));
	solve(depth, right(board));
	solve(depth, up(board));
	solve(depth, down(board));
	return 0;
}

int main() {
	cin >> N;
	int** initBoard = new int*[N];
	for(int i = 0; i < N; i++){
		initBoard[i] = new int[N];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int num;
			cin >> num;
			initBoard[i][j] = num;
		}
	}
	solve(0, initBoard);
	cout << maximum;
}
