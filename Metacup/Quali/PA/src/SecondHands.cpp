#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int TC;
int N, K;
vector<int> arr;
ofstream output;

int solve(){
    cin >> N >> K;
    arr = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    if(K * 2 < N){
        output << "NO\n";
        return 0;
    }
    vector<int> cnt = vector<int>(101, 0);
    for(int i = 0; i < N; i++){
        cnt[arr[i]]++;
        if(cnt[arr[i]] > 2){
            output << "NO\n";
            return 0;
        }
    }
    output << "YES\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    output.open("output.txt"); 
    for(int tc = 1; tc <= TC; tc++){
        output << "Case #" << tc << ": ";
        solve();
    }
    output.close();
    return 0;
}