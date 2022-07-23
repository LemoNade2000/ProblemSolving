#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N;
int dp[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= N; i++){
        int left = 0;
        int right = i - 2;
        vector<bool> mex = vector<bool>(16, false);
        while(left <= right){
            mex[dp[left] ^ dp[right]] = true;
            left++;
            right--;
        }
        for(int k = 0; k < 16; k++){
            if(mex[k] == false){
                dp[i] = k;
                break;
            }
        }
    }
    if(dp[N] == 0){
        cout << "2";
        return 0;
    }
    else{
        cout << "1";
        return 0;
    }
    return 0;
}