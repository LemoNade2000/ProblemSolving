# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
// # pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    arr = vector<int>(N);
    int ans = 0;
    ll grundy = 0;
    bool notOne = false;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        grundy ^= arr[i];
        if(arr[i] == 1){
            ans++;
        }
        else{
            notOne = true;
        }
    }
    if(!notOne){
        if(N % 2 != 0){
            cout << "cubelover";
            return 0;
        }
        else{
            cout << "koosaga";
            return 0;
        }
    }
    if(ans == 0 || ans % 2 == 1){
        if(grundy != 0){
            cout << "koosaga";
            return 0;
        }
        else{
            cout << "cubelover";
            return 0;
        }
    }
    else if(ans % 2 == 0){
        for(int j = 0; j < N; j++){
            if(arr[j] != 1){
                grundy ^= arr[j];
                grundy ^= 1;
                for(int i = 0; i < N; i++){
                    grundy ^= arr[i];
                }
                if(grundy != 0){
                    cout << "koosaga";
                    return 0;
                }
                else{
                    cout << "cubelover";
                    return 0;
                }
            }
        }
    }  
    return 0;
}   