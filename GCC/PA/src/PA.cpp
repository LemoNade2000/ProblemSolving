#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll st;
    cin >> st;

    ll a, b;
    a = b = st;
    if(st & 1){
        cout << "SELL";
        return 0;
    }
    else if(!(a & 1) && !((b >> 1) & 1)){
        cout << "BUY";
        return 0;
    }
    else{
        cout << "PASS";
        return 0;
    }
    return 0;
}