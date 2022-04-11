#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	long long int sum = 0;
	long long int bitxor = 0;
	int num;
	cin >> num;
	for(int t = 0; t < num; t++){
		int op;
		cin >> op;
		if(op == 1){
			int input;
			cin >> input;
			sum += input;
			bitxor ^= input;
		}
		else if(op == 2){
			int input;
			cin >> input;
			sum -= input;
			bitxor ^= input;
		}
		else if(op == 3){
			cout << sum << "\n";
		}
		else if(op == 4){
			cout << bitxor << "\n";
		}
	}
	return 0;
}
