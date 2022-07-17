#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N;

bool compX(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first < b.first){
        return true;
    }
    else if(a.first == b.first){
        return (a.second < b.second);
    }
    else return false;
}

bool compY(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second < b.second){
        return true;
    }
    else if(a.second == b.second){
        return (a.first < b.first);
    }
    else return false;
}

int solve(){
    cin >> N;
    vector<pair<ll, ll>> pointsX;
    vector<pair<ll, ll>> pointsY;
    for(int i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y;
        pointsX.push_back({x, y});
        pointsY.push_back({x, y});
    }
    sort(pointsX.begin(), pointsX.end(), compX);
    sort(pointsY.begin(), pointsY.end(), compY);
    ll errorX, errorY;
    errorX = errorY = -1;
    ll tempX, tempY;
    tempX = tempY = -1;
    if(N % 2 == 1){
        for(auto i : pointsX){
        //    cout << i.first << " " << i.second << "\n";
            if(tempX != -1){
                if(i.first != tempX){
                    break;
                }
                else{
                    tempX = -1; tempY = -1;
                }
            }
            else{
                tempX = i.first;
                tempY = i.second;
            }
        }
        errorX = tempX;
        tempX = tempY = -1;
        for(auto i : pointsY){
        //    cout << i.first << " " << i.second << "\n";
            if(tempY != -1){
                if(i.second != tempY){
                    break;
                }
                else{
                    tempX = -1; tempY = -1;
                }
            }
            else{
                tempX = i.first;
                tempY = i.second;
            }
        }
        errorY = tempY;
    }
    ll ans = 0;
    bool flag = false;
    tempX = tempY = -1;
    for(auto i : pointsX){
        if(i.first == errorX && i.second == errorY && flag == false){
            flag = true;
            continue;
        }
        if(tempX == -1 && tempY == -1){
            tempX = i.first;
            tempY = i.second;
        }
        else{
            ans += abs(i.second - tempY);
            tempX = tempY = -1;
        }
    }
    flag = false;
    tempX = tempY = -1;
    for(auto i : pointsY){
        if(i.first == errorX && i.second == errorY && flag == false){
            flag = true;
            continue;
        }
        if(tempX == -1 && tempY == -1){
            tempX = i.first;
            tempY = i.second;
        }
        else{
            ans += abs(i.first - tempX);
            tempX = tempY = -1;
        }
    }
    cout << ans << "\n";
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