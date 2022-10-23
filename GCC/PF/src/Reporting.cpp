# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct Node{
    int idx;
    int parent;
    int cnt;
    int rank;
    Node(){
        this->idx = 0;
        this->parent = 0;
        this->cnt = 1;
        this->rank = 1;     
    }
};

int N;
vector<Node> nodes;

int find(int n){
    if(nodes[n].parent == n){
        return n;
    }
    else return nodes[n].parent = find(nodes[n].parent);
}

int unionNode(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
        return 0;
    }
    if(nodes[u].rank > nodes[v].rank){
        swap(u, v);
    }
    nodes[v].cnt += nodes[u].cnt;
    nodes[u].parent = v;
    if(nodes[u].rank == nodes[v].rank){
        nodes[v].rank++;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    nodes = vector<Node>(N + 1);
    for(int i = 1; i <= N; i++){
        nodes[i].parent = i;
        nodes[i].idx = i;
    }
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        unionNode(i, n);
    }
    for(int i = 1; i <= N; i++){
        cout << nodes[find(i)].cnt << " ";
    }
    return 0;
}