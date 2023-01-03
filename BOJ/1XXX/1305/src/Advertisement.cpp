#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

vector<int> pre;
string ad;
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> ad;
    int j = 0;
    pre = vector<int>(N);
    for(int i = 1; i < N; i++){
        while(ad[i] != ad[j] && j > 0){
            j = pre[j - 1];
        }
        if(ad[i] == ad[j]){
            pre[i] = ++j;
        }
    }
    cout << N - pre[N - 1];
    return 0;
}