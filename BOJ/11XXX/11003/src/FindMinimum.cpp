#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, L;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<pii> pq;
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        pq.push({-a, i});
        int bound = i - L + 1;
        while(pq.top().second < bound){
            pq.pop();
        }
        cout << -pq.top().first << " ";
    }
    return 0;
}