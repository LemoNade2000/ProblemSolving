#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N;
vector<vector<char>> results;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    results = vector<vector<char>>(N);
    for(int i = 0; i < N; i++){
        results[i] = vector<char>(N);
        string str;
        cin >> str;
        for(int j = 0; j < N; j++){
            results[i][j] = str[j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                if(results[i][j] != '-'){
                    cout << "incorrect";
                    return 0;
                }
                else continue;
            }
            else{
                if(results[i][j] == 'D'){
                    if(results[j][i] != 'D'){
                        cout << "incorrect";
                        return 0;
                    }
                    else continue;
                }
                else if(results[i][j] == 'W'){
                    if(results[j][i] != 'L'){
                        cout << "incorrect";
                        return 0;
                    }
                    else continue;
                }
                else if(results[i][j] == 'L'){
                    if(results[j][i] != 'W'){
                        cout << "incorrect";
                        return 0;
                    }
                    else continue;
                }
            }
        }
    }
    cout << "correct";
    return 0;
}