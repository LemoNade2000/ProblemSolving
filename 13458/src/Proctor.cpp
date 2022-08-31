#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<int> arr;
int B, C;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cin >> B >> C;
    ll ans = 0;
    for(auto i : arr){
        int temp = i;
        if(temp > 0){
            temp -= B;
            ans += 1;
        }
        if(temp > 0){
            ans += ceil(temp / (C + 0.0));
        }
    }
    cout << ans;
    return 0;
}