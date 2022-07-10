#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;
int N, M;
int K;



int solve(){
    ll ans = 0;
    cin >> N;
    vector<vector<ll>> dpA;
    dpA.resize(N + 1);
    for(int i = 0; i <= N; i++){
        dpA[i].resize(N + 1, -1);
    }
    vector<ll> maxA;
    maxA.resize(N + 1, -1);
    vector<int> A, B;
    dpA[0][0] = 0;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        A.push_back(n);
        dpA[i + 1][0] = dpA[i][0] + n;
        maxA[i + 1] = dpA[i + 1][0];
    }
    cin >> M;
    vector<vector<ll>> dpB;
    vector<ll> maxB;
    maxB.resize(M + 1, -1);
    dpB.resize(M + 1);
    for(int i = 0; i <= M; i++){
        dpB[i].resize(M + 1, -1);
    }
    dpB[0][0] = 0;
    for(int i = 0; i< M; i++){
        int n;
        cin >> n;
        B.push_back(n);
        dpB[i + 1][0] = dpB[i][0] + n;
        maxB[i + 1] = dpB[i + 1][0];
    }
    cin >> K;
    for(int i = 0; i <= N; i++){
        for(int j = 1; j + i <= N; j++){
            if(i == 0 && j == 0){
                continue;
            }
            dpA[i][j] = dpA[i][j - 1] + A[N - j];
            if(dpA[i][j] > maxA[i + j]){
                maxA[i + j] = dpA[i][j];
            }
        }
        if(dpA[i][0] > maxA[i]){
            maxA[i] = dpA[i][0];
        }
    }
    for(int i = 0; i <= M; i++){
        for(int j = 1; j + i <= M; j++){
            if(i == 0 && j == 0){
                continue;
            }
            dpB[i][j] = dpB[i][j - 1] + B[M - j];
            if(dpB[i][j] > maxB[i + j]){
                maxB[i + j] = dpB[i][j];
            }
        }
        if(dpB[i][0] > maxB[i]){
            maxB[i] = dpB[i][0];
        }
    }
    for(int i = 0; i <= K; i++){
        if(i > N || K - i > M){
            continue;
        }
        ans = max(ans, maxA[i] + maxB[K - i]);
    }
    cout << ans << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}