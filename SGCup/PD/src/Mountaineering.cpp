#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll N, H;
ll realN;
ll E;
vector<ll> arr;
ll ans;
vector<ll> purArr;
ll memo[202020][3]; // 0 = energy - use, 1 = E, 2 = E - purArr[stone];

ll solve(ll pos, ll energy, ll stone, int type){
    if(stone >= realN){
        return 0;
    }
    if(memo[stone][type] != -1){
    //    cout << "Inf: " << stone << " " << type << "\n";
        return memo[stone][type];
    }
    ll use = (purArr[stone] < pos) ? 0 : purArr[stone] - pos; 
    ll a, b, c;
    a = b = c = LLONG_MAX;
    if(energy >= use){
        a = abs(purArr[stone] - pos) + solve(purArr[stone], energy - use, stone + 1, 0);
    }
    if(energy >= H - pos){
        b = (H - pos) + (H - purArr[stone]) + solve(purArr[stone], E, stone + 1, 1);
    }
    c = pos + purArr[stone] + solve(purArr[stone], E - purArr[stone], stone + 1, 2);
    return memo[stone][type] = min({a, b, c});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> E >> H >> N;
    ans = LLONG_MAX;
    for(int i = 0; i < 200001; i++){
        memo[i][0] = memo[i][1] = memo[i][2] = -1;
    }
    arr.push_back(0);
    for(int i = 1; i <= N ; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    arr.push_back(0);
    bool asc = true;
    ll temp = arr[0];
    for(int i = 0; i < arr.size(); i++){
        purArr.push_back(arr[i]);
        /*
        if(i == 0){
            purArr.push_back(arr[i]);
            continue;
        }
        if(asc == true){
            if(arr[i] > temp){
                temp = arr[i];
            }
            else if(arr[i] < temp){
                purArr.push_back(temp);
                temp = arr[i];
                asc = false;
            }
        }
        else if(asc == false){
            if(arr[i] < temp){
                temp = arr[i];
            }
            else if(arr[i] > temp){
                purArr.push_back(temp);
                temp = arr[i];
                asc = true;
            }
        }
        */
    }
    /*
    for(auto i : purArr){
        cout << i << " ";
    }
    cout << purArr.size();
    */
    realN = purArr.size();
    solve(0, E, 0, 1);
    for(int i = 0; i < realN; i++){
        cout << memo[i][0] << " " << memo[i][1] << " " << memo[i][2] << "\n";
    }
}