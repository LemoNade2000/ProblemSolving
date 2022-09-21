#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    arr = vector<int>(10000001);
    for(int i = 0; i < 100; i++){
        arr[i] = i;
    }
    for(int i = 2; i <= 10; i++){
        if(arr[i] == i){
            for(int j = i * i; j <= 100; j += i){
                if(arr[j] == j){
                    arr[j] = i;
                }
            }
        }
    }
    set<int> cubes;
    for(int i = 2; i <= 100; i++){
        if(arr[i] == i){
            int cube = i * i * i;
            for(int j = cube; j <= 10000000; j += cube){
                cubes.insert(j);
            }
        }
    }
    vector<int> cubeVec;
    for(auto i : cubes){
        cubeVec.push_back(i);
    }
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        cout << "Case " << i << ": ";
        if(cubes.count(n) > 0){
            cout << "Not Cube Free"<< "\n";
            continue;
        }
        else{
            cout << n - (lower_bound(cubeVec.begin(), cubeVec.end(), n) - cubeVec.begin()) << "\n";
        }
    }
    return 0;
}