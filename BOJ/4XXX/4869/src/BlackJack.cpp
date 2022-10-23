// # pragma GCC optimize ("O3")
// # pragma GCC optimize ("Ofast")
// # pragma GCC optimize ("unroll-loops")
// # pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int N;
    while(cin >> N){
        if(N == 0){
            return 0;
        }
        vector<int> cnt(12);
        for(int i = 2; i < 12; i++){
            cnt[i] = 4 * N;
            if(i == 10){
                cnt[i] = 16 * N;
            }
        }
        char c[3];
        int dealer, player;
        dealer = player = 0;
        for(int i = 0; i < 3; i++){
            cin >> c[i];
            int val;
            if(c[i] > 'A' && c[i] < 'Z'){
                val = 10;
            }
            else if(c[i] == 'A'){
                val = 11;
            }
            else{
                val = c[i] - '0';
            }
            cnt[val]--;
            if(i == 0){
                dealer += val;
            }
            else{
                player += val;
            }
        }
        if(player == 22){
            player = 12;
        }
        int event = 0;
        for(int i = 2; i < 12; i++){
            if(i + dealer == 22){
                if(player > 12){
                    event += cnt[i];
                }
            }
            if(i + dealer < player){
                event += cnt[i];
            }
        }
        cout << fixed << setprecision(3);
        cout << round((event / ((52.0 * N) - 3)) * 100000) / 1000 << "%\n";
    }
    return 0;
}