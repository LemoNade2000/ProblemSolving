#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, M;

void setPrint(int bit){
    for(int i = 1; i <= N; i++){
        if(bit % 2){
            cout << i << " ";
        }
        bit = (bit >> 1);
    }
    cout << "\n";
}

void solve(int bit, int length, int min){
    if(length == M){
        setPrint(bit);
        return;
    }
    for(int i = min; i <= N; i++){
        if((bit >> (i - 1)) & 1){
            continue;
        }
        solve(bit | (1 << (i - 1)), length + 1, i);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    solve(0, 0, 1);
}