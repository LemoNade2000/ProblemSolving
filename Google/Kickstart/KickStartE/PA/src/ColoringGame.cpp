#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int N, M;

int solve(){
    cin >> N;
    if(N % 5 == 0){
        cout << (N / 5);
        return 0;
    }
    cout << (N / 5) + 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        cout << "Case #" << tc << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}