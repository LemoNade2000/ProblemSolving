#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Node{
    int idx;
    int parent;
    int weight;
};

Node samples[100001];
int N, M;

pii findRoot(int node){
    if(samples[node].parent == samples[node].idx){
        return {node, samples[node].weight};
    }
    else{
        pii res = findRoot(samples[node].parent);
        samples[node].parent = res.first;
        samples[node].weight = res.second + samples[node].weight;
        return {samples[node].parent, samples[node].weight};
    }
}

void addSmp(int a, int b, int w){
    pii rootA = findRoot(a);
    pii rootB = findRoot(b);
    if(rootA.first == rootB.first){
        return;
    }
    int res = w + rootA.second - rootB.second;
    if(res < 0){
        samples[rootA.first].parent = rootB.first;
        samples[rootA.first].weight = -res;
        return;
    }
    else{
        samples[rootB.first].parent = rootA.first;
        samples[rootB.first].weight = res;
        return;
    }
    return;
}

int measure(int a, int b){
    pii rootA = findRoot(a);
    pii rootB = findRoot(b);
    if(rootA.first != rootB.first){
        cout << "UNKNOWN\n";
        return 0;
    }
    else{
        cout << rootB.second - rootA.second << "\n";
        return 0;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cin >> N >> M;
        if(N == 0 && M == 0){
            return 0;
        }
        for(int i = 1; i <= N; i++){
            samples[i] = {i, i, 0};
        }
        for(int i = 0; i < M; i++){
            char op;
            cin >> op;
            if(op == '!'){
                int a, b, w;
                cin >> a >> b >> w;
                addSmp(a, b, w);
            }
            else if(op == '?'){
                int a, b;
                cin >> a >> b;
                measure(a, b);
            }
        }
    }
    return 0;
}