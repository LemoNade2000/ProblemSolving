#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Node{
    ll lMax;
    ll rMax;
    ll sum;
    ll tMax;
    int idx;
    Node(){
        lMax = 0;
        rMax = 0;
        sum = 0;
        tMax = 0;
    };
    Node(int idx){
        this->idx = idx;
        lMax = 0;
        rMax = 0;
        sum = 0;
        tMax = 0;
    }
};

struct Coord{
    int x;
    int y;
    int idx;
    ll profit;
    Coord(int x, int y, ll profit, int idx){
        this->x = x;
        this->y = y;
        this->idx = idx;
        this->profit = profit;
    }
};

int N;
vector<Coord> mines;
vector<vector<Coord>> yMines;
vector<Node> tree;

bool compX(Coord &a, Coord &b){
    return a.x < b.x;
}

bool compY(Coord &a, Coord &b){
    return a.y < b.y;
}

Node update(int start, int end, int pos, ll val, int idx){
    if(start > pos || end < pos){
        return tree[idx];
    }
    if(start == end && start == pos){
        tree[idx].sum += val;
        tree[idx].lMax += val;
        tree[idx].rMax += val;
        tree[idx].tMax += val;
        return tree[idx];
    }
    int mid = (start + end) / 2;
    Node left = update(start, mid, pos, val, idx << 1);
    Node right = update(mid + 1, end, pos, val, (idx << 1) + 1);
    tree[idx].sum = left.sum + right.sum;
    tree[idx].lMax = max(left.lMax, left.sum + right.lMax);
    tree[idx].rMax = max(right.rMax, right.sum + left.rMax);
    tree[idx].tMax = max({left.tMax, right.tMax, left.rMax + right.lMax});
    return tree[idx];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        int x, y, p;
        cin >> x >> y >> p;
        mines.push_back(Coord(x, y, p, i));
    }
    sort(mines.begin(), mines.end(), &compX);
    int last = MOD;
    int compressed = 0;
    for(int i = 0; i < N; i++){
        if(mines[i].x != last){
            compressed++;
        }
        last = mines[i].x;
        mines[i].x = compressed;
    }
    sort(mines.begin(), mines.end(), &compY);
    last = MOD;
    compressed = 0;
    for(int i = 0; i < N; i++){
        if(mines[i].y != last){
            compressed++;
        }
        last = mines[i].y;
        mines[i].y = compressed;
    }
    yMines = vector<vector<Coord>>(compressed + 1);
    for(auto i : mines){
        yMines[i.y].push_back(i);
    }
    ll res = 0;
    tree = vector<Node>(N * 4, Node());
    for(int start = 0; start <= compressed; start++){
        for(int i = 0; i < N * 4; i++){
            tree[i] = Node(i);
        }
        for(int end = start; end <= compressed; end++){
            for(int i = 0; i < yMines[end].size(); i++){
                int targetX = yMines[end][i].x;
                ll targetP = yMines[end][i].profit;
                update(1, N, targetX, targetP, 1);
            }
            res = max(tree[1].tMax, res);
        }
    }
    cout << res;
}