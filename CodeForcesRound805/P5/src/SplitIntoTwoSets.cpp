#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
int TC;
int N;
unordered_set<int> A, B;
vector<pii> arr;
vector<bool> visited;
bool flag;
 
void dfs(int cnt){
    if(cnt == N){
        flag = true;
        return;
    }
    int a = arr[cnt].first;
    int b = arr[cnt].second;
    if(a == b){
        return;
    }
    if(A.count(a) == 0 && A.count(b) == 0){
        A.insert(a);
        A.insert(b);
        dfs(cnt + 1);
        A.erase(a);
        A.erase(b);
    }
    if(B.count(a) == 0 && B.count(b) == 0){
        B.insert(a);
        B.insert(b);
        dfs(cnt + 1);
        B.erase(a);
        B.erase(b);
    }
    return;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        flag = false;
        A.clear();
        B.clear();
        arr.clear();
        cin >> N;
        for(int i = 0; i < N; i++){
            int a, b;
            cin >> a >> b;
            arr.push_back({a, b});
        }
        dfs(0);
        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}