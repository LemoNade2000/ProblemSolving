#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 987654321
int TC;

struct Node{

};

string str;
vector<string> arr;
int N;
vector<int> dp;
vector<pii> shards;

int comp(pii a, pii b){
    if(a.second < b.second){
        return true;
    }
    else if(a.second == b.second){
        return a.first <b.first;
    }
    else return false;
}

int solve(){
    cin >> str;
    cin >> N;
    arr = vector<string>(N);
    dp = vector<int>(101, MAX);
    shards = vector<pii>(0);
    for(int i = 0; i < N ; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < N; i++){
        for(int pos = 0; pos < str.size(); pos++){
            int j = 0;
            for(; j < arr[i].size(); j++){
                if(str[pos + j] != arr[i][j]){
                    break;
                }
            }
            if(j == arr[i].size()){
                shards.push_back({pos, pos + j - 1});
            }
        }
    }
    sort(shards.begin(), shards.end());
    if(shards.empty() || shards[0].first != 0){
        cout << "-1\n";
        return 0;
    }
    dp[0] = 1;
    int idx = 0;
    for(auto i : shards){
        if(i.first == 0){
            for(int idx = 0; idx <= i.second; idx++){
                dp[idx] = 1;
            }
        }
        else{
            for(int idx = i.first; idx <= i.second; idx++){
                dp[idx] = min(dp[idx], dp[i.first - 1] + 1);
            }
        }
    }
    if(dp[str.size() - 1] == MAX){
        cout << "-1\n";
        return 0;
    }
    cout << dp[str.size() - 1] << "\n";
    int cnt = dp[str.size() - 1];
    int start, end;
    start = 0;
    for(int i = 0; i < str.size(); i++){
        cout << dp[i];
    }
    cout << "\n";
    for(int i = str.size(); i > 0; i--){
        string search;
        if(dp[i - 1] != cnt){
            end = i - 1;
            for(int j = 0; j < N; j++){
                int k = 0;
                for(; k < arr[j].size(); k++){
                    if(str[start + k] != arr[j][k]){
                        break;
                    }
                }
                if(k == arr[j].size()){
                    cout << j + 1 << " " << start + 1 << "\n";
                }
            }
            start = i - 1;
            cnt--;
        }
    }
    end = str.size() - 1;
    for(int j = 0; j < N; j++){
        int k = 0;
        for(; k < arr[j].size(); k++){
            if(str[start + k] != arr[j][k]){
                break;
            }
        }
        if(k == arr[j].size()){
            cout << j + 1 << " " << start + 1 << "\n";
        }
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