#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, Q;
vector<char> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    string str;
    cin >> str;
    ll shift = 0;
    arr.resize(str.length() + 1);
    for(int i = 0; i < str.length(); i++){
        arr[i] = str[i];
    }
    for(int i = 0; i < Q; i++){
        int op;
        cin >> op;
        if(op == 1){
            int s;
            cin >> s;
            s = s % str.length();
            shift += (str.length() - s);
        }
        if(op == 2){
            int s;
            cin >> s;
            s = s - 1;
            cout << str[(shift + s) % str.length()] << "\n";
        }
    }
    return 0;
}