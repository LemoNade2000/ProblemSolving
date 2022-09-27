#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 100000007

ll N, K;

class Matrix{
    private:
    int row;
    int col;
    public:
    vector<vector<ll>> adj;
    Matrix(){
        adj.clear();
        row = 0;
        col = 0;
    }
    Matrix(int x, int y){
        adj.clear();
        row = x;
        col = y;
        adj.resize(x);
        for(int i = 0; i < x; i++){
            adj[i].resize(y, 0);
        }
    }
    Matrix operator*(Matrix B){
        Matrix C(row, B.col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < B.col; j++){
                for(int k = 0; k < col; k++){
                    C.adj[i][j] = (C.adj[i][j] + ((adj[i][k] * B.adj[k][j]) % MOD)) % MOD;
                }
            }
        }
        return C;
    }
    void print(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }
};

Matrix matrixPower(Matrix matrix, int exp){
    if(exp == 0){
        Matrix idMat(N, N);
        for(int i = 0; i < N; i++){
            idMat.adj[i][i] = 1;
        }
        return idMat;
    }
    else if(exp == 1){
        return matrix;
    }
    int mid = exp / 2;
    Matrix midMat;
    midMat = matrixPower(matrix, mid);
    if(exp & 1){
        return midMat * midMat * matrix;
    }
    else{
        return midMat * midMat;
    }
}

ll power(ll a, ll pow){
    ll res = 1;
    if(a == 1) return 1;
    while(pow > 0){
        if(pow & 1 == 1){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        pow = pow >> 1;
    }
    return res % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    for(int i = 0; i < TC; i++){
        cin >> K >> N;
        if(K >= N){
            cout << "1\n";
        }
        else if(K == 0){
            cout << power(2, N) << "\n";
        }
        else{
            Matrix one = Matrix(K + 1, 1);
            Matrix* m = new Matrix(K + 1, K + 1);
            m->adj[0][0] = 1;
            m->adj[0][K] = 1;
            for(int j = 0; j < K; j++){
                m->adj[j + 1][j] = 1;
            }
            Matrix k = matrixPower(*m, N - K);
            ll ans = 0;
            // for(int x = 0; x <= K; x++){
            //     for(int y = 0; y <= K; y++){
            //         cout << k.adj[x][y] << " ";
            //     }
            //     cout << "\n";
            // }
            for(int i = 0; i <= K; i++){
                ans += k.adj[0][i];
                ans %= MOD;
            }
            cout << ans % MOD << "\n";
        }
    }
    return 0;
}