#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;
int N, M;
vector<int> happ;
vector<int> cnt;
vector<pii> rel;

int solve(){
    cin >> N >> M;
    happ = vector<int>(N + 1, 0);
    cnt = vector<int>(N + 1, 0);
    rel = vector<pii>(M, {0, 0});
    for(int i = 1; i <= N; i++){
        cin >> happ[i];
    }
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
        rel[i] = {a, b};
    }
    if(M % 2 == 0){
        cout << "0\n";
        return 0;
    }
    int minimum = INT_MAX;
    for(int i = 1; i <= N; i++){
        if(cnt[i] & 1 == 1){
            minimum = min(minimum, happ[i]);
        }
    }
    for(int i = 0; i < M; i++){
        int a = rel[i].first;
        int b = rel[i].second;
        if(cnt[a] + cnt[b] - 1 & 1 == 1){
            minimum = min(minimum, happ[a] + happ[b]);
        }
    }
    cout << minimum << "\n";
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