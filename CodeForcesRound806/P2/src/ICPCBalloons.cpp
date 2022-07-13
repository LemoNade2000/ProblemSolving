#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        int N;
        cin >> N;
        string str;
        cin >> str;
        int c[30];
        memset(c, 0, sizeof(c));
        int ans = 0;
        for(int i = 0; i < N; i++){
            char cur = str[i];
            if(c[cur - 'A'] > 0){
                ans++;
                c[cur - 'A']++;
            }
            else{
                ans += 2;
                c[cur - 'A']++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}