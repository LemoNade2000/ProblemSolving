#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(1);
    int TC;
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        int N, M;
        cin >> N >> M;
        vector<int> arr;
        int sum = 0;
        long double ans = 0;
        for(int i = 0; i < N; i++){
            int n;
            cin >> n;
            arr.push_back(n);
            sum += n;
        }
        sort(arr.begin(), arr.end(), greater<int>());
        for(int i = 0; i < M - 1; i++){
            sum -= arr[i];
            ans += arr[i];
        }
        if((N - M + 1) % 2 == 1){
            ans += arr[M - 1 + ((N - M + 1) / 2)];
        }
        else{
            int pos = M - 1 + ((N - M + 1) / 2);
            ans += ((double)arr[pos] + (double)arr[pos - 1]) / 2.0;
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}