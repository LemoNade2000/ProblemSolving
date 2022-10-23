# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int C;
int N;
vector<int> arr;
vector<int> prefix;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> C;
    cin >> N;
    arr = vector<int>(N);
    prefix = vector<int>(N + 1, 0);
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }
    int lIdx = 0;
    int i = 1;
    while(i <= N){
        while(prefix[i] - prefix[lIdx] >= C){
            lIdx++;
            if(lIdx == i) break;
        }
        sum += i - lIdx;
        i++;
    }
    cout << sum << "\n";
    return 0;
}