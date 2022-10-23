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

int N, limit;
vector<int> arr;
vector<vector<vector<int>>> dp; // dp[i][j] : with i-segments left, maximum from index j
vector<int> compact;

int maximumSubseq(int start, int end){
    int ret = 0;
    int sum = 0;
    for(int i = start; i <= end; i++){
        sum += compact[i];
        ret = max(ret, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return ret;
}

int fillDP(int cond, int start, int end, int chance){
    if(start > end || chance == 0){
        return 0;
    }
    else if(start == end){
        return compact[start];
    }
    if(dp[cond][start][chance] != -1){
        return dp[cond][start][chance];
    }
    if(cond == 0){
        if(chance == 1){
            dp[cond][start][chance] = maximumSubseq(start, end);
            return dp[cond][start][chance];
        }
        dp[cond][start][chance] = max({fillDP(0, start + 2, end, chance),
        fillDP(1, start + 2, end, chance - 1) + compact[start] + compact[start + 1],
        fillDP(0, start + 2, end, chance - 1) + compact[start]
        });
        return dp[cond][start][chance];
    }
    else if(cond == 1){
        dp[cond][start][chance] = max(
        fillDP(1, start + 2, end, chance) + compact[start] + compact[start + 1],
        fillDP(0, start + 2, end, chance) + compact[start]
        );
        return dp[cond][start][chance];
    }
    // if(chance == 0){
    //     return dp[start][chance] = maximumSubseq(start, end);
    // }
    // dp[start][chance] = max(fillDP(start + 2, end, chance) + compact[start] + compact[start + 1], fillDP(start + 2, end, chance - 1) + compact[start]);
    // return dp[start][chance];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> limit >> N;
    arr = vector<int>(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    if(limit == 0){
        cout << "0\n";
        return 0;
    }
    int increasing = 0; // 0 - neutral 1 - inc -1 - dec
    int nextIncrease = 0;
    int prev = arr[0];
    int s = 0;
    for(int i = 1; i < N; i++){
        if(arr[i] > prev){
            nextIncrease = 1;
        }
        else if(arr[i] == prev){
            continue;
        }
        else{
            nextIncrease = -1;
        }
        if(increasing != nextIncrease){
            if(s != 0){
                compact.push_back(increasing * s);
            }
            s = 0;
            increasing = nextIncrease;
        }
        s += abs(arr[i] - prev);
        prev = arr[i];
    }
    if(s != 0){
        compact.push_back(increasing * s);
    }
    int start = 0;
    int end = compact.size() - 1;
    if(compact.empty()){
        cout << "0\n";
        return 0;
    }
    if(compact[0] < 0){
        start++;
    }
    if(compact[end] < 0){
        end--;
    }
    if((end - start + 2) / 2 <= limit){
        int sum = 0;
        for(;start <= end; start += 2){
            sum  += compact[start];
        }
        cout << sum;
        return 0;
    }
    dp = vector<vector<vector<int>>>(2);
    for(int i = 0; i < 2; i++){
        dp[i] = vector<vector<int>>(end + 1);
        for(int j = 0; j <= end; j++){
            dp[i][j] = vector<int>(limit + 1, -1);
        }
    }
    cout << fillDP(0, start, end, limit);
    return 0;
}