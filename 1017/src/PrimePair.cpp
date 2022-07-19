#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N;
vector<int> even, odd;
vector<int> adj[110];
vector<int> conn;
vector<int> revConn;
int mat[110][110];
vector<bool> visited;

bool isPrime(int a){
    if(a == 1){
        return false;
    }
    for(int i = 2; i - 1 <= sqrt(a); i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

bool dfs(int n){
    if(visited[n] == true) return false;
    visited[n] = true;
    for(int i = 0; i < adj[n].size(); i++){
        if(mat[n][adj[n][i]] == -1){
            continue;
        }
        if(revConn[adj[n][i]] == -1 || dfs(revConn[adj[n][i]])){
            conn[n] = adj[n][i];
            revConn[adj[n][i]] = n;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    memset(mat, 0, sizeof(mat));
    bool firstOdd = false;
    odd.push_back(0);
    even.push_back(0);
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        if(n & 1){
            if(i == 1){
                firstOdd = true;
            }
            odd.push_back(n);
        }
        else{
            even.push_back(n);
        }
    }
    if(odd.size() != even.size()){
        cout << "-1";
        return 0;
    }
    if(firstOdd){
        for(int i = 1; i <= N / 2; i++){
            for(int j = 1; j <= N / 2; j++){
                if(isPrime(odd[i] + even[j])){
                    adj[i].push_back(j + 54);
                }
            }
        }
    }
    else{
        for(int i = 1; i <= N / 2; i++){
            for(int j = 1; j <= N / 2; j++){
                if(isPrime(odd[j] + even[i])){
                    adj[i].push_back(j + 54);
                }
            }
        }
    }
    int cnt = 0;
    vector<int> ansVec;
    while(true){
        int ans = 0;
        bool flag = true;
        conn = vector<int>(110, -1);
        revConn = vector<int>(110, -1);
        for(int i = 1; i <= N / 2; i++){
            visited = vector<bool>(N + 1, false);
            dfs(i);
        }
        for(int i = 1; i <= N / 2; i++){
            if(conn[i] != -1){
                ans++;
            }
        }
        if(ans != N / 2){
            if(cnt == 0){
                cout << "-1\n";
            }
            else{
                sort(ansVec.begin(), ansVec.end());
                for(auto i : ansVec){
                    cout << i << " ";
                }
                cout << "\n";
            }
            return 0;
        }
        cnt++;
        mat[1][conn[1]] = -1;
        if(firstOdd){
            ansVec.push_back(even[conn[1] - 54]);
        }
        else{
            ansVec.push_back(odd[conn[1] - 54]);
        }
    }
    return 0;
}