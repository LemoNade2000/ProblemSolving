#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

struct Move{
    int time;
    char dir;
};

struct Block{
    int row, col;
    bool apple;
    bool occupied;
    Block(int row, int col){
        this->row = row;
        this->col = col;
        this->apple = false;
        this->occupied = false;
    }
};

int N, K, L;
int hor, ver;
int sec;
vector<pii> apples;
vector<Move> moves;
vector<vector<Block*>> board;
deque<pii> snake;

bool move(pii dir){
    sec++;
    pii head = snake.front();
    pii nextHead = {head.first + dir.first, head.second + dir.second};
    pii tail = snake.back();
    if(nextHead.first == 0 || nextHead.first > N || nextHead.second == 0 || nextHead.second > N){
        return false;
    }
    if(board[nextHead.first][nextHead.second]->occupied){
        return false;
    }
    if(board[nextHead.first][nextHead.second]->apple == true){
        snake.push_front(nextHead);
        board[nextHead.first][nextHead.second]->apple = false;
        board[nextHead.first][nextHead.second]->occupied = true;
        return true;
    }
    else{
        snake.push_front(nextHead);
        board[nextHead.first][nextHead.second]->occupied = true;
        board[tail.first][tail.second]->occupied = false;
        snake.pop_back();
        return true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    board = vector<vector<Block*>>(N + 1);
    for(int i = 1; i <= N; i++){
        board[i] = vector<Block*>(N + 1);
        for(int j = 1; j <= N; j++){
            board[i][j] = new Block(i, j);
        }
    }
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        board[b][a]->apple = true;
    }
    cin >> L;
    for(int i = 0; i < L; i++){
        int t;
        char c;
        cin >> t >> c;
        moves.push_back({t, c});
    }
    board[1][1]->occupied = true;
    snake.push_front({1, 1});
    hor = 1; ver = 0;
    sec = 0;
    auto it = moves.begin();
    while(true){
        if(it != moves.end() && sec == it->time){
            if(hor == 1 && ver == 0){
                if(it->dir == 'L'){
                    hor = 0; ver = -1;
                }
                else if(it->dir == 'D'){
                    hor = 0; ver = 1;
                }
            }
            else if(hor == 0 && ver == 1){
                if(it->dir == 'L'){
                    hor = 1; ver = 0;
                }
                else if(it->dir == 'D'){
                    hor = -1; ver = 0;
                }
            }
            else if(hor == -1 && ver == 0){
                if(it->dir == 'L'){
                    hor = 0; ver = 1;
                }
                else if(it->dir == 'D'){
                    hor = 0; ver = -1;
                }
            }
            else if(hor == 0 && ver == -1){
                if(it->dir == 'L'){
                    hor = -1; ver = 0;
                }
                else if(it->dir == 'D'){
                    hor = 1; ver = 0;
                }
            }
            it++;
        }
        if(move({hor, ver})== false){
            cout << sec;
            return 0;
        }
    }
    return 0;
}