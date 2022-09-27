#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int N;
string str;
string s;
vector<int> LPS;

int solve(){
    cin >> N;
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
    int i = 1;
    for(; i <= 2 * N; i++){
        int center = i;
        int lLeft = i - LPS[i];
        if(lLeft != 0){
            continue;
        }
        int rLeft = i + LPS[i];
        int cRight = N + LPS[i];
        if(LPS[cRight] + cRight == 2 * N){
            break;
        }
    }
    if(i == 2 * N + 1){
        cout << s;
    }
    else{
        for(int j = 0; j < i + LPS[i]; j++){
            if(str[j] == '#'){
                continue;
            }
            else{
                cout << str[j];
            }
        }
    }
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
        str.clear();
    }
    return 0;
}