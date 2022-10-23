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

int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
string str;
int lineCnt;
vector<vector<vector<int>>> dp;
ll ans;

ll power(ll a, ll pow){
    ll res = 1;
    if(a == 1) return 1;
    while(pow > 0){
        if(pow & 1 == 1){
            res = (res * a);
        }
        a = (a * a);
        pow = pow >> 1;
    }
    return res;
}

ll fillDP(int pos, int diff, int over){
    // cout << pos << diff;
    if(diff < 0){
        return 10;
    }
    if(pos == str.size()){
        if(diff == 0 && over == 1){
            return 0;
        }
        else return 10;
    }
    if(dp[pos][diff][over] != -1){
        return dp[pos][diff][over];
    }
    dp[pos][diff][over] = 10;
    int dig;
    if(over == 1){
        dig = 0;
    }
    else{
        dig = str[pos] - '0';
    }
    for(; dig < 10; dig++){
        bool overNext = false;
        if(over == 1 || dig > str[pos] - '0'){
            overNext = true;
        }
        int ret = fillDP(pos + 1, diff - arr[dig], overNext);
        if(ret != 10){
            dp[pos][diff][over] = dig;
            break;
        }
    }
    return dp[pos][diff][over];
}

void initDP(){
    dp = vector<vector<vector<int>>>(16);
    for(int i = 0; i < 16; i++){
        dp[i] = vector<vector<int>>(106);
        for(int j = 0; j < 106; j++){
            dp[i][j] = vector<int>(2, -1);
        }
    }
    return;
}

void backtrack(int pos, int diff, int over){
    if(pos == str.size()){
        return;
    }
    int currDig = dp[pos][diff][over];
    ans = ans * 10 + currDig;
    if(currDig > str[pos] - '0' || over){
        over = true;
    }
    backtrack(pos + 1, diff - arr[currDig], over);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    lineCnt = 0;
    initDP();
    for(int i = 0; i < str.size(); i++){
        lineCnt += arr[str[i] - '0'];
    }
    string original = str;
    str = "";
    for(int i = 0; i < original.size(); i++){
        str.push_back('0');
    }
    ll finalAns = 0;
    ans = 0;
    fillDP(0, lineCnt, 0);
    backtrack(0, lineCnt, 0);
    finalAns = ans + power(10, original.size()) - stoll(original);
    initDP();
    str = original;
    if(fillDP(0, lineCnt, 0) != 10){
        ans = 0;
        backtrack(0, lineCnt, 0);
        finalAns = ans - stoll(original);
    }
    cout << finalAns << "\n";
    return 0;
}