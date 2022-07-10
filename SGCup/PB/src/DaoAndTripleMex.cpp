#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    set<int> A, B, C;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        A.insert(n);
    }
    int i = 0;
    if(A.size() == 1 && A.count(0) > 0){
        B.insert(1);
    }
    else{
        for(; i < N; i++){
            B.insert(i);
            if(A.count(i) == 0){
                break;
            }
        }
        if(i == A.size()){
            B.insert(i);
        }
    }
    /*
    for(auto i : B){
        cout << i << " ";
    }
    */
    i = 0;
    if(B.size() == 1 && B.count(0) > 0){
        C.insert(1);
    }
    else{
        for(; i < B.size(); i++){
            C.insert(i);
            if(B.count(i) == 0){
                break;
            }
        }
        if(i == B.size()){
            C.insert(i);
        }
    }
    /*
    for(auto i : C){
        cout << i << " ";
    }
    */
    i = 0;
    for(; i < C.size(); i++){
        if(C.count(i) == 0){
            break;
        }
    }
    cout << i;
}