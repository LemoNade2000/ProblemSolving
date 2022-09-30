#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, A, B;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> A >> B;
    vector<int> arr;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    sort(arr.begin(), arr.end());
    while(true){
        if(arr[N - 1] - B < arr[0]){
            break;
        }
        for(int i = 0; i < N; i++){
            int left = arr[i];
            int right = arr[N - 1 - i];
            if(right - B < left + A){
                break;
            }
            arr[i] = left + A;
            arr[N - 1 - i] = right - B;
        }
        sort(arr.begin(), arr.end());
    }
    sort(arr.begin(), arr.end());
    for(auto i : arr){
        cout << i << " ";
    }
    cout << arr[0];
    return 0;
}