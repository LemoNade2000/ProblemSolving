#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        string str;
        int N;
        cin >> str;
        cin >> N;
        int sum = 0;
        int app[30];
        for(int i = 0; i < 30; i++){
            app[i] = 0;
        }
        for(int i = 0; i < str.size(); i++){
            char c = str[i];
            sum += c - 'a' + 1;
            app[c - 'a']++;
        }
        int c = 'z' - 'a';
        while(sum > N){
            if(app[c] == 0){
                --c;
                continue;
            }
            app[c]--;
            sum -= c + 1;
            if(c < 0){
                break;
            }
        }
        for(int i = 0; i < str.size(); i++){
            char currC = str[i];
            if(app[currC - 'a'] > 0){
                cout << currC;
                app[currC - 'a']--;
            }
        }
        cout << "\n";
    }
}