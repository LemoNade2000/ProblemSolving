#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> ph;

int main() {
	cin >> N;
	for(int i = 0; i < N; i++){
		int n;
		cin >> n;
		ph.push_back(n);
	}
	auto left = ph.begin();
	auto right = ph.end() - 1;
	int sum = INT_MAX;
	int ans[2];
	while(left != right){
		int newSum = *left + *right;
		if(abs(newSum) < abs(sum)){
			ans[0] = *left;
			ans[1] = *right;
			sum = abs(newSum);
		}
		if(newSum <= 0){
			left++;
		}
		if(newSum > 0){
			right--;
		}
	}
	cout << ans[0] << " " << ans[1];
}
