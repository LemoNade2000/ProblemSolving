#include <iostream>
#include <map>
using namespace std;

int numList[40];
map<int, int> sumMap;
long long int answer;
int obj;

int rightSeq(int index, int num, int sum){
	if(index == num){
		sumMap[sum]++;
		return 0;
	}
	rightSeq(index + 1, num, sum); // not include
	rightSeq(index + 1, num, sum + numList[index]); // include
	return 0;
}

int leftSeq(int index, int num, int sum){
	if(index == num){
		answer += sumMap[obj - sum];
		return 0;
	}
	leftSeq(index + 1, num, sum);
	leftSeq(index + 1, num, sum + numList[index]);
	return 0;
}

int main() {
	int num;
	cin >> num >> obj;
	for(int i = 0; i < num; i++){
		cin >> numList[i];
	}

	rightSeq(num / 2, num, 0);
	leftSeq(0, num / 2, 0);
	if(obj == 0){
		cout << answer - 1;
		return 0;
	}
	cout << answer;
}
