#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> red(200, false);
    vector<bool> blue(200, false);
    int L1, R1, L2, R2;
    cin >> L1 >> R1 >> L2 >> R2;
    for(int i = L1; i <= R1; i++){
        red[i] = true;
    }
    for(int i = L2; i <= R2; i++){
        blue[i] = true;
    }
    int ans = 0;
    for(int i = 0; i < 200; i++){
        if(red[i] && blue[i]){
            ans++;
        }
    }
    if(ans == 0){
        ans = 1;
    }
    cout << ans - 1;
    return 0;
}