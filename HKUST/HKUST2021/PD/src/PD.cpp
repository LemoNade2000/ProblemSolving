#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int TC;

int distance(int x1, int y1, int x2, int y2){
    return (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
}

int solve(){
    int x1, y1, r1;
    int x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    int dist = distance(x1, y1, x2, y2);
    int s = r1 + r2;
    int r = r1 - r2;
    if(dist == r * r){
        cout << "E\n";
        return 0;
    }
    else if(dist < r * r){
        cout << "I\n";
        return 0;
    }
    else if(dist > r * r){
        cout << "O\n";
        return 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int i = 0; i < TC; i++){
        solve();
    }
    return 0;
}