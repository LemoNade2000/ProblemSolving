#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;

int solve(){
    int N;
    cin >> N;
    if(N == 1){
        cout << "1\n";
        return 0;
    }
    else{
        cout << N << " ";
        for(int i = 1; i < N; i++){
            cout << i << " ";
        }
        cout << "\n";
        return 0;
    }
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