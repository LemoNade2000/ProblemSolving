#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int W, H;
vector<vector<char>> board;
vector<pii> dirty;
pii start;
vector<vector<int>> dist;

int dfs(pii coord, int step, int idx){
    for(int i = 0; i < dirty.size(); i++){
        if(coord == dirty[i]){
            dist[idx][i] = min(dist[idx][i], step);
        }
    }
}

int solve(){
    if(W == 0 && H == 0){
        return 0;
    }
    board = vector<vector<char>>(H);
    for(int i = 0; i < H; i++){
        board[i] = vector<char>(W);
        string str;
        cin >> str;
        for(int j = 0; j < W; j++){
            board[i][j] = str[j];
            if(str[j] == '*'){
                dirty.push_back({i, j});
            }
            else if(str[j] == 'o'){
                start = {i, j};
            }
        }
    }
    dist = vector<vector<int>>(dirty.size() + 1);
    for(int i = 0; i <= dirty.size(); i++){
        dist[i] = vector<int>(dirty.size() + 1, INT_MAX);
        dist[i][i] = 0;
    }
    dfs(start, 0, dirty.size());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> W >> H){
        solve();
    }
    return 0;
}