#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Node;
struct Edge;

struct Node{
    int row, col;
    bool visited;
    int step;
    vector<Edge*> adj;
    Node(int r, int c){
        this->row = r;
        this->col = c;
        visited = false;
        step = -1;
    }
};

struct Edge{
    Node* start;
    Node* end;
    Edge(Node* start, Node* end){
        this->start = start;
        this->end = end;
    }
};

vector<vector<Node*>> board;
int destRow, destCol;
int startRow, startCol;

bool check(int row, int col){
    if(row == destRow && col == destCol){
        return false;
    }
    else return true;
}

void addEdge(int r, int c){
    if(r - 3 >= 0 && c + 2 < 9){
        if(check(r - 1, c) && check(r - 2, c + 1)){
            Edge* e = new Edge(board[r][c], board[r - 3][c + 2]);
            board[r][c]->adj.push_back(e);
            // Edge* re = new Edge(board[r - 3][c + 2], board[r][c]);
            // board[r - 3][c + 2]->adj.push_back(re);
        }
    }
    if(r - 2 >= 0 && c + 3 < 9){
        if(check(r, c + 1) && check(r - 1, c + 2)){
            Edge* e = new Edge(board[r][c], board[r - 2][c + 3]);
            board[r][c]->adj.push_back(e);
            // Edge* re = new Edge(board[r - 2][c + 3], board[r][c]);
            // board[r - 2][c + 3]->adj.push_back(re);
        }
    }
    if(r + 2 < 10 && c + 3 < 9){
        if(check(r, c + 1) && check(r + 1, c + 2)){
            Edge* e = new Edge(board[r][c], board[r + 2][c + 3]);
            board[r][c]->adj.push_back(e);
            // Edge* re = new Edge(board[r + 2][c + 3], board[r][c]);
            // board[r + 2][c + 3]->adj.push_back(re);
        }
    }
    if(r + 3 < 10 && c + 2 < 9){
        if(check(r + 1, c) && check(r + 2, c + 1)){
            Edge* e = new Edge(board[r][c], board[r + 3][c + 2]);
            board[r][c]->adj.push_back(e);
            // Edge* re = new Edge(board[r + 3][c + 2], board[r][c]);
            // board[r + 3][c + 2]->adj.push_back(re);
        }
    }
    if(r + 3 < 10 && c - 2 >= 0){
        if(check(r + 1, c) && check(r + 2, c - 1)){
            Edge* e = new Edge(board[r][c], board[r + 3][c - 2]);
            board[r][c]->adj.push_back(e);
            // Edge* re = new Edge(board[r + 3][c - 2], board[r][c]);
            // board[r + 3][c - 2]->adj.push_back(re);
        }
    }
    if(r + 2 < 10 && c - 3 >= 0){
        if(check(r, c - 1) && check(r + 1, c - 2)){
            Edge* e = new Edge(board[r][c], board[r + 2][c - 3]);
            board[r][c]->adj.push_back(e);
            // Edge* re = new Edge(board[r + 2][c - 3], board[r][c]);
            // board[r + 2][c - 3]->adj.push_back(re);
        }
    }
    if(r - 2 >= 0 && c - 3 >= 0){
        if(check(r, c - 1) && check(r - 1, c - 2)){
            Edge* e = new Edge(board[r][c], board[r - 2][c - 3]);
            board[r][c]->adj.push_back(e);
            // Edge* re = new Edge(board[r - 2][c - 3], board[r][c]);
            // board[r - 2][c - 3]->adj.push_back(re);
        }
    }
    if(r - 3 >= 0 && c - 2 >= 0){
        if(check(r - 1, c) && check(r - 2, c - 1)){
            Edge* e = new Edge(board[r][c], board[r - 3][c - 2]);
            board[r][c]->adj.push_back(e);
            // Edge* re = new Edge(board[r - 3][c - 2], board[r][c]);
            // board[r - 3][c - 2]->adj.push_back(re);
        }
    }
    return;
}

int bfs(){
    queue<Node*> q;
    q.push(board[startRow][startCol]);
    board[startRow][startCol]->step = 0;
    while(!q.empty()){
        Node* currNode = q.front();
        q.pop();
        if(currNode->visited){
            continue;
        }
        // cout << currNode->row << " " << currNode->col << " " << currNode->step << "\n";
        currNode->visited = true;
        for(auto edge : currNode->adj){
            if(edge->end->visited == false){
                q.push(edge->end);
                edge->end->step = currNode->step + 1;
            }
        }
    }
    return board[destRow][destCol]->step;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> startRow >> startCol;
    cin >> destRow >> destCol;
    board = vector<vector<Node*>>(10);
    for(int row = 0; row < 10; row++){
        board[row] = vector<Node*>(9);
        for(int col = 0; col < 9; col++){
            board[row][col] = new Node(row, col);
        }
    }
    for(int row = 0; row < 10; row++){
        for(int col = 0; col < 9; col++){
            addEdge(row, col);
        }
    }
    cout << bfs();
    return 0;
}