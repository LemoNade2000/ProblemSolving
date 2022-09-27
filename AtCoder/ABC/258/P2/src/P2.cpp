#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<vector<int>> board;
ll ans;

void solve(int row, int col){
    ll ret = 0; // right
    for(int i = 0; i < N; i++){
        int r, c;
        c = ((col + i) + N) % N;
        r = row % N;
        ret = ret * 10 + board[r][c];
    }
    ans = max(ret, ans); // clockwise
    ret = 0;
    for(int i = 0; i < N; i++){
        int r, c;
        c = ((col + i) + N) % N;
        r = ((row + i) + N) % N;
        ret = ret * 10 + board[r][c];
    }
    ans = max(ret, ans);
    ret = 0;
    for(int i = 0; i < N; i++){
        int r, c;
        c = col % N;
        r = ((row + i) + N) % N;
        ret = ret * 10 + board[r][c];
    }
    ans = max(ret, ans);
    ret = 0;
    for(int i = 0; i < N; i++){
        int r, c;
        c = ((col - i) + N) % N;
        r = ((row + i) + N) % N;
        ret = ret * 10 + board[r][c];
    }
    ans = max(ret, ans);
    ret = 0;
    for(int i = 0; i < N; i++){
        int r, c;
        c = ((col - i) + N) % N;
        r = row % N;
        ret = ret * 10 + board[r][c];
    }
    ans = max(ret, ans);
    ret = 0;
    for(int i = 0; i < N; i++){
        int r, c;
        c = ((col - i) + N) % N;
        r = ((row - i) + N) % N;
        ret = ret * 10 + board[r][c];
    }
    ans = max(ret, ans);
    ret = 0;
    for(int i = 0; i < N; i++){
        int r, c;
        c = col % N;
        r = ((row - i) + N) % N;
        ret = ret * 10 + board[r][c];
    }
    ans = max(ret, ans);
    ret = 0;
    for(int i = 0; i < N; i++){
        int r, c;
        c = ((col + i) + N) % N;
        r = ((row - i) + N) % N;
        ret = ret * 10 + board[r][c];
    }
    ans = max(ret, ans);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    board.resize(N);
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        board[i].resize(N, 0);
        for(int j = 0; j < N; j++){
            board[i][j] = str[j] - '0';
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            solve(i, j);
        }
    }
    
    cout << ans;
    return 0;
}