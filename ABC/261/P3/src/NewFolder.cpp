#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N;
map<string, int> strarr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        if(strarr.count(str) == 0){
            strarr.insert({str, 1});
            cout << str << "\n";
        }
        else{
            cout << str << "(" << strarr[str] << ")\n";
            strarr[str]++;
        }
    }
    return 0;
}