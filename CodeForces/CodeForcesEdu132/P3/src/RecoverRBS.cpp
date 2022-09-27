#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;

int solve(){
    string str;
    cin >> str;
    stack<char> st;
    vector<int> left;
    vector<int> right;
    int cnt = 0;
    for(int i = 0; i < str.size(); i++){
        if(st.empty()){
            str[i] = '(';
        }
        
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