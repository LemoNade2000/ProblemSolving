
#include <iostream>
#include <math.h>

long long int dnc(long long int base, long long int exponent, long long int modular){
	if(exponent == 1){
		return base % modular;
	}
	if(exponent % 2 == 0){
		long long int temp = dnc(base, exponent / 2, modular);
		return (temp * temp) % modular;
	}
	else{
		return (dnc(base, exponent / 2 + 1, modular) * dnc(base, exponent / 2, modular)) % modular;
	}
}

int main() {
	long long int base, exponent, modular;
	std::cin >> base >> exponent >> modular;
	long long int remainder = dnc(base, exponent, modular);
	std::cout << remainder;
	return 0;
}
