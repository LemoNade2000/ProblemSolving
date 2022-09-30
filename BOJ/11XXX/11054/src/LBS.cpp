#include <iostream>
#include <vector>

using namespace std;

vector<int> seq;
int ascDp[1001];
int dscDp[1001];

int max(int a, int b){
	if(a >= b){
		return a;
	}
	else return b;
}
// ascending sequence until i
int asc(int length, int mid){
	for(int i = 0; i <= mid; i++){
		ascDp[i] = 1;
	}

	for(int i = 0; i <= mid; i++){
		for(int j = 0; j < i; j++){
			if(seq[i] > seq[j]){
				ascDp[i] = max(ascDp[i], ascDp[j]+ 1);
			}
		}
	}
	return ascDp[mid];
}

// descending sequence from i
int dsc(int length, int mid){
	for(int i = mid; i <= length; i++){
		dscDp[i] = 1;
	}
	for(int i = length - 1; i >= mid; i--){
		for(int j = length - 1; j > i; j--){
			if(seq[i] > seq[j]){
				dscDp[i] = max(dscDp[i], dscDp[j] + 1);
			}
		}
	}
	return dscDp[mid];
}
int main() {
	int length;
	cin >> length;
	for(int i = 0; i < length; i++){
		int num;
		cin >> num;
		seq.push_back(num);
	}
	int result = 0;
	for(int i = 0; i < length; i++){
		result = max(result, asc(length, i) + dsc(length, i) - 1);
	}
	cout << result;
}
