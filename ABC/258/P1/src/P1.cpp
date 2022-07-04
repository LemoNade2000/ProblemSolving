#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int min = N % 60;
    int hour = N / 60;
    if(min < 10){
        cout << 21 + hour << ":0" << min << "\n";
    }
    else{
    cout << 21 + hour << ":" << min << "\n";
    }
    return 0;
}