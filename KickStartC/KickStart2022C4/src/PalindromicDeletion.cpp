#include <bits/stdc++.h>

using namespace std;

int T;
int N, L;
int ans;
int tot;

bool isPalindrome(string str){
	int left = 0;
	int right = str.length() - 1;
	while(left < right){
		if(str[left] != str[right]){
			return false;
		}
		left++;
		right--;
	}
	return true;
}

int dfs(string str){
	if(str == ""){
		tot++;
		return 0;
	}
	cout << str << "\n";
	if(isPalindrome(str) == true){
		ans++;
	}
	for(int i = 0; i < str.length(); i++){
		string newStr = str;
		dfs(newStr.erase(i, 1));
	}
	return 0;
}

int solve(){
	ans = 0;
	tot = 0;
	cin >> N;
	string str;
	cin >> str;
	dfs(str);
	cout << ans << " " << tot << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		solve();
	}
}
