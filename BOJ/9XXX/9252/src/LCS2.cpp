#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){
	if(a >= b){
		return a;
	}
	else return b;
}

int main() {
	string firstStr, secondStr;
	cin >> firstStr;
	cin >> secondStr;
	int dp[firstStr.length() + 1][secondStr.length() + 1];

	for(int i = 0; i <= firstStr.length(); i++){
		for(int j = 0; j <= secondStr.length(); j++){
			dp[i][j] = 0;
		}
	}

	for(int i = 0; i < firstStr.length(); i++){
		for(int j = 0; j < secondStr.length(); j++){
			if(firstStr[i] == secondStr[j]){
				dp[i+1][j+1] = 1 + dp[i][j];
			}
			else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
		}
	}
	int ans = dp[firstStr.length()][secondStr.length()];
	cout << ans << "\n";
	stack<char> str;
	int i = firstStr.length();
	int j = secondStr.length();
	for(int found = 0; found < ans;){
		if(dp[i][j] == dp[i - 1][j]){
			i--;
		}
		else if(dp[i][j] == dp[i][j - 1]){
			j--;
		}
		else{
			str.push(firstStr[i-1]);
			i--;
			j--;
			found++;
		}
	}
	for(int i = 0; i < ans; i++){
		cout << str.top();
		str.pop();
	}
}
