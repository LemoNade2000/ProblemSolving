#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int N;
int ans;
vector<vector<bool>> board;

bool check(int row, int col){
    int it = 1;
    for(int i = row - 1; i >= 0; i--){
        if(col - it >= 0 && board[i][col - it]){
            return false;
        }
        if(board[i][col]){
            return false;
        }
        if(col + it < N && board[i][col + it]){
            return false;
        }
        it++;
    }
    if(row == N - 1){
        ans++;
    }
    return true;
}

int solve(int row){
    for(int i = 0; i < N; i++){
        if(check(row, i)){
            board[row][i] = true;
            solve(row + 1);
            board[row][i] = false;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    ans = 0;
    board = vector<vector<bool>>(N);
    for(int i = 0; i < N; i++){
        board[i] = vector<bool>(N, false);
    }
    solve(0);
    cout << ans;
    return 0;
}