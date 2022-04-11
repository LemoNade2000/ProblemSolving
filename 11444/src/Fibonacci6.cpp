#include <iostream>
#include <map>
using namespace std;

#define MODULAR 1000000007
map<long long int, long long int> fib;

long long int docagne(long long int num){
	if(num == 0){
		fib[0] = 0;
		return 0;
	}
	if(num == 1){
		fib[1] = 1;
		return 1;
	}
	if(num == 2){
		fib[2] = 1;
		return 1;
	}
	if(num == 3){
		fib[3] = 2;
		return 2;
	}
	if(fib.count(num) > 0) return fib[num];
	if(num % 2 == 0){
		long long int a = docagne(num / 2);
		long long int b = docagne(num / 2 - 1);
		fib[num] = ((a % MODULAR) * ((2 * b + a) % MODULAR)) % MODULAR;
		return fib[num];
	}
	else{
		long long int a = docagne(num / 2);
		long long int b = docagne(num / 2 + 1);
		fib[num] = ((a * a) % MODULAR + (b * b) % MODULAR) % MODULAR;
		return fib[num];
	}
}

int main() {
	long long int num;
	cin >> num;
	long long int answer;
	answer = docagne(num) % MODULAR;
	cout << answer;
}
