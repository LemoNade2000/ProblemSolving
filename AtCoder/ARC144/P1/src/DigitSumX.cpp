#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    ll dec = 1;
    ll ans = 0;
    cout << 2 * N << "\n";
    stack<int> st;
    while(N > 0){
        if(N >= 4){
            st.push(4);
            N -= 4;
        }
        else{
            st.push(N);
            N = 0;
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}