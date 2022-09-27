#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long int> ph;

long long int longAbs(long long int a){
	if(a >= 0){
		return a;
	}
	else return -a;
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++){
		long long int n;
		cin >> n;
		ph.push_back(n);
	}
	sort(ph.begin(), ph.end());
	vector<long long int> ans;
	ans.resize(3, 0);
	long long int sum = LLONG_MAX;

	for(int i = 0; i < N; i++){
		auto left = ph.begin();
		auto right = ph.end() - 1;
		long long int selected = -ph[i];
		while(left != right){
			if(*left == ph[i]){
				left++;
				continue;
			}
			else if(*right == ph[i]){
				right--;
				continue;
			}
			long long int newSum = *left + *right + ph[i];
			long long int lr = *left + *right;
			if(longAbs(newSum) < longAbs(sum)){
				ans[0] = *left;
				ans[1] = *right;
				ans[2] = ph[i];
				sum = longAbs(newSum);
				if(sum == 0){
					sort(ans.begin(), ans.end());
					cout << ans[0] << " " << ans[1] << " " << ans[2];
					return 0;
				}
			}
			if(lr <= selected){
				left++;
			}
			if(lr > selected){
				right--;
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans[0] << " " << ans[1] << " " << ans[2];
}
