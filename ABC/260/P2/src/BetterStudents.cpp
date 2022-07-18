#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int X, Y, Z, N;
vector<pii> math, english, total;
vector<bool> admitted;

bool comp(pii a, pii b){
    if(a.first > b.first){
        return true;
    }
    else if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }
        else return false;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> X >> Y >> Z;
    admitted = vector<bool>(N, false);
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        math.push_back({n, i});
    }
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        english.push_back({n, i});
    }
    for(int i = 0; i < N; i++){
        int n = math[i].first + english[i].first;
        total.push_back({n, i});
    }
    sort(math.begin(), math.end(), comp);
    sort(english.begin(), english.end(), comp);
    sort(total.begin(), total.end(), comp);
    for(int i = 0; X > 0 && i < N; i++){
        if(admitted[math[i].second] == false){
            admitted[math[i].second] = true;
            X--;
        }
    }
    for(int i = 0; Y > 0 && i < N; i++){
        if(admitted[english[i].second] == false){
            admitted[english[i].second] = true;
            Y--;
        }
    }
    for(int i = 0; Z > 0 && i < N; i++){
        if(admitted[total[i].second] == false){
            admitted[total[i].second] = true;
            Z--;
        }
    }
    for(int i = 0; i < N; i++){
        if(admitted[i]){
            cout << i + 1 <<"\n";
        }
    }
    return 0;
}