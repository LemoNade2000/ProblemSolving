#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, M;
ll X[5001];
ll Y[5001];
ll memo[5001][5001];

ll max(ll a, ll b){
    if(a > b){
        return a;
    }
    else return b;
}

ll fill(int count, int streak){
    if(count == N){
        return 0;
    }
    else if(memo[count][streak] != -1){
        return memo[count][streak];
    }
    return memo[count][streak] = max(fill(count + 1, 0), X[count + 1] + Y[streak + 1] + fill(count + 1, streak + 1));

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < 5001; i++){
        for(int j = 0; j < 5001; j++){
            memo[i][j] = -1;
        }
        Y[i] = 0;
    }
    for(int i = 1 ; i <= N; i++){
        cin >> X[i];
    }
    for(int i = 1; i <= M; i++){
        int c;
        cin >> c;
        cin >> Y[c];
    }
    cout << fill(0, 0);
    return 0;
}