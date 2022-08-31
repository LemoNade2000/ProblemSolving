#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int N, P, M, sRow, sCol;
pair<char, ll> north, east, west, south;
ll maxi;
vector<vector<ll>> maxCoin;

ll calc(char op, ll coef, ll base){
    if(op == '+'){
        return base + coef;
    }
    else if(op == '*'){
        return base * coef;
    }
    else if(op == '-'){
        return base - coef;
    }
    else if(op == '/'){
        return base / coef;
    }
}

int dfs(int row, int col, int time, ll coin){
    maxi = max(maxi, coin);
    if(coin <= maxCoin[row][col]){
        return 0;
    }
    maxCoin[row][col] = coin;
    if(row == sRow && col == sCol && coin < 0){
        return 0;
    }
    if(time == M){
        return 0;
    }
    if(row > 1){
        ll newcoin = calc(north.first, north.second, coin);
        dfs(row - 1, col, time + 1, newcoin);
    }
    if(col > 1){
        ll newcoin = calc(west.first, west.second, coin);
        dfs(row, col - 1, time + 1, newcoin);
    }
    if(row < N){
        ll newcoin = calc(south.first, south.second, coin);
        dfs(row + 1, col, time + 1, newcoin);
    }
    if(col < N){
        ll newcoin = calc(east.first, east.second, coin);
        dfs(row, col + 1, time + 1, newcoin);
    }
    return 0;
}

int solve(){
    cin >> N >> P >> M >> sRow >> sCol;
    cin >> north.first >> north.second >> east.first >> east.second;
    cin >> west.first >> west.second >> south.first >> south.second;
    maxi = 0;
    maxCoin = vector<vector<ll>>(N + 1);
    for(int i = 1; i <= N; i++){
        maxCoin[i] = vector<ll>(N + 1, LLONG_MIN);
    }
    dfs(sRow, sCol, 0, 0);
    cout << maxi;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        cout << "Case #" << tc << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}