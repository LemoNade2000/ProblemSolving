#include <iostream>

bool isDescending(long long int number){
	int temp = -1;
	for(; number > 0;){
		if(number % 10 <= temp){
			return false;
		}
		else{ //descending
			temp = number % 10;
			number /= 10;
		}
	}
	return true;
}

int main() {
	int rank;
	std::cin >> rank;
	if(rank >= 1023){
		std::cout << "-1" << std::endl;
		return 0;
	}
	rank++;
	long long int number = 0;
	for(int i = 0; i < rank;){
		if(number == 100){
			number = 210;
			continue;
		}
		else if(number == 1000){
			number = 3210;
			continue;
		}
		else if(number == 10000){
			number = 43210;
			continue;
		}
		else if(number == 100000){
			number = 543210;
			continue;
		}
		else if(number == 1000000){
			number = 6543210;
			continue;
		}
		else if(number == 10000000){
			number = 76543210;
			continue;
		}
		else if(number == 100000000){
			number = 876543210;
			continue;
		}
		else if(number == 876543211){
			number = 976543210;
			continue;
		}
		else if(number == 1000000000){
			number = 9876543210;
			continue;
		}
		if(isDescending(number)){
			i++;
			if(i == rank){
				std::cout << number << std::endl;
				return 0;
			}
		}
		number++;
	}
}
