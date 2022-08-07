#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;

int N;
int logN;
vector<vector<int>> grid;
vector<vector<vector<vector<int>>>> minsparse;
vector<vector<vector<vector<int>>>> maxsparse;

pii query(int x1, int y1, int x2, int y2){
    int rowL = x2 - x1 + 1;
    int colL = y2 - y1 + 1;
    int logRow = log2(rowL);
    int logCol = log2(colL);
    int leftmin = min(minsparse[logRow][x1][logCol][y1], minsparse[logRow][x1][logCol][y2 - (1 << logCol) + 1]);
    int rightmin = min(minsparse[logRow][x2 - (1 << logRow) + 1][logCol][y1], minsparse[logRow][x2 - (1 << logRow) + 1][logCol][y2 - (1 << logCol) + 1]);
    int leftmax = max(maxsparse[logRow][x1][logCol][y1], maxsparse[logRow][x1][logCol][y2 - (1 << logCol) + 1]);
    int rightmax = max(maxsparse[logRow][x2 - (1 << logRow) + 1][logCol][y1], maxsparse[logRow][x2 - (1 << logRow) + 1][logCol][y2 - (1 << logCol) + 1]);
    return {min(leftmin, rightmin), max(leftmax, rightmax)};
}

int solve(){
    cin >> N;
    grid = vector<vector<int>>(N);
    logN = ceil(log2(N));
    maxsparse = minsparse = vector<vector<vector<vector<int>>>>(logN + 1);
    for(int i = 0; i <= logN; i++){
        maxsparse[i] = minsparse[i] = vector<vector<vector<int>>>(N);
        for(int j = 0; j < N; j++){
            maxsparse[i][j] = minsparse[i][j] = vector<vector<int>>(logN + 1);
            for(int k = 0; k <= logN; k++){
                maxsparse[i][j][k] = minsparse[i][j][k] = vector<int>(N, 0);
            }
        }
    }
    for(int i = 0; i < N; i++){
        grid[i] = vector<int>(N);
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            maxsparse[0][i][0][j] = minsparse[0][i][0][j] = grid[i][j];
        }
        for(int li = 1; li <= logN; li++){
            for(int idx = 0; idx + (1 << (li - 1)) < N; idx++){
                maxsparse[0][i][li][idx] = max(maxsparse[0][i][li - 1][idx], maxsparse[0][i][li - 1][idx + (1 << (li - 1))]);
                minsparse[0][i][li][idx] = min(minsparse[0][i][li - 1][idx], minsparse[0][i][li - 1][idx + (1 << (li - 1))]);
            }
        }
    }
    int ans = 0;
    for(int li = 1; li <= logN; li++){
        for(int i = 0; i + (1 << (li - 1)) < N; i++){
            for(int lj = 0; lj <= logN; lj++){
                for(int j = 0; j < N; j++){
                maxsparse[li][i][lj][j] = max(maxsparse[li - 1][i][lj][j], maxsparse[li - 1][i + (1 << (li - 1))][lj][j]);
                minsparse[li][i][lj][j] = min(minsparse[li - 1][i][lj][j], minsparse[li - 1][i + (1 << (li - 1))][lj][j]);
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int x = i; x < N; x++){
                int y = j;
                if(i == x && j == y){
                    ans++;
                    y++;
                }
                while(y < N){
                    pii q = query(i, j, x, y);
                    int num = q.second - q.first + 1;
                    if(num == (x - i + 1) * (y - j + 1)){
                        ans++;
                    }
                    // cout << i << " " << j << " " << x << " " << y << "\n";
                    y = max(y + 1, (int)ceil((j + num / (x - i + 1.0)) - 1));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
    cout << "Case #" << tc << endl;
    solve();
    }
    return 0;
}