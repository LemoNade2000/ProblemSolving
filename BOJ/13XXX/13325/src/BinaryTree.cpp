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

int height;
vector<int> weight;
vector<int> dp;
ll maxi;
ll sum;

int evenTree(int idx, int h, ll obj){
    if(h == height){
        return dp[idx];
    }
    else{
        int left = evenTree(idx * 2, h + 1, obj);
        int right = evenTree(idx * 2 + 1, h + 1, obj);
        sum += max(left, right) - min(left, right);
        return max(left, right);
    }
}

ll max(int a, ll b){
    if(b >= a){
        return b;
    }
    else return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> height;
    sum = 0;
    weight = vector<int>((1 << (height + 1)));
    dp = vector<int>((1 << (height + 1)));
    for(int i = 2; i < (1 << (height + 1)); i++){
        cin >> weight[i];
        sum += weight[i];
    }
    maxi = 0;
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i < (1 << (height + 1)); i++){
        dp[i] = dp[(i >> 1)] + weight[i];
    }
    for(int i = 1; i < (1 << (height + 1)); i++){
        maxi = max(dp[i], maxi);
    }
    evenTree(1, 0, maxi);
    cout << sum;
    return 0;
}