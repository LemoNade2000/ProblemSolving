#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;
int N, K;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<int, int> firstStations;
    unordered_map<int, int> lastStations;
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        firstStations.clear();
        lastStations.clear();
        cin >> N >> K;
        for(int i = 0; i < N; i++){
            int n;
            cin >> n;
            if(firstStations.count(n) == 0){
                firstStations.insert({n, i});
            }
            if(lastStations.count(n) > 0){
                lastStations[n] = i;
            }
            else if(lastStations.count(n) == 0){
                lastStations.insert({n, i});
            }
        }
        for(int i = 0; i < K; i++){
            int start, end;
            cin >> start >> end;
            if(firstStations.count(start) == 0 || lastStations.count(end) == 0){
                cout << "NO\n";
                continue;
            }
            if(firstStations[start] <= lastStations[end]){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}