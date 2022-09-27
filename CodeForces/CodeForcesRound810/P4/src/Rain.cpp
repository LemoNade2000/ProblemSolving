#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N, M, K;
vector<int> arr;

int solve(){
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    vector<int> numCols;
    vector<int> numRows;
    for(int i = 0; i < K; i++){
        numCols.push_back(arr[i] / N);
        numRows.push_back(arr[i] / M);
    }
    int sumC = 0;
    int sumR = 0;
    for(int i = 0; i < K; i++){
        if(numCols[i] > 1){
            sumC += numCols[i];
        }
        if(numRows[i] > 1){
            sumR += numRows[i];
        }
    }
    if(sumC > M || sumR > N){
        cout <<"YES\n";
        return 0;
    }
    else cout << "NO\n";
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
    solve();
    }
    return 0;
}