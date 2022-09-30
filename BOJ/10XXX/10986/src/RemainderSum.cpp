#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MOD 1000000007

int N, M;
ll cnt[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int sum = 0;
    cnt[0]++;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        sum += n;
        sum %= M;
        cnt[sum]++;
    }
    ll ans = 0;
    for(int i = 0; i < 1001; i++){
        ans += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    cout << ans << "\n";
}