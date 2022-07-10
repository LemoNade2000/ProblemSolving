#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

struct Prop{
    ld val;
    ld probB;
    ld probR;
    int id;
};

int n; 
ld x, y;
ld q;
vector<ld> red;
vector<ld> blue;
vector<ld> pRed, pBlue;
vector<ld> ans;

bool comp(Prop &a, Prop &b){
    if(a.val > b.val){
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(6);
    cin >> n >> x >> y;
    q = x / y;
    red.resize(n);
    pRed.resize(n);
    blue.resize(n);
    pBlue.resize(n);
    ans.resize(n);
    ll rSum, bSum;
    rSum = bSum = 0;
    for(int i = 0; i < n; i++){
        cin >> red[i];
        rSum += red[i];
    }
    for(int i = 0; i < n; i++){
        cin >> blue[i];
        bSum += blue[i];
    }
    for(int i = 0; i < n; i++){
        pRed[i] = red[i] / (ld)rSum;
        pBlue[i] = blue[i] / (ld)bSum;
    }
    vector<Prop> arr(n);
    for(int i = 0; i < n; i++){
        arr[i].id = i;
        arr[i].probB = pBlue[i];
        arr[i].probR = pRed[i];
        arr[i].val = pRed[i] / (pRed[i] + pBlue[i]);
    }
    sort(arr.begin(), arr.end(), comp);
    for(int i = 0; i < n && q > 0; i++){
        if(arr[i].probB <= q){
            ans[arr[i].id] = 1;
            q = q - arr[i].probB; 
        }
        else if(arr[i].probB > q){
            ans[arr[i].id] = q / arr[i].probB;
            q = 0;
            break;
        }
    }
    for(auto i : ans){
        cout << i << "\n";
    }
}