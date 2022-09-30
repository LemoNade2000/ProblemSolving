#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
int T, N, D;

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
            adj[i].resize(y);
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T >> N >> D;
    vector<Matrix> vecMat;
    for(int i = 0; i < T; i++){
        int M;
        cin >> M;
        Matrix matrix(N, N);
        for(int j = 0; j < M; j++){
            int u, v;
            ll num;
            cin >> u >> v >> num;
            matrix.adj[u - 1][v - 1] = num;
        }
        vecMat.push_back(matrix);
    }
    int exp = D / T;
    int mod = D % T;
    Matrix powMat(N, N);
    for(int i = 0; i < N; i++){
        powMat.adj[i][i] = 1;
    }
    for(int i = 0; i < T; i++){
        powMat = powMat * vecMat[i];
    }
    Matrix ansMat;
    ansMat = matrixPower(powMat, exp);
    for(int i = 0; i < mod; i++){
        ansMat = ansMat * vecMat[i];
    }
    ansMat.print();
}