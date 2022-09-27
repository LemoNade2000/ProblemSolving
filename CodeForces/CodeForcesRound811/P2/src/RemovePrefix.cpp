#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;

int solve(){
    int N;
    cin >> N;
    vector<int> arr(N + 1);
    vector<int> count(N + 1, 0);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    int i = N;
    for(; i > 0; i--){
        count[arr[i]]++;
        if(count[arr[i]] == 2){
            break;
        }
    }
    cout << i << "\n";
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