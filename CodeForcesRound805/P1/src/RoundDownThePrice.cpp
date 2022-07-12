#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        int temp = 1;
        while(temp * 10 <= num){
            temp *= 10;
        }
        cout << num - temp << "\n";
    }
    return 0;
}