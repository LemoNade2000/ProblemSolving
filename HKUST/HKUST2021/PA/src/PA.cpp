#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    arr = vector<int>(10000001);
    for(int i = 0; i < 10000001; i++){
        arr[i] = i;
    }
    for(int i = 2; i <= sqrt(10000000); i++){
        if(arr[i] == i){
            for(int j = i * i; j <= 10000000; j += i){
                if(arr[j] == j){
                    arr[j] = i;
                }
            }
        }
    }
    int N;
    while(scanf("%d", &N) != EOF){
        cout << "1";
        while(N > 1){
            cout << " x ";
            cout << arr[N];
            N /= arr[N];
        }
        cout << "\n";
    }
    return 0;
}