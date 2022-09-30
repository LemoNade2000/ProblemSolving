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
    int count[30];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < 3; i++){
        count[str[i] - 'a']++;
    }
    for(int i = 0; i < 30; i++){
        if(count[i] == 1){
            cout << (char)('a' + i);
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}