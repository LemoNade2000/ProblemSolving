#include <iostream>

int main(){
	long long int result = 1;
	int sum, variable = 0;
	std::cin >> sum >> variable;
	int i, j = 0; // i being a power of smaller number than j
	int quo = sum/variable;
	j = sum % variable;
	i = variable - j;
	for(int x = 0; x < i; x++){
		result = result * quo;
	}
	for(int y = 0; y < j; y++){
		result = result * (quo + 1);
	}
	std::cout.precision(0);
	std::cout << result << std::endl;
}
