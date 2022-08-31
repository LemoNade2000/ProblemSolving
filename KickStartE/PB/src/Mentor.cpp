#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

bool compR(pii a, pii b){
    if(a.first < b.first){
        return true;
    }
    else return false;
}

bool compOrder(pii a, pii b){
    if(a.second < b.second){
        return true;
    }
    else return false;
}

int solve(){
    int N;
    cin >> N;
    vector<pii> arr;
    for(int i = 0; i < N; i++){
        int r;
        cin >> r;
        arr.push_back({r, i});
    }
    sort(arr.begin(), arr.end(), compR);
    vector<int> ans;
    ans = vector<int>(N, -1);
    int left = 0;
    for(int i = 0; i < N; i++){
        while(left < N - 1 && arr[left + 1].first <= arr[i].first * 2){
            left++;
        }
        if(left == i){
            if(i == 0){
                continue;
            }
            else{
                ans[arr[i].second] = arr[left - 1].first;
            }
        }
        else{
            ans[arr[i].second] = arr[left].first;
        }
    }
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        cout << "Case #" << tc << ": ";
        solve();
        cout << "\n";
    }
    return 0;
} 