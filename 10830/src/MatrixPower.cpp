#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int main() {
	int size;
	long long int power;
	cin >> size >> power;
	int matrix[size][size];
	int powmat[size][size];

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cin >> matrix[i][j];
		}
	}
	memcpy(powmat, matrix, sizeof(matrix));
	int log = 0;
	for(;pow(2, log) <= power; log++){
	}
	bool bin[log];
	memset(bin, false, sizeof(bin));
	log--;
	for(int i = log; power != 0; i--){
		if(pow(2, i) <= power){
			bin[i] = true;
			power = power - pow(2, i);
		}
	}
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			matrix[i][j] = 0;
			if(i == j){
				matrix[i][j] = 1;
			}
		}
	}
	for(int i = 0; i <= log; i++){
		if(bin[i] == true){
			// mat = mat * powmat
			int temp[size][size];
			memcpy(temp, matrix, sizeof(matrix));
			for(int x = 0; x < size; x++){
			for(int row = 0; row < size; row++){
				for(int col = 0; col < size; col++){
					matrix[row][col] = 0;
					for(int k = 0; k < size; k++){
						matrix[row][col] += temp[row][k] * powmat[k][col];
						matrix[row][col] %= 1000;
						}
					}
				}
			}
		}
		// powmat = powmat * powmat
		int temp[size][size];
		memcpy(temp, powmat, sizeof(powmat));
		for(int row = 0; row < size; row++){
			for(int col = 0; col < size; col++){
				powmat[row][col] = 0;
				for(int k = 0; k < size; k++){
					powmat[row][col] += temp[row][k] * temp[k][col];
					powmat[row][col] %= 1000;
				}
			}
		}

	}
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}
