#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

vector<int> fib;
vector<int> grundy;
vector<bool> mex;
int N;
vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fib = vector<int>(34);
    fib[0] = 1; fib[1] = 1;
    grundy = vector<int>(3030303);
    grundy[0] = 0;
    for(int i = 2; i < 34; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for(int i = 1; i < 3000001; i++){
        mex = vector<bool>(16, false);
        for(int j = 0; j < 34; j++){
            if(fib[j] <= i){
                mex[grundy[i - fib[j]]] = true;
            }
            else{
                for(int m = 0; m < 16; m++){
                    if(mex[m] == false){
                        grundy[i] = m;
                        break;
                    }
                }
            }
        }
    }
    cin >> N;
    arr = vector<int>(N);
    int ans = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        ans ^= grundy[arr[i]];
    }
    if(ans == 0){
        cout << "cubelover\n";
        return 0;
    }
    else{
        cout << "koosaga\n";
        return 0;
    }
    return 0;
}