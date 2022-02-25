
#include <iostream>
#include <string>

int bfs(int *board, int posY,int posX);
int main() {
	int height, width;
	std::cin >> height >> width;

	int board[height][width];
	for(int i = 0; i < height; i++){
		std::string boardRow;
		std::cin >> boardRow;
		for(int j = 0; j < width; j++){
			char digitChar = boardRow[j];
			board[i][j] = digitChar - '0';
		}
	}
	std::cout << bfs(board, 0, 0); << std::endl;
}
