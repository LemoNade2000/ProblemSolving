#include <iostream>
using namespace std;

int min(int a, int b){
	if(a < b){
		return a;
	}
	else return b;
}
int main() {
	int num, obj;
	cin >> num >> obj;
	int list[num];
	for(int i = 0; i < num; i++){
		cin >> list[i];
	}
	int* start = &list[0];
	int* end = &list[0];
	int sum = list[0];
	int length = 100001;
	for(int i = 0; start != &list[num - 1]; i++){
		if(sum >= obj){
			length = min(length, end - start);
		}
		if(sum >= obj){
			sum -= * (start);
			start += 1;
		}
		else if(sum < obj && end != &list[num - 1]){
			end += 1;
			sum += * (end);
		}
		else if(sum < obj && end == &list[num - 1]){
			break;
		}
	}
	if(list[num - 1] >= obj){
		length = 0;
	}
	if(length == 100001){
		cout << 0;
		return 0;
	}
	cout << length + 1;
}
