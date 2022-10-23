# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int N;
vector<int> grundy; // starter wins if 1 with state [i], loses if 0
vector<vector<int>> divisor;

int fillDP(int n){
    if(n == N){
        grundy[N] = 0;
    }
    bool flag = false;
    for(int i = 0; i < divisor[n].size() && n + divisor[n][i] <= N; i++){
        if(grundy[n + divisor[n][i]] == 0){
            flag = true;
            break;
        }
    }
    if(flag) grundy[n] = 1;
    return 0;
}

bool comp(int a, int b){
    return a < b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    grundy = vector<int>(100001, 0);
    divisor = vector<vector<int>>(100001);
    for(int i = 1; i < N ;i++){
        divisor[i] = vector<int>(0);
        for(int j = 1; j <= sqrt(N); j++){
            if(i % j == 0){
                divisor[i].push_back(i / j);
                divisor[i].push_back(j);
            }
        }
        sort(divisor[i].begin(), divisor[i].end(), comp);
    }
    for(int i = N; i >= 1; i--){
        fillDP(i);
    }
    if(grundy[1] == 1){
        cout << "Kali";
    }
    else cout << "Ringo";
    return 0;
}