
#include <iostream>

int memo[1001];

int max(int a, int b){
	if(a >= b){
		return a;
	}
	else return b;
}
int main() {
	int length;
	std::cin >> length;
	if(length == 0){
		std::cout << length << std::endl;
		return 0;
	}
	int array[length];
	for(int i = 0; i < length; i++){
		std::cin >> array[i];
		memo[i] = 1;
	}
	int LIS = 1;
	for(int i = 1; i < length; i++){
		for(int j = 0; j <= i; j++){
			if(array[i] > array[j]){
				memo[i] = max(memo[i], memo[j] + 1);
			}
		}
		if(LIS <= memo[i]){
			LIS = memo[i];
		}
	}
	std::cout << LIS << std::endl;
}
