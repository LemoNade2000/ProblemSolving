# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N;
vector<string> names;
vector<pii> times;

struct Info{
    bool goingIn; 
    int idx;
}; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<vector<Info>> schedule;
    names = vector<string>(N);
    schedule = vector<vector<Info>>(22);
    vector<int> cnt(22, 0);
    for(int i = 1; i <= 21; i++){
        schedule[i] = vector<Info>(0);
    }
    for(int i = 0; i < N; i++){
        cin >> names[i];
    }
    int ansC = 0;
    for(int i = 0; i < N; i++){
        int u, v;
        cin >> u >> v;
        schedule[u].push_back({true, i});
        schedule[v].push_back({false, i});
        if(cnt[u] == 0){
            cnt[u]++;
            ansC++;
        }
        if(cnt[v] == 0){
            cnt[v]++;
            ansC++;
        }
    }
    set<string> active;
    int prev = -1;
    cout << ansC - 1;
    for(int i = 1; i <= 21; i++){
        if(schedule[i].empty()){
            continue;
        }
        if(prev == -1){
            prev = i;
            for(auto info : schedule[i]){ 
                if(info.goingIn){
                    active.insert(names[info.idx]);
                }
                else{
                    active.erase(names[info.idx]);
                }
            }
            continue;
        }
        cout << "\n" << prev << " " << i << " " << active.size();
        if(active.empty()){
            cout << " ";
        }
        for(auto j : active){
            cout << " " << j;
        }
        for(auto info : schedule[i]){
            if(info.goingIn){
                active.insert(names[info.idx]);
            }
            else{
                active.erase(names[info.idx]);
            }
        }
        prev = i;
    }
    return 0;
}