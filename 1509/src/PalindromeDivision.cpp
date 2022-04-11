#include <iostream>
#include <cstring>

using namespace std;

int min(int a, int b){
	if(a <= b){
		return a;
	}
	else return b;
}

bool isPalin(string str, int start, int end){
	int loop;
	if(end == start){
		return true;
	}
	if((end - start) % 2 == 0){ // odd num char
		loop = (end - start) / 2;
	}
	else{ // even num char
		loop = (end - start + 1) / 2;
	}
	for(int i = 0; i < loop; i++){
		if(str[end] != str[start]){
			return false;
		}
		end--;
		start++;
	}
	return true;
}

int main() {
	string str;
	cin >> str;
	int dp[str.length()];
	for(int i = 0; i < str.length(); i++){
		dp[i] = str.length();
	}
	dp[0] = 1;
	for(int i = 1; i < str.length(); i++){
		for(int j = i; j > 0; j--){
			if(isPalin(str, j, i)){
				dp[i] = min(dp[i], dp[j-1] + 1);
			}
		}
		if(isPalin(str, 0, i)){
			dp[i] = 1;
		}
	}
	cout << dp[str.length() - 1];
}
