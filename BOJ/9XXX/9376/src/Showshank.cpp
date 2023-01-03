#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 7654321

struct Node{
    int r, c;
    char symbol;
    vector<Node*> adj;
};

int TC;
vector<vector<char>> board;
int R, C;
pii criminalA, criminalB;
vector<vector<Node*>> nodes;

int getCost(pii coord){
    int r = coord.first;
    int c = coord.second;
    char symbol = board[r][c];
    if(symbol == '.' || symbol == '$'){
        return 0;
    }
    else if(symbol == '#'){
        return 1;
    }
    else if(symbol == '*'){
        return MAX;
    }
}

void initBoard(vector<vector<int>> &cost, pii coord){
    cost = vector<vector<int>>(R + 2);
    for(int i = 0; i < R + 2; i++){
        cost[i] = vector<int>(C + 2, -1);
    }
    priority_queue<pair<int, pii>> pq;
    pq.push({0, coord});
    while(!pq.empty()){
        pii pos = pq.top().second;
        int doors = pq.top().first;
        int row = pos.first;
        int col = pos.second;
        pq.pop();
        if(cost[row][col] != -1){
            continue;
        }
        cost[row][col] = -doors;
        if(row < R + 1){ // can go down
            int moveCost = getCost({row + 1, col});
            pq.push({doors - moveCost, {row + 1, col}});
        }
        if(row > 0){ // can go up
            int moveCost = getCost({row - 1, col});
            pq.push({doors - moveCost, {row - 1, col}});
        }
        if(col < C + 1){ // can go right
            int moveCost = getCost({row, col + 1});
            pq.push({doors - moveCost, {row, col + 1}});
        }
        if(col > 0){ // can go left
            int moveCost = getCost({row, col - 1});
            pq.push({doors - moveCost, {row, col - 1}});
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        criminalA = {-1, -1};
        criminalB = {-1, -1};
        cin >> R >> C;
        board = vector<vector<char>>(R + 2);
        for(int i = 0; i < R + 2; i++){
            board[i] = vector<char>(C + 2, '.');
        }
        for(int i = 0; i < R; i++){
            string str;
            cin >> str;
            for(int j = 0; j < C; j++){
                board[i + 1][j + 1] = str[j];
                if(str[j] == '$'){
                    if(criminalA.first == -1){
                        criminalA = {i + 1, j + 1};
                    }
                    else{
                        criminalB = {i + 1, j + 1};
                    }
                }
            }
        }

        vector<vector<int>> costOutside, costA, costB;
        initBoard(costOutside, {0, 0}); // cost to reach common ground
        initBoard(costA, criminalA); // cost for A to move
        initBoard(costB, criminalB); // cost for B to move
        int mini = MAX;
        for(int i = 0; i < R + 2; i++){
            for(int j = 0; j < C + 2; j++){
                int doorAdjust = 0;
                if(board[i][j] == '#'){
                    doorAdjust = -2;
                }
                mini = min(mini, costOutside[i][j] + costA[i][j] + costB[i][j] + doorAdjust);
            }
        }
        cout << mini;
        cout << "\n";
    }
    return 0;
}