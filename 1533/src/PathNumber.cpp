#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MOD 1000003

int N, S, E, T;
vector<vector<ll>> adj, ans;

vector<vector<ll>> matMul(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2){
    vector<vector<ll>> newMat;
    newMat.resize(N * 5 + 1);
    for(int i = 0; i < N * 5 + 1; i++){
        newMat[i].resize(N * 5 + 1, 0);
    }
    for(int i = 1; i < N * 5 + 1; i++){
        for(int j = 1; j < N * 5 + 1; j++){
            for(int k = 1; k < N * 5 + 1; k++){
                newMat[i][j] += mat1[i][k] * mat2[k][j];
                newMat[i][j] %= MOD;
            }
        }
    }
    return newMat;
}

void matPow(){
    while(T > 0){
        if(T % 2 == 1){
            ans = matMul(ans, adj);
            T--;
        } 
        else{
            adj = matMul(adj, adj);   
            T /= 2;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S >> E >> T;
    adj.resize(N * 5 + 1);
    ans.resize(N * 5 + 1);
    for(int i = 0; i < N * 5 + 1; i++){
        adj[i].resize(N * 5 + 1, 0);
        ans[i].resize(N * 5 + 1, 0);
    }
    for(int i = 1; i <= N; i++){
        string str;
        cin >> str;
        for(int j = 1; j <= N; j++){
            ll num = str[j - 1] - '0';
            if(num == 0){
                continue;
            }
            adj[i * 5][j * 5 - num + 1] = 1;
        }
        for(int j = 0; j < 4; j++){
            adj[i * 5 - j - 1][i * 5 - j] = 1;
        }
    }
    for(int i = 1; i < N * 5 + 1; i++){
        ans[i][i] = 1;
    }
    matPow();
    /*
    for(int i = 1; i < N * 5 + 1; i++){
        for(int j = 1; j < N * 5 + 1; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << ans[S * 5][E * 5];
} 