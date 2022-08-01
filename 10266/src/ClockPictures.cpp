#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 360000

int N;
vector<bool> c1;
vector<bool> c2;
vector<int> fFunc;

void failFunction(vector<bool> pattern){
    int j = 0;
    for(int i = 1; i < pattern.size(); i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = fFunc[i];
        }
        if(pattern[i] == pattern[j]){
            j++;
            fFunc[i] = j;
        }
    }
    return;
}

bool kmp(vector<bool> text, vector<bool> pattern){
    int j = 0;
    for(int i = 0; i < MAX * 2; i++){
        while(j > 0 && text[i] != pattern[j]){
            j = fFunc[j - 1];
        }
        if(text[i] == pattern[j]){
            if(j == MAX - 1){
                return true;
            }
            else{
                j++;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    c1 = vector<bool>(MAX * 2, false);
    c2 = vector<bool>(MAX, false);
    fFunc = vector<int>(MAX, 0);
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        c1[n] = c1[n + MAX] = true;
    }
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        c2[n] = true;
    }
    failFunction(c2);
    if(kmp(c1, c2)){
        cout << "possible\n";
    }
    else{
        cout << "impossible\n";
    }
    return 0;
}