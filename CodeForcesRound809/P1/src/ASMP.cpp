#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N, M;
vector<int> arr;
vector<bool> lett;

int solve(){
    cin >> N >> M;
    arr = vector<int>(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    lett = vector<bool>(M + 1, false);
    for(int i = 1; i <= N; i++){
        int pos = max(arr[i], M + 1 - arr[i]);
        int minPos = min(arr[i], M + 1 - arr[i]);
        if(lett[minPos] == false){
            lett[minPos] = true;
        }
        else{
            lett[pos] = lett[pos] | true;
        }
    }
    for(int i = 1; i <= M; i++){
        if(lett[i]){
            cout << "A";
        }
        else cout << "B";
    }
    cout << "\n";
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