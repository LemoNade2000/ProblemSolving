#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll N, K;
map<ll, ll> cnt; 

ll count(ll n){
    if(cnt.count(n) > 0){
        return cnt[n];
    }
    ll sum = 0;
    for(int i = 1; i <= N; i++){
        int smaller = n / i;
        if(smaller > N){
            smaller = N;
        }
        sum += smaller;
    }
    cnt.insert({n, sum});
    return sum;
}

ll find(ll left, ll right){
    if(left == right){
        return left;
    }
    ll mid = (left + right) / 2;
    ll sum = count(mid);
    if(sum >= K && count(mid - 1) < K) return mid;
    if(sum >= K){
        return find(left, mid);
    }
    else{
        return find(mid + 1, right);
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    cout << find(1, N * N);
    return 0;
}