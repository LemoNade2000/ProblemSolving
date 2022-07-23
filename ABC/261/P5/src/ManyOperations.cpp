#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int op[32][2];
int N, C;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> C;
    for(int i = 0; i < 32; i++){
        op[i][0] = 0;
        op[i][1] = 1;
    }

    for(int i = 0; i < N; i++){
        int t, a;
        cin >> t >> a;
        int digit = 0;
        for(int digit = 0; digit < 32; digit++){
            int last = (a & 1);
            if(a == 0){
                last = 0;
            }
            a = (a >> 1);
            if(t == 1){
                op[digit][0] = op[digit][0] & last;
                op[digit][1] = op[digit][1] & last;
            }
            else if(t == 2){
                op[digit][0] = op[digit][0] | last;
                op[digit][1] = op[digit][1] | last;
            }
            else if(t == 3){
                op[digit][0] = op[digit][0] ^ last;
                op[digit][1] = op[digit][1] ^ last;
            }
        }
        int temp = 0;
        for(int j = 0; j < 32; j++){
            int dig = C & 1;
            C = (C >> 1);
            if(op[j][dig] == 1){
                temp = temp | (1 << j);
            }
        }
        C = temp;
        cout << C << "\n";
    }
    return 0;
}