#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int solve(){
    int N;
    cin >> N;
    vector<int> arr;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    for(int i = 1; i < N; i++){
        if(arr[i] % arr[0] != 0){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        solve();
    }
    return 0;
}