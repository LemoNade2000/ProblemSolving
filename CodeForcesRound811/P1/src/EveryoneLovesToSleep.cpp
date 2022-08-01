#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;

struct Time{
    int hour;
    int minute;
};

bool comp(Time a, Time b){
    if(a.hour < b.hour){
        return true;
    }
    else if(a.hour == b.hour){
        return a.minute < b.minute;
    }
    else return false;
}

int solve(){
    int N;
    cin >> N;
    int hour, minute;
    cin >> hour >> minute;
    Time sleep = {hour, minute};
    vector<Time> alarms;
    for(int i = 0; i < N; i++){
        int h, m;
        cin >> h >> m;
        alarms.push_back({h, m});
        alarms.push_back({h + 24, m});
    }
    sort(alarms.begin(), alarms.end(), comp);
    for(auto i : alarms){
        if(comp(sleep, i) || sleep.hour == i.hour && sleep.minute == i.minute){
            if(sleep.minute > i.minute){
                i.hour--;
                i.minute += 60;
            }
            cout << i.hour - sleep.hour << " " << i.minute - sleep.minute << "\n";
            break;
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