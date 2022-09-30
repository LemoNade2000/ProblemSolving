#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, X;
vector<pii> game;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> X;
    game.resize(N);
    ll ans = LLONG_MAX;
    ll comp = 0;
    for(int i = 0; i < N; i++){
        if(X - i - 1 < 0){
            break;
        } 
        ll a, b;
        cin >> a >> b;
        comp += a + b;
        ans = min(ans, comp + (b * (X - i - 1)));
    }
    cout << ans;
}