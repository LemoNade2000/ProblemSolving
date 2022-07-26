#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N;
struct Shark{
    int a, b, c;
};
vector<Shark> arr;
vector<int> adj[110];
int limit[110][110];
int flow[110][110];
int level[110];
int lastEdge[110];

bool bfs(int start, int end){
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(0);
    level[start] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto next : adj[node]){
            if(level[next] == -1 && limit[node][next] - flow[node][next] > 0){
                level[next] = level[node] + 1;
                q.push(next);
            }
        }
    }
    if(level[end] == -1){
        return false;
    }
    return true;
}

int dfs(int curr, int end, int minF){
    if(curr == end){
        return minF;
    }
    for(int &i = lastEdge[curr]; i < adj[curr].size(); i++){
        int next = adj[curr][i];
        if(level[next] == level[curr] + 1 && limit[curr][next] - flow[curr][next] > 0){
            int ret = dfs(next, end, min(minF, limit[curr][next] - flow[curr][next]));
            if(ret > 0){
                flow[curr][next] += ret;
                flow[next][curr] -= ret;
                return ret;
            }
        }
    }
    lastEdge[curr] = adj[curr].size();
    return 0;
}

int dinik(int start, int end){
    int ans = 0;
    while(bfs(start, end)){
        memset(lastEdge, 0, sizeof(lastEdge));
        while(true){
            int temp = dfs(start, end, INT_MAX);
            if(temp == 0){
                break;
            }
            ans += temp;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(adj, 0, sizeof(adj));
    memset(flow, 0, sizeof(flow));
    cin >> N;
    arr = vector<Shark>(N + 2);
    for(int i = 1; i <= N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }
    for(int i = 1; i <= N; i++){
        limit[0][i] = 2;
        adj[0].push_back(i);
        limit[i + 55][109] = 1;
        adj[i + 55].push_back(109);
        for(int j = 1; j <= N; j++){
            if(i == j){
                continue;
            }
            if(arr[i].a >= arr[j].a && arr[i].b >= arr[j].b && arr[i].c >= arr[j].c){
                if(arr[i].a == arr[j].a && arr[i].b == arr[j].b && arr[i].c == arr[j].c){
                    if(i > j){
                        continue;
                    }
                }
                limit[i][j + 55] = 1;
                adj[i].push_back(j + 55);
                adj[j + 55].push_back(i);
            }
        }
    }
    cout << N - dinik(0, 109);
    
    return 0;
}

