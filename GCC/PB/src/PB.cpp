# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    vector<int> cnt = vector<int>(30);
    int ans = 0;
    int oneCnt = 0;
    for(int i = 0; i < str.size(); i++){
        cnt[str[i] - 'a']++;
        if(cnt[str[i] - 'a'] == 2){
            ans += 2;
            oneCnt--;
            cnt[str[i] - 'a'] = 0;
        }
        else{
            oneCnt++;
        }
    }
    if(oneCnt){
        ans++;
    }
    cout << ans << "\n";
    return 0;
}