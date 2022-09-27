#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int TC;

int solve(){
    int N;
    cin >> N;
    stack<int> st;
    int num = 9;
    while(N > num){
        st.push(num);
        N -= num;
        num--;
    }
    st.push(N);
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << "\n";
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
    solve();
    }
    return 0;
}