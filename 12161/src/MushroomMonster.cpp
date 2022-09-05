#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N;
vector<int> arr;

int solve(){
    cin >> N;
    arr = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int prev = -1;
    // first
    int fAns = 0;
    int maxDiff = 0;
    for(int i = 0; i < N; i++){
        if(prev > arr[i]){
            fAns += prev - arr[i];
            maxDiff = max(maxDiff, prev - arr[i]);
        }
        prev = arr[i];
    }
    // second
    int sAns = 0;
    for(int i = 0; i < N - 1; i++){
        sAns += min(arr[i], maxDiff);
    }
    cout << fAns << " " << sAns << "\n";
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
    cout << "Case #" << tc << ": ";
    solve();
    }
    return 0;
}