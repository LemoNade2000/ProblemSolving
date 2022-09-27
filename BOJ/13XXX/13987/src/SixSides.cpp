# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> dice1 = vector<int>(6);
    vector<int> dice2 = vector<int>(6);
    for(int i = 0; i < 6; i++){
        cin >> dice1[i];
    }
    for(int i = 0; i < 6; i++){
        cin >> dice2[i];
    }
    double event = 0;
    double revEvent = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(dice1[i] > dice2[j]){
                event++;
            }
            else if(dice2[j] > dice1[i]){
                revEvent++;
            }
        }
    }
    cout << fixed << setprecision(5);
    cout << (event) / (event + revEvent);
    return 0;
}