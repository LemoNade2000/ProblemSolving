#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

vector<int> arr;
int N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    arr = vector<int>(N);
    int maxi = -1;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(arr[i] > maxi){
            maxi = arr[i];
        }
        else if(arr[i] < maxi){
            if(arr[i] + maxi > M){
                cout << "0";
                return 0;
            }
        }
    }
    cout << "1";
    return 0;
}