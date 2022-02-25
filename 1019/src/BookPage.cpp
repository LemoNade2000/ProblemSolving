#include <iostream>
#include <math.h>

int main(){
	long long int page;
	std::cin >> page;
	long long int appearance[10] = {0,0,0,0,0,0,0,0,0,0};
	int length, temp;
	for(length = 0, temp = page; temp > 0;){
		length++;
		temp /= 10;
	}
	for(int i = 1; i < 10; i++){
		for(int j = 0; j < length; j++){
			int digit;
			long long int multiplier;
			long long int base;
			base = pow(10, j);
			temp = page;
			temp /= base;
			digit = temp % 10;
			temp = page;
			if(i < digit){
				multiplier = (temp / (10 * base)) + 1;
				appearance[i] += base * multiplier;
			}
			else if(i == digit){
				appearance[i] += (temp % base) + 1;
				multiplier = (temp / (10 * base));
				appearance[i] += base * multiplier;
			}
			else if(i > digit){
				multiplier = (temp / (10 * base));
				appearance[i] += base * multiplier;
			}
		}
	}
	// for 0 appearance
	for(int j = 0; j < length - 1; j++){
		int digit;
		long long int multiplier;
		long long int base;
		base = pow(10, j);
		temp = page;
		temp /= base;
		digit = temp % 10;
		temp = page;
		if(digit == 0){
			appearance[0] += (temp % base) + 1;
			multiplier = (temp / (10 * base)) - 1;
			appearance[0] += base * multiplier;
		}
		else{
			multiplier = (temp / (10* base));
			appearance[0] += base * multiplier;
		}
	}
	for(int i = 0; i < 10; i++){
		std::cout << appearance[i] << " ";
	}
}
