#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<char>> board;
vector<vector<char>> sol;
vector<vector<int>> inDeg;
int R, C;
queue<pii> q;
ofstream output;

int count(pii point, vector<vector<char>> &board){
    int r = point.first;
    int c = point.second;
    int ret = 0;
    if(r > 0){
        if(board[r - 1][c] == '^'){
            ret++;
        }
    }
    if(r < R - 1){
        if(board[r + 1][c] == '^'){
            ret++;
        }
    }
    if(c > 0){
        if(board[r][c - 1] == '^'){
            ret++;
        }
    }
    if(c < C - 1){
        if(board[r][c + 1] == '^'){
            ret++;
        }
    }
    return ret;
}

bool check(pii point){
    int r = point.first;
    int c = point.second;
    if(board[r][c] == '^'){
        if(sol[r][c] == '^'){
            return true;
        }
        else if(sol[r][c] == '.'){
            return false;
        }
    }
    return true;
}

void initDeg(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            inDeg[i][j] = count({i, j}, sol);
            if(inDeg[i][j] < 2 && sol[i][j] == '^'){
                q.push({i, j});
            }
        }
    }
}

void erase(pii point){
    int r = point.first;
    int c = point.second;
    sol[r][c] = '.';
    int ret = 0;
    if(r > 0){
        if(sol[r - 1][c] == '^'){
            inDeg[r - 1][c]--;
            if(inDeg[r - 1][c] < 2){
                q.push({r - 1, c});
            }
        }
    }
    if(r < R - 1){
        if(sol[r + 1][c] == '^'){
            inDeg[r + 1][c]--;
            if(inDeg[r + 1][c] < 2){
                q.push({r + 1, c});
            }
        }
    }
    if(c > 0){
        if(sol[r][c - 1] == '^'){
            inDeg[r][c - 1]--;
            if(inDeg[r][c - 1] < 2){
                q.push({r, c - 1});
            }
        }
    }
    if(c < C - 1){
        if(sol[r][c + 1] == '^'){
            inDeg[r][c + 1]--;
            if(inDeg[r][c + 1] < 2){
                q.push({r, c + 1});
            }
        }
    }
}

int solve(){
    cin >> R >> C;
    while(!q.empty()){
        q.pop();
    }
    board = vector<vector<char>>(R);
    sol = vector<vector<char>>(R);
    inDeg = vector<vector<int>>(R);
    for(int i = 0; i < R; i++){
        board[i] = vector<char>(C);
        sol[i] = vector<char>(C);
        inDeg[i] = vector<int>(C, 0);
    }
    for(int i = 0; i < R; i++){
        string str;
        cin >> str;
        for(int j = 0; j < C; j++){
            board[i][j] = str[j];
            sol[i][j] = str[j];
            if(sol[i][j] == '.'){
                sol[i][j] = '^';
            }
        }
    }
    initDeg();

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        cout << r << " " << c << "\n";
        q.pop();
        erase({r, c});
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(!check({i, j})){
                output << "Impossible\n";
                return 0;
            }
        }
    }
    output << "Possible\n";
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            output << sol[i][j];
        }
        output << "\n";
    }
    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j < C; j++){
    //         cout <<  inDeg[i][j];
    //     }
    //     cout << "\n";
    // }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    output.open("output.txt"); 
    for(int tc = 1; tc <= TC; tc++){
        cout << "\n";
        output << "Case #" << tc << ": ";
        solve();
    }
    output.close();
    return 0;
}