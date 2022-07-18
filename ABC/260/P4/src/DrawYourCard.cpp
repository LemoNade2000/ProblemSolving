#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, K;
vector<int> arr;
vector<int> cnt;
vector<int> order;
vector<int> link;
vector<int> curr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    arr = vector<int>(N + 1);
    order = vector<int>(N + 1, -1);
    cnt = vector<int> (N + 1, 0);
    link = vector<int> (N + 1, -1);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= N; i++){
        int n = arr[i];
        auto it = lower_bound(curr.begin(), curr.end(), n);
        if(it == curr.end()){
            if(K == 1){
                order[n] = i;
                continue;
            }
            curr.push_back(n);
            cnt[n] = 1;
            continue;
        }
        link[n] = *it;
        cnt[n] = cnt[*it] + 1;
        if(cnt[n] == K){
            order[n] = i;
            int l = link[n];
            for(int j = 1; j < K && l != -1; j++){
                order[l] = i;
                l = link[l];
            }
            curr.erase(it);
            continue;
        }
        *it = n;
    }
    for(int i = 1; i <= N; i++){
        cout << order[i] << "\n";
    }
    return 0;
}