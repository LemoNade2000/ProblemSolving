#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Fabric{
    string color;
    int dur;
    int id;
    int idx;
};

int TC;
int N;
vector<Fabric> arr;
vector<int> col, durab, ids;

bool compCol(Fabric &a, Fabric &b){
    int co = a.color.compare(b.color);
    if(co < 0){
        return true;
    }
    else if(co == 0){
        return a.id < b.id;
    }
    else return false;
}

bool compDur(Fabric &a, Fabric &b){
    if(a.dur < b.dur){
        return true;
    }
    else if(a.dur == b.dur){
        return a.id < b.id;
    }
    else return false;
}

bool compId(Fabric &a, Fabric &b){
    if(a.id < b.id){
        return true;
    }
    else return false;
}

bool compIdx(Fabric &a, Fabric &b){
    if(a.idx < b.idx){
        return true;
    }
    else return false;
}

int solve(){
    cin >> N;
    arr = vector<Fabric>(N);
    col = durab = ids = vector<int>(N);
    for(int i = 0; i < N; i++){
        string str;
        int a, b;
        cin >> str >> a >> b;
        arr[i].color = str;
        arr[i].dur = a;
        arr[i].id = b;
        arr[i].idx = i;
    }
    sort(arr.begin(), arr.end(), compCol);
    for(int i = 0; i < N; i++){
        col[arr[i].idx] = i;
    }
    sort(arr.begin(), arr.end(), compDur);
    for(int i = 0; i < N; i++){
        durab[arr[i].idx] = i;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(durab[i] == col[i]){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
    cout << "Case #" << tc << ": ";
    solve();
    }
    return 0;
}