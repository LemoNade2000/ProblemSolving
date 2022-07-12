#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N, T;
int a[50000];
int b[50000];

int solve(){
    string str;
    cin >> N >> T;
    cin >> str;
    for(int i = 0; i < N; i++){
        a[i] = -1;
        char c = str[i];
        if(c == '0'){
            b[i] = 0;
        }
        else{
            b[i] = 1;
        }
    }
    for(int i = 0; i < N; i++){
        int left = i - T;
        int right = i + T;
        if(b[i] == 0){
            if(left >= 0){
                a[left] = 0;
            }
            if(right < N){
                a[right] = 0;
            }
        }
    }
    for(int i = 0; i < T; i++){
        if(i + T < N){
            a[i + T] = b[i];
        }
        if(N - 1 - i - T >= 0){
            a[N - 1 - i - T] = b[N - 1 - i];
        }
    }
    for(int i = 0; i < N; i++){
        if(a[i] != -1){
            continue;
        }
        a[i] = 0;
        if(i - T >= 0 && (i - 2 * T < 0 || a[i - 2 * T] == 0)){
            a[i] = 1;
        }
        if(i + T < N && (i + 2 * T >= N || a[i + 2 * T] == 0)){
            a[i] = 1;
        }
    }
    for(int i = 0; i < N; i++){
        cout << a[i];
    }
    cout << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        cout << "Case #" << tc << "\n";
        solve();
    }
    return 0;
}