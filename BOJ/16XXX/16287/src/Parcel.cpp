#include <bits/stdc++.h>

using namespace std;

int N, W;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> W >> N;
	arr.resize(N, 0);
	bool dp[W + 1];
	memset(dp, false, sizeof(dp));
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for(int i = 0; i < N - 2; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] + arr[j] > W){
				break;
			}
			dp[arr[i] + arr[j]] = true;
		}
		for(int j = i + 2; j < N; j++){
			int remainder = W - arr[i + 1] - arr[j];
			if(remainder <= 0){
				break;
			}
			else if(remainder <= 400000 && dp[remainder] == true){
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}
