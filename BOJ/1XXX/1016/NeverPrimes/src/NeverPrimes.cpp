#include <iostream>
#include <math.h>

int main(){
	long long int min, max;
	long long int result = 0;
	std::cin >> min >> max;
	bool isPrimeProduct[max - min + 1];
	for(long long int i = 0; i < max - min + 1; ++i){
		isPrimeProduct[i] = 0;
	}
	for(long long int i = 2; i <= sqrt(max); i++){
			long long int x;
			x = (min / (i * i));
			while(i * i * x <= max){
				if(i * i * x >= min){
				isPrimeProduct[i * i * x - min] = true;
				}
				x++;
			}

	}

	for(long long int i = 0; i < max - min + 1; ++i){
		if(isPrimeProduct[i] == false){
			result++;
		}
	}
	std::cout << result << std::endl;
}

