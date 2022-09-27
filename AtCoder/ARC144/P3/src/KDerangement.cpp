#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, K;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    vector<int> arr(N + 1);
    for(int i = 1; i <= N; i++){
        if(K + i <= N){
            arr[i] = K + i;
        }
        else{
            if(abs(((K + i) % N) - i) >= K){
                arr[i] = (K + i) % N;
            }
            else{
                cout << "-1\n";
                return 0;
            }
        }
    }
    if(N & 1 == 1){
        if(arr[(N + 1) / 2] - N >= K){
            for(int i = 1; i <= N; i++){
                if(i == (N + 1) / 2){
                    continue;
                }
                else{
                    cout << arr[i] << " ";
                }
            }
            cout << arr[(N + 1) / 2];
            return 0;
        }
    } 
    for(int i = 1; i <= N; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
