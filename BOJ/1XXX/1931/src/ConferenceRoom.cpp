#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> times;

bool comp(pii a, pii b){
    if(a.second < b.second){
        return true;
    }
    else if(a.second == b.second){
        if(a.first < b.first){
            return true;
        }
        else return false;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        times.push_back({a, b});
    }
    sort(times.begin(), times.end(), comp);
    int ans = 0;
    pii currTime;
    currTime = {0, 0};
    for(int i = 0; i < N; i++){
        if(times[i].first >= currTime.second){
            currTime.first = times[i].first;
            currTime.second = times[i].second;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}