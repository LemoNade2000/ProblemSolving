#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

string str;
int N;
int pos;
ll sum;
vector<int> SA;
vector<int> group;
vector<int> LCP;

bool compGroup(int a, int b){
    if(group[a] < group[b]){
        return true;
    }
    else if(group[a] == group[b]){
        if(group[a + pos] < group[b + pos]){
            return true;
        }
        else return false;
    }
    else return false;
}

int manber(){
    pos = 1;
    for(; pos < N; pos = (pos << 1)){
        sort(SA.begin(), SA.end(), compGroup);
        vector<int> newGroup(2 * N, 0);
        newGroup[SA[0]] = 1;
        for(int i = 1; i < N; i++){
            newGroup[SA[i]] = newGroup[SA[i - 1]] + compGroup(SA[i - 1], SA[i]);
        }
        group = newGroup;
    }
    return 0;
}

int kasai(){
    vector<int> invSA(N, 0);
    for(int i = 0; i < N; i++){
        invSA[SA[i]] = i;
    }
    int k = 0;
    for(int i = 0; i < N; i++){
        if(invSA[i] == N - 1){
            k = 0;
            continue;
        }
        int j = SA[invSA[i] + 1];
        while(i + k < N && j + k < N && str[i + k] == str[j + k]){
            k++;
        }
        LCP[invSA[i]] = k;
        sum += k;
        if(k > 0){
            k--;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    N = str.size();
    SA = vector<int>(N);
    group = vector<int>(2 * N, 0);
    LCP = vector<int>(N);
    for(int i = 0; i < N; i++){
        SA[i] = i;
        group[i] = str[i] - 'a' + 1;
    }
    sum = 0;
    manber();
    kasai();
    ll ans = 0;
    ans = ((N * (N + 1)) >> 1) - sum;
    cout << ans << "\n";
    return 0;
}