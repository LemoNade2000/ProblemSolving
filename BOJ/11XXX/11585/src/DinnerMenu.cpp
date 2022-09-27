#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<char> arr;
vector<char> meat;
vector<int> table;
int sol;

int generateTable(){
    table = vector<int>(N, 0);
    int j = 0;
    for(int i = 1; i < N; i++){
        while(j > 0 && meat[j] != meat[i]){
            j = table[j - 1];
        }
        if(meat[j] == meat[i]){
            table[i] = ++j;
        }
    }
    return 0;
}

int KMP(){
    int j = 0;
    for(int i = 0; i < 2 * N - 1; i++){
        if(j > 0 && arr[i] != meat[j]){
            j = table[j - 1];
        }
        if(arr[i] == meat[j]){
            if(j == N - 1){
                sol++;
                j = table[j];
            }
            else{
                j++;
            }
        }
    }
    return 0;
}

int GCD(int a, int b){
    while(true){
        int r = a % b;
        if(r == 0){
            return b;
        }
        a = b; 
        b = r;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr = vector<char>(2 * N);
    for(int i = 0; i < N; i++){
        char c;
        cin >> c;
        arr[i] = arr[i + N] = c;
    }
    meat = vector<char>(N);
    for(int i = 0; i < N; i++){
        cin >> meat[i];
    }
    sol = 0;
    generateTable();
    KMP();
    int gcd = GCD(N, sol);
    cout << sol / gcd << "/" << N / gcd;
    return 0;
}