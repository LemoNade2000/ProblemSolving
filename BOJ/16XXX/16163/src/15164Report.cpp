#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

string str;
vector<int> LPS;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        str.push_back('#');
        str.push_back(s[i]);
    }
    str.push_back('#');
    LPS = vector<int>(str.size(), 0);
    int r, p;
    r = p = 0;
    for(int i = 0; i < str.size(); i++){
        if(i <= r){
            LPS[i] = min(LPS[2 * p - i], r - i);
        }
        else LPS[i] = 0;
        while(i - LPS[i] - 1 >= 0 && i + LPS[i] + 1 < str.size()){
            if(str[i - LPS[i] - 1] != str[i + LPS[i] + 1]){
                break;
            }
            LPS[i]++;
        }
        if(r < i + LPS[i]){
            r = i + LPS[i];
            p = i;
        }
    }
    ll ans = 0;
    for(int i = 0; i < str.size(); i++){
        if(i % 1 == 0){ // #
            if(LPS[i] == 0){
                continue;
            }
            else if(LPS[i] > 0){
                ans += ceil(LPS[i] / 2.0);
            }
        }
        else if(i % 1 == 1){ // letter
            ans += (LPS[i] >> 1) + 1;
        }
    }
    cout << ans % 10007;
    return 0;
}