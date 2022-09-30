#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N;
vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr = vector<int>(N);
    int grundy = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        grundy ^= arr[i];
    }
    if(grundy != 0){
        cout << "koosaga";
    }
    else{
        cout << "cubelover";
    }
    return 0;
}