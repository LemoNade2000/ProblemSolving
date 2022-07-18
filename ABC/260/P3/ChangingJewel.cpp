#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, X, Y;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> X >> Y;
    ll red[10];
    ll blue[10];
    red[1] = 0;
    blue[1] = 1;
    for(int i = 2; i <= 10; i++){
        blue[i] = red[i - 1] + Y * blue[i - 1];
        red[i] = red[i - 1] + X * blue[i];
    }
    cout << red[N];
}