#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
map<ll, ll> epFunc;

ll eulerphi(ll N){
	if(N == 1){
		epFunc[1] = 1;
		return 1;
	}
	ll ans = N;
	for(ll i = 2; i * i <= N; i++){
		if(N % i == 0){
			ans -= ans / i;
		}
		while(N % i == 0){
			N /= i;
		}
	}
	if(N != 1){
		ans -= ans / N;
	}
	return ans;
}

int main() {
	cin >> N;
	cout << eulerphi(N);
}
