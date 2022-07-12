#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        set<char> rem;
        int ans = 1;
        for(int j = 0; j < str.size(); j++){
            if(rem.count(str[j]) > 0){
                continue;
            }
            if(rem.size() < 3){
                rem.insert(str[j]);
            }
            else if(rem.size() == 3){
                rem.clear();
                rem.insert(str[j]);
                ans++;
            }
        }
        cout << ans << "\n";
    }
}