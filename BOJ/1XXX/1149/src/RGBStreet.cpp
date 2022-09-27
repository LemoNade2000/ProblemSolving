#include <iostream>

int memo[1001][3]; // 0 - R, 1 - G, 2 - B

int min(int a, int b){
	if(a <= b) return a;
	else return b;
}
int main() {
	int houseNum;
	std::cin >> houseNum;
	int price[houseNum][3];
	for(int i = 0; i < houseNum; i++){
		std::cin >> price[i][0] >> price[i][1] >> price[i][2];
	}
	long long int temp = 0;

	memo[0][0] = price[0][0]; memo[0][1] = price[0][1]; memo[0][2] = price[0][2];
	for(int i = 1; i < houseNum; i++){
		for(int color = 0; color < 3; color++){
			switch(color){
			case 0:
			memo[i][color] = price[i][color] + min(memo[i-1][1], memo[i-1][2]);
			break;
			case 1:
			memo[i][color] = price[i][color] + min(memo[i-1][0], memo[i-1][2]);
			break;
			case 2:
			memo[i][color] = price[i][color] + min(memo[i-1][0], memo[i-1][1]);
			break;
			}
		}
	}

	temp = memo[houseNum - 1][0];
	if(memo[houseNum-1][1] <= temp) temp = memo[houseNum-1][1];
	if(memo[houseNum-1][2] <= temp) temp = memo[houseNum-1][2];

	std::cout << temp << std::endl;
	return 0;
}
