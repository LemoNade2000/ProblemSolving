#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;
int N;

int solve(){
    cin >> N;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        vector<int> v;
        vector<bool> v2;
        grid.push_back(v);
        visited.push_back(v2);
        for(int j = 0; j < N; j++){
            int c = str[j] - '0';
            grid[i].push_back(c);
            visited[i].push_back(false);
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == true){
                continue;
            }
            pii rot[4];
            rot[0] = make_pair(i, j);
            rot[1] = make_pair(j, N - 1 - i);
            rot[2] = make_pair(N - i - 1, N - j - 1);
            rot[3] = make_pair(N - 1 - j, i);
            int cntOne = 0; int cntZero = 0;
            for(int i = 0; i < 4; i++){
                pii point = rot[i];
                if(grid[point.first][point.second] == 0){
                    cntZero++;
                }
                else cntOne++;
                visited[point.first][point.second] = true;
            }
            ans += min(cntOne, cntZero);
        }
    }
    cout << ans << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        solve();
    }
    return 0;
}