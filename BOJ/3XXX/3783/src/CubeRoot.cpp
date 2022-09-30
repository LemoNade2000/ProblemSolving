#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        long double cube;
        cin >> cube;
        long double CR = cbrt(cube);
        CR *= 1e12;
        CR = round(CR);
        CR /= 1e2;
        CR = floor(CR);
        CR = CR / 1e10;
        cout << CR << "\n";
    }
}