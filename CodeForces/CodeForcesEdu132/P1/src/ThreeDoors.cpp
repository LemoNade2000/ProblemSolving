#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int door[4];
int N;

int solve(){
    cin >> N;
    cin >> door[1] >> door[2] >> door[3];
    int key = N;
    for(int i = 0; i < 2; i++){
        key = door[key];
        if(key == 0){
            cout << "NO\n";
            return 0;
        } 
    }
    cout << "YES\n";
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