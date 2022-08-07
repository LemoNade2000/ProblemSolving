#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N, K;
vector<int> arr;

int solve(){
    cin >> N >> K;
    arr = vector<int>(N, 0);
    int minimum, minimumIdx;
    minimum = INT_MAX;
    minimumIdx = -1;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(minimum > arr[i]){
            minimum = arr[i];
            minimumIdx = i;
        }
    }
    ll left = 0;
    ll right = N - 1;
    int epoch = 0;
    int goal = K - minimum;
    ll cost = 0;
    if(minimum > K){
        cout << "0 0" << "\n";
        return 0;
    }
    while(epoch < goal){
        while(arr[left] + epoch >= K){
            left++;
        }
        while(arr[right] + epoch >= K){
            right--;
        }
        ll dist = min(K - arr[left] - epoch, K - arr[right] - epoch);
        cost += (right - left + 1) * dist;
        epoch += dist;
    }
    cout << goal << " " << cost << "\n";
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