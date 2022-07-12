#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;
int N, K;
vector<int> A, B;
ll dp[3001][3001];
ll sumX[3001][3001];
ll sumY[3001][3001];
int lowerA[3001];
int lowerB[3001];

int solve(){
    cin >> N >> K;
    int cnt = 0;
    A.resize(N + 1, 0); B.resize(N + 1, 0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> B[i];
    }
    for(int i = 1; i <= N; i++){
        int sum = 0; int idx = i;
        while(idx > 0){
            sum += A[idx];
            if(sum > K){
                break;
            }
            idx--;
        }
        lowerA[i] = idx;
    }
    for(int i = 1; i <= N; i++){
        int sum = 0; int idx = i;
        while(idx > 0){
            sum += B[idx];
            if(sum > K){
                break;
            }
            idx--;
        }
        lowerB[i] = idx;
    }
    /*
    for(int i = 1; i <= N; i++){
        cout << lowerA[i] << " ";
    }
    cout << "\n";
    for(int j = 1; j <= N; j++){
        cout << lowerB[j] << " ";
    }
    cout << "\n";
    */
    dp[0][0] = 1; dp[1][0] = 0; dp[0][1] = 0; dp[1][1] = 1;
    sumX[0][0] = 1; sumY[0][0] = 1;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(i == 0 && j == 0){
                continue;
            }
            if(i > 0){ // deck A
                int low = lowerA[i];
                // dp[low][j] + dp[low + 1][j] ... dp[i - 1][j]
                int sumLeft, sumRight;
                sumLeft = sumX[low][j];
                sumRight = sumX[i - 1][j];
                if(sumRight - sumLeft + dp[low][j]< i - low){
                    dp[i][j] = 1;
                    sumX[i][j] = sumX[i - 1][j] + 1;
                    sumY[i][j] = sumY[i][j - 1] + 1;
                    cnt++;
                    continue;
                }
                else if(sumRight - sumLeft + dp[low][j] == i - low){
                    dp[i][j] = 0;
                    sumX[i][j] = sumX[i - 1][j];
                    sumY[i][j] = sumY[i][j - 1];
                }
            }
            if(j > 0){ // deck B
                int low = lowerB[j];
                // dp[low][j] + dp[low + 1][j] ... dp[i - 1][j]
                int sumLeft, sumRight;
                sumLeft = sumY[i][low];
                sumRight = sumY[i][j - 1];
                if(sumRight - sumLeft + dp[i][low]< j - low){
                    dp[i][j] = 1;
                    sumX[i][j] = sumX[i - 1][j] + 1;
                    sumY[i][j] = sumY[i][j - 1] + 1;
                    cnt++;
                    continue;
                }
                else if(sumRight - sumLeft + dp[i][low] == j - low){
                    dp[i][j] = 0;
                    sumX[i][j] = sumX[i - 1][j];
                    sumY[i][j] = sumY[i][j - 1];
                }
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        cout << "Case #" << tc << "\n";
        solve();
        int cnt = 0;
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                if(dp[i][j] == 1){
                    cnt++;
                }
            }
        }
        cout << cnt << " " << (N + 1) * (N + 1) - cnt << "\n";
    }
    return 0;
    
}