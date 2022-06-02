#include <bits/stdc++.h>

using namespace std;

int T, N;

int solve(){
	cin >> N;
	string oldPW;
	cin >> oldPW;
	bool digit = false;
	bool uc = false;
	bool lc = false;
	bool sc = false;
	for(int i = 0; i < N; i++){
		char c = oldPW[i];
		if(c <= '9' && c >= '0'){
			digit = true;
		}
		else if(c <= 'Z' && c >= 'A'){
			uc = true;
		}
		else if(c <= 'z' && c >= 'a'){
			lc = true;
		}
		else if(c == '#' || c == '@' || c == '*' || c == '&'){
			sc = true;
		}
	}
	if(digit == false){
		oldPW += '1';
		digit = true;
	}
	if(uc == false){
		oldPW += 'A';
		uc = true;
	}
	if(lc == false){
		oldPW += 'a';
		lc = true;
	}
	if(sc == false){
		oldPW += '#';
		sc = true;
	}
	while(oldPW.length() < 7){
		oldPW += 'A';
	}
	cout << oldPW << "\n";
	return 0;
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
