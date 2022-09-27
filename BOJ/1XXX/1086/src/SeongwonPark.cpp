#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
int K;
int MAX;
ll totalCase;
string numArr[15];
int mods[15];
int baseMods[51];
ll memo[1 << 15][100];

int getMod(string num){
	int mod = 0;
	for(int i = 0; i < num.length(); i++){
		mod *= 10;
		mod += num[i] - '0';
		mod %= K;
	}
	return mod;
}

ll gcd(ll a, ll b){
	ll ans;
	while(b != 0){
		ans = a % b;
		a = b;
		b = ans;
	}
	return a;
}

ll dfs(int bitField, int remainder){
	if(memo[bitField][remainder] != -1){
		return memo[bitField][remainder];
	}
	if(bitField == MAX){
		if(remainder == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	ll ans = 0;
	for(int i = 0; i < N; i++){
		if(!(bitField & (1 << i))){
			int temp = remainder * baseMods[numArr[i].length()] + mods[i];
			ans += dfs(bitField | (1 << i), temp % K);
		}
	}
	memo[bitField][remainder] = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> numArr[i];
	}
	MAX = (1 << N) - 1;
	cin >> K;
	for(int i = 0; i < N; i++){
		mods[i] = getMod(numArr[i]);
	}
	string baseTen = "1";
	for(int i = 0; i < 51; i++){
		baseMods[i] = getMod(baseTen);
		baseTen += "0";
	}
	memset(memo, -1, sizeof(memo));
	totalCase = 1;
	for(int i = 1; i <= N; i++){
		totalCase *= i;
	}
	ll ans = dfs(0, 0);
	if(ans == 0){
		cout << "0/1";
		return 0;
	}
	ll denom = gcd(totalCase, ans);
	totalCase /= denom;
	ans /= denom;
	cout << abs(ans) << "/" << abs(totalCase);
	return 0;
}
