#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll N, H;
ll realN;
ll E;
vector<ll> arr;
ll ans;
ll memo[202020][3]; // 0 = energy - use, 1 = E, 2 = E - arr[stone];

ll solve(ll pos, ll energy, ll stone, int type){
    //cout << pos << " " << energy << " " << stone << " " << type << "\n";
    if(memo[stone][type] != LLONG_MAX){
    //    cout << "Inf: " << stone << " " << type << "\n";
        return memo[stone][type];
    }
    if(stone >= realN){
        return 0;
    }
    ll use = (arr[stone] < pos) ? 0 : arr[stone] - pos; 
    ll a, b, c;
    a = b = c = LLONG_MAX;
    if(energy >= use){
        a = abs(arr[stone] - pos) + solve(arr[stone], energy - use, stone + 1, 0);
    }
    if(energy >= H - pos && energy != E){
        b = (H - pos) + (H - arr[stone]) + solve(arr[stone], E, stone + 1, 1);
    }
    if(E - arr[stone] > energy - use && energy != E){
        c = pos + arr[stone] + solve(arr[stone], E - arr[stone], stone + 1, 2);
    }
    cout << stone << " " << type << " " << min({a, b, c}) << "\n";
    return memo[stone][type] = min({a, b, c});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> E >> H >> N;
    ans = LLONG_MAX;
    for(int i = 0; i < 200001; i++){
        memo[i][0] = memo[i][1] = memo[i][2] = LLONG_MAX;
    }
    arr.push_back(0);
    for(int i = 1; i <= N ; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    arr.push_back(0);
    realN = arr.size();
    solve(0, E, 1, 1);
    cout << memo[1][1];
    for(int i = 1; i < realN; i++){
        cout << memo[i][0] << " " << memo[i][1] << " " << memo[i][2] << "\n";
    }
    return 0;
}