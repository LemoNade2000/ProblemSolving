#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<pii> arr;
vector<int> sorted;
vector<int> pos;

bool comp(pii a, pii b){
    if(a.first < b.first){
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end(), comp);
    sorted.push_back(arr[0].second);
    pos.push_back(0);
    for(int i = 1; i < N; i++){
        int next = arr[i].second;
        if(next > sorted[sorted.size() - 1]){
            sorted.push_back(next);
            pos.push_back(sorted.size() - 1);
        }
        else{
            auto it = lower_bound(sorted.begin(), sorted.end(), next);
            *it = next;
            pos.push_back(distance(sorted.begin(), it));
        }
    }
    cout << arr.size() - sorted.size() << "\n";
    return 0;
}