#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 2000000000

struct Node{
    int idx;
    vector<int> dp;
    vector<Node*> adj;
    vector<bool> visit;
    Node(int idx){
        this->idx = idx;
        dp = vector<int>(24, MAX);
    }
};

vector<Node*> nodes;
int N;
int colorCnt;

int dfs(int idx, int preIdx, int color){
    if(nodes[idx]->dp[color] != MAX){
        return nodes[idx]->dp[color];
    }
    int childrenCost = 0;
    for(int i = 0; i < nodes[idx]->adj.size(); i++){
        Node* next = nodes[idx]->adj[i];
        int ret = MAX;
        if(next->idx == preIdx){
            continue;
        }
        for(int j = 1; j <= colorCnt; j++){
            if(j == color){
                continue;
            }
            ret = min(ret, dfs(next->idx, idx, j));
        }
        childrenCost += ret;
    }
    nodes[idx]->dp[color] = childrenCost + color;
    return nodes[idx]->dp[color];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    nodes = vector<Node*>(N + 1);
    for(int i = 1; i <= N; i++){
        nodes[i] = new Node(i);
    }
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        nodes[a]->adj.push_back(nodes[b]);
        nodes[b]->adj.push_back(nodes[a]);
    }
    colorCnt = ceil(log2(N));
    int ret = MAX;
    for(int i = 1; i <= colorCnt; i++){
        ret = min(ret, dfs(1, 0, i));
    }
    cout << ret;
    return 0;
}