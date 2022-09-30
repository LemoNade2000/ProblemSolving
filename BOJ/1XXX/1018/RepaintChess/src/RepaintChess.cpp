//============================================================================
// Name        : RepaintChess.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int checkBoard(int row, int col, int *chessBoard, int columnNum) {
	int selectedBoard[8][8];
	int min = 0;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			selectedBoard[i][j] = *((chessBoard+(i+row)*columnNum) + (j+col));
		}
	}
	// if first color was black
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if((i+j)%2 == 0 && selectedBoard[i][j] == 1){
				min++;
			}
			if((i+j)%2 == 1 && selectedBoard[i][j] == 0){
				min++;
			}
		}
	}
	int blkFirst = min;
	min = 0;
	// if first color was white
	for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				if((i+j)%2 == 0 && selectedBoard[i][j] == 0){
					min++;
				}
				if((i+j)%2 == 1 && selectedBoard[i][j] == 1){
					min++;
				}
			}
		}
	int whtFirst = min;
	if(blkFirst <= whtFirst){
		return(blkFirst);
	}
	else return whtFirst;
}

int main() {
	int min = 999;
	int m, n = 0;
	std::cin >> m >> n;
	char line[n];
	int chessBoard[m][n];
	for(int i = 0; i < m; i++){
		std::cin >> line;
		for(int j = 0; j < n; j++){
			if(line[j] == 'B')
				chessBoard[i][j] = 0;
			else chessBoard[i][j] = 1;
		}
	}
	for(int i = 0; i < m - 7; i++){
		for(int j = 0; j < n - 7; j++){
			int result = checkBoard(i, j, &chessBoard[0][0], n);
			if (result < min)
				min = result;
		}
	}
	std::cout << min << std::endl;
}

