#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;

int M;
ll factorial[4000001];

ll pow(ll base, ll exp){
	if(exp == 0){
		return 1;
	}
	if(exp == 1){
		return base % MOD;
	}
	if(exp % 2 == 0){
		return pow((base * base) % MOD, exp / 2) % MOD;
	}
	if(exp % 2 == 1){
		return (pow(base, exp - 1) * (base % MOD)) % MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M;
	factorial[0] = 1;
	factorial[1] = 1;
	for(ll i = 2; i < 4000001; i++){
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
	for(int tc = 0; tc < M; tc++){
		ll N, K;
		cin >> N >> K;
		ll ans = factorial[N] * pow(ll((factorial[N - K] * factorial[K]) % MOD), ll(MOD - 2));
		cout << ans % MOD << "\n";
	}
	return 0;
}
