#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
vector<int> arr;

int solve(){
    int N;
    cin >> N;
    arr = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int maximum = arr[N - 1];
    int cnt = 0;
    while(true){
        int maxMod = maximum % 10;
        int maxVal = maximum - maxMod;
        int largeMod = (maxMod + 10) / 2;
        int secondVal = maximum - largeMod;
        if((maxVal + maxMod /2 > arr[N - 1] && secondVal > arr[N - 1]) || maxMod == 0){
            break;
        }
        maximum += maxMod;
    }
    int idx = N - 2;
    priority_queue<int> pq;
    pq.push(maximum);
    while(!pq.empty()){
        int num = pq.top();
        pq.pop();
        if(num == arr[idx]){
            while(idx >= 0 && arr[idx] == num){
                idx--;
            }
        }
        if(idx == -1 || num < arr[idx]){
            break;
        }
        if(num & 1 == 1){
            continue;
        }
        else if(num % 10 == 0){
            pq.push(num - 5);
            continue;
        }
        else if(num - 40 > arr[idx]){
            int base = (num - arr[idx]) / 20;
            base--;
            pq.push(num - (20 * base));
            continue; 
        }
        else{
            int mod = num % 10;
            int val = num - mod;
            if(mod != 0){
                pq.push(val + mod / 2);
            }
            int large = (mod + 10) / 2;
            if(num - large > 0){
                pq.push(num - large);
            }
            continue;
        }
    }
    if(idx == -1){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        solve();
    }
    return 0;
}