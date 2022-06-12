#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str, detonate;
    cin >> str;
    cin >> detonate;
    int idx = 0; 
    char ans[1000001];
    for(int i = 0; i < str.length(); i++){
        ans[idx] = str[i];
        idx++;
        if(ans[idx - 1] == detonate[detonate.length() - 1]){
            if(idx < detonate.length()){
                continue;
            }
            bool bomb = true;
            for(int j = 0; j < detonate.length(); j++){
                if(ans[idx - j - 1] != detonate[detonate.length() - 1- j]){
                    bomb = false;
                    break;
                }
            }
            if(bomb == true){
                idx -= detonate.length();
            }
        }
    }
    if(idx == 0){
        cout << "FRULA";
        return 0;
    }
    for(int i = 0; i < idx; i++){
        cout << ans[i];
    }
    return 0;
}