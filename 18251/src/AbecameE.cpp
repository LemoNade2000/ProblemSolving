#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N;
vector<ll> weight[25];
vector<ll> arr;
vector<bool> visited;
ll minimum, maxDiff, sum;

int dfs(int top, int bottom, int idx, int height){
    if(height == bottom){
        sum += arr[idx];
        maxDiff = max(maxDiff, sum - minimum);
        minimum = min(minimum, sum);
        return 0;
    }
    dfs(top, bottom, idx * 2, height + 1);
    sum += arr[idx];
    maxDiff = max(maxDiff, sum - minimum);
    minimum = min(minimum, sum);
    dfs(top, bottom, idx * 2 + 1, height + 1);
    return 0;
}

ll getRectangle(int bottom, int top){
    int height = top - bottom;
//    visited = vector<bool>(N + 1, false);
    minimum = sum = 0;
    maxDiff = LLONG_MIN;
    int idx = (1 << (top - 1));
    for(int i = 0; i < weight[top].size(); i++){
    //    cout << idx << " ";
        dfs(top, bottom, idx, top);
        idx++;
    }
    return maxDiff;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    if(N == 1){
        int a;
        cin >> a;
        cout << a;
        return 0;
    }
    arr.push_back(0);
    for(int i = 0; (1 << i) < N; i++){
        for(int j = 0; j < (1 << i); j++){
            ll a;
            cin >> a;
            weight[i + 1].push_back(a);
            arr.push_back(a);
        }
    }
    ll ans = LLONG_MIN;
    for(int height = 0; (1 << height) < N; height++){
        int bottom = log2(N + 1);
        for(int top = bottom - height; top > 0; bottom--, top--){
        //    cout << bottom << " " << top << "\n";
            ans = max(getRectangle(bottom, top), ans);
        }
    }
    cout << ans;
    return 0;
}