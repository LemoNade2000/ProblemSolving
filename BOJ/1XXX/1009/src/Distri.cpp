#include <bits/stdc++.h>

using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC){
        int a, b;
        int ans;
        int temp = 1;
        cin >> a >> b;
        while(b){
            temp = (temp * a) % 10;
            b--;
        }
        cout << temp << "\n";
        TC--;
    }
    return 0;
}