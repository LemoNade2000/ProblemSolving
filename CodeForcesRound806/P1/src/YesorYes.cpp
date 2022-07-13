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
        bool flag = true;
        if(str[0] == 'y' || str[0] == 'Y'){
            if(str[1] == 'e' || str[1] == 'E'){
                if(str[2] == 's' || str[2] == 'S'){
                    cout << "Yes\n";
                    flag = false;
                }
            }
        }
        if(flag == true){
            cout << "No\n";
        }
    }
    return 0;
}