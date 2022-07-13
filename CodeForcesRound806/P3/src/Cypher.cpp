#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;
int N;

int solve(){
    cin >> N;
    vector<int> arr;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    for(int i = 0; i < N; i++){
        int K;
        cin >> K;
        string str;
        cin >> str;
        for(int j = 0; j < K; j++){
            char c = str[j];
            if(c == 'D'){
                arr[i] = (arr[i] + 1) % 10;
            }
            else if(c == 'U'){
                arr[i] = (arr[i] - 1) % 10;
                if(arr[i] < 0){
                    arr[i] += 10;
                }
            }
        }
    }
    for(auto i : arr){
        cout << i << " ";
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