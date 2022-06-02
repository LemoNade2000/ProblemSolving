#include <bits/stdc++.h>

#define MOD 10007

using namespace std;

int nCr[53][53];
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int n=0; n <= 52; n++){
        nCr[n][0] = 1; nCr[n][n] = 1;
        for(int k = 1; k < n; k++){
            nCr[n][k] = nCr[n-1][k-1] + nCr[n-1][k];
            nCr[n][k] %= MOD;
            nCr[n][n-k] = nCr[n][k];
        }
    }
    int ans = 0;
    for(int i = 4; i <= N; i += 4){
        if((i / 4) % 2 == 1){
            ans += nCr[13][i/4] * nCr[52-i][N-i];
        }
        else{
            ans -= nCr[13][i/4] * nCr[52-i][N-i];
        }
        ans %= 10007;
    }
    if(ans < 0) {
    	ans += MOD;
    }
    cout << ans;
}
