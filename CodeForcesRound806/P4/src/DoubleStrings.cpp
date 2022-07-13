#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;
int N;

int solve(){
    cin >> N;
    vector<string> arr;
    set<string> strArr;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        strArr.insert(str);
        arr.push_back(str);
    }
    for(int i = 0; i < N; i++){
        bool flag = false;
        string curStr = arr[i];
        for(int j = 1; j <= curStr.size(); j++){
            string cut = curStr.substr(0, j);
            if(strArr.count(cut) > 0){
                string nextCut = curStr.substr(j);
                if(strArr.count(nextCut) > 0){
                    flag = true;
                    break;
                }
            }
            if(flag == true){
                break;
            }
        }
        if(flag == true){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
    cout << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        solve();
    }
    return 0;
}