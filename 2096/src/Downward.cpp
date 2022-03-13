#include <iostream>
using namespace std;


int main() {
	int numSteps;
	cin >> numSteps;
	int score[3];
	for(int j = 0; j < 3; j++){
		cin >> score[j];
	}

	int memo[2][3];
	int memo2[2][3];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			memo[i][j] = 0;
			memo2[i][j] = 999999;
		}
	}
	memo2[0][0] = score[0], memo2[0][1] = score[1], memo2[0][2] = score[2];
	memo[0][0] = score[0], memo[0][1] = score[1], memo[0][2] = score[2];
	for(int i = 1; i < numSteps; i++){
		for(int j = 0; j < 3; j++){
			cin >> score[j];
		}
		for(int j = 0; j < 3; j++){
			if(j == 0){
				if(memo[1][j] <= memo[0][0] + score[0])
					memo[1][j] = memo[0][0] + score[0];
				if(memo[1][j] <= memo[0][1] + score[0])
					memo[1][j] = memo[0][1] + score[0];
				if(memo2[1][j] >= memo2[0][0] + score[0])
					memo2[1][j] = memo2[0][0] + score[0];
				if(memo2[1][j] >= memo2[0][1] + score[0])
					memo2[1][j] = memo2[0][1] + score[0];
			}
			if(j == 1){
				if(memo[1][j] <= memo[0][0] + score[1])
					memo[1][j] = memo[0][0] + score[1];
				if(memo[1][j] <= memo[0][1] + score[1])
					memo[1][j] = memo[0][1] + score[1];
				if(memo[1][j] <= memo[0][2] + score[1])
					memo[1][j] = memo[0][2] + score[1];
				if(memo2[1][j] >= memo2[0][0] + score[1])
					memo2[1][j] = memo2[0][0] + score[1];
				if(memo2[1][j] >= memo2[0][1] + score[1])
					memo2[1][j] = memo2[0][1] + score[1];
				if(memo2[1][j] >= memo2[0][2] + score[1])
					memo2[1][j] = memo2[0][2] + score[1];
			}
			if(j == 2){
				if(memo[1][j] <= memo[0][1] + score[2])
					memo[1][j] = memo[0][1] + score[2];
				if(memo[1][j] <= memo[0][2] + score[2])
					memo[1][j] = memo[0][2] + score[2];
				if(memo2[1][j] >= memo2[0][1] + score[2])
					memo2[1][j] = memo2[0][1] + score[2];
				if(memo2[1][j] >= memo2[0][2] + score[2])
					memo2[1][j] = memo2[0][2] + score[2];
			}
		}
		for(int j = 0; j < 3; j++){
			memo[0][j] = memo[1][j];
			memo[1][j] = 0;
			memo2[0][j] = memo2[1][j];
			memo2[1][j] = 999999;
		}
	}
	int max = 0; int min = 999999;
	for(int i = 0; i < 3; i++){
		if(max < memo[0][i]){
			max = memo[0][i];
		}
		if(min > memo2[0][i]){
			min = memo2[][i];
		}
	}
	cout << max << " " << min;

}
