#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 9901

int N, M;
vector<vector<int>> memo;

int fill(int pos, int bit){
    if(pos == N * M && bit == 0){
        return 1;
    }
    else if(pos >= N * M){
        return 0;
    }
    if(memo[pos][bit] != -1){
        return memo[pos][bit];
    }
    if(bit & 1 == 1){
        memo[pos][bit] = fill(pos + 1, (bit >> 1)) % MOD;
        return memo[pos][bit];
    }
    else{
        int ret = 0;
        ret += fill(pos + 1, (1 << (M - 1)) | (bit >> 1));
        if((pos % M) != (M - 1) && ((bit >> 1) & 1) == 0){
            ret += fill(pos + 2, (bit >> 2));
        }
        return memo[pos][bit] = (ret % MOD);
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    memo = vector<vector<int>>(N * M);
    for(int i = 0; i < N * M; i++){
        memo[i] = vector<int>((1 << M), -1);
    }
    cout << fill(0, 0);
    return 0;
}