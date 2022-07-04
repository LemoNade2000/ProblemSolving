#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;
typedef pair<int, int> pii;

int N;

vector<ll> unsorted;
vector<ll> sorted;

ll gcd(ll a, ll b){
    if(a < b){
        ll temp = b;
        b = a;
        a = temp;
    }
    ll c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

bool isSqrt(ll a){
    if(sqrtl(a) == floor(sqrtl(a))) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        ll a;
        cin >> a;
        unsorted.push_back(a);
        sorted.push_back(a);
    }
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i < N; i++){
        ll g = gcd(unsorted[i], sorted[i]);
        if(!isSqrt(unsorted[i] / g) || !isSqrt(sorted[i] / g)){
            cout << "NO"; 
            return 0;
        }
    }
    cout << "YES";
    return 0;
}