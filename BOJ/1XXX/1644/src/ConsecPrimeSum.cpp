#include <iostream>
#include <vector>
#include <math.h>

#define MAX 4000000

using namespace std;

int main() {
	int obj;
	cin >> obj;
	vector<int> primes;
	vector<bool> isPrime;
	for(int i = 0; i <= MAX; i++){
		isPrime.push_back(true);
	}
	for(int i = 2; i <= sqrt(MAX); i++){
		if(isPrime[i] == true){
			for(int j = 2; i * j <= MAX; j++){
				isPrime[i*j] = false;
			}
		}
	}
	for(int i = 2; i <= MAX; i++){
		if(isPrime[i] == true){
			primes.push_back(i);
		}
	}
	auto start = primes.begin();
	auto end = primes.begin();
	int sum = 2;
	int ans = 0;
	for(; start!= primes.end();){
		if(sum == obj){
			ans++;
		}
		if(sum >= obj){
			sum -= *start;
			start++;
			if(start == primes.end()){
				break;
			}
		}
		else if(sum < obj){
			end++;
			if(end == primes.end()){
				break;
			}
			else{
				sum += *end;
			}
		}
	}
	cout << ans;
}
