#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int TC;
int N, K;
vector<int> A, B;

int solve(){
    cin >> N >> K;
    A.resize(N);
    B.resize(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int minimum = 0;
    for(int i = 0; i < K; i++){
        minimum = max(minimum, A[i] + B[K - i - 1]);
    }
    cout << minimum << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        cout << "Case #" << tc << "\n";
        solve();
    }
}