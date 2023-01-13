#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 987654321

int N, M;
vector<int> candies;
vector<vector<vector<int>>> dpL, dpR; // l = sua is at left, r = sua is at right

int getDP(int i, int l, int r){
    if(i == 0){
        dpL[i][l][r] = 0;
        dpR[i][l][r] = 0;
        return 0;
    }
    // if(i == 0){
    //     dpL[i][l][r] = dpR[i][l][r] = 0;
    //     continue;
    // }
    // dpL[i][l][r] = min(
    //     dpL[i - 1][l - 1][r] + i * (candies[l] - candies[l - 1]),
    //     dpR[i - 1][l][r + 1] + i * (candies[r + 1] - candies[l])
    // );
    // dpR[i][l][r] = min(
    //     dpR[i - 1][l][r + 1] + i * (candies[r + 1] - candies[r]),
    //     dpL[i - 1][l - 1][r] + i * (candies[r] - candies[l - 1])
    // );
    if(l > 0){
        dpL[i][l][r] = dpL[i - 1][l - 1][r] + i * (candies[l] - candies[l - 1]);
        dpR[i][l][r] = dpL[i - 1][l - 1][r] + i * (candies[r] - candies[l - 1]);
    }
    if(r < N){
        dpL[i][l][r] = min(dpL[i][l][r],
                    dpR[i - 1][l][r + 1] + i * (candies[r + 1] - candies[l])
        );
        dpR[i][l][r] = min(dpR[i][l][r],
                    dpR[i - 1][l][r + 1] + i * (candies[r + 1] - candies[r])
        );
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    candies = vector<int>(N + 1);
    for(int i = 0; i < N; i++){
        cin >> candies[i];
    }
    candies[N] = 0;
    dpL = vector<vector<vector<int>>>(N + 1);
    dpR = vector<vector<vector<int>>>(N + 1);
    for(int i = 0; i <= N; i++){
        dpL[i] = vector<vector<int>>(N + 1);
        dpR[i] = vector<vector<int>>(N + 1);
        for(int j = 0; j <= N; j++){
            dpL[i][j] = vector<int>(N + 1, MAX);
            dpR[i][j] = vector<int>(N + 1, MAX);
        }     
    }
    sort(candies.begin(), candies.end());
    for(int i = 0; i <= N; i++){ // i = # of candies to eat
        for(int l = 0; l <= N; l++){
            for(int r = l; r <= N; r++){
                getDP(i, l, r);
            }
        }
    }
    int idx;
    for(int i = 0; i <= N; i++){
        if(candies[i] == 0){
            idx = i;
            break;
        }
    }
    int maxi = -1;
    for(int i = 0; i <= N; i++){
        maxi = max(maxi, i * M - min(dpL[i][idx][idx], dpR[i][idx][idx]));
    }
    cout << maxi;
    return 0;
}