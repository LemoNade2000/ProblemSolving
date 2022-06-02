#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int N;
vector<ll> menu;

ll power(ll n, ll k) {
	ll ret;
	if (k == 0)
		return 1;
	if (k == 1)
		return n;
	ret = power(n, k / 2);
	ret = ret * ret;
	ret %= MOD;
	if (k % 2)
		ret *= n;
	return ret % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll ans = 0;

	cin >> N;
	menu.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> menu[i];
	}
	sort(menu.begin(), menu.end());
	for (int i = 0; i < N; i++) {
		ans += menu[i] * (power(2, i) + MOD - power(2, (ll)N - i - 1)) % MOD;
		ans %= MOD;
	}
	cout << ans << "\n";
}
