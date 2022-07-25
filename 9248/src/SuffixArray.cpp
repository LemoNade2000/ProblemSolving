#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

string str;
int N;
int pos;
vector<int> suffixArray;
vector<int> group;
vector<int> LCP;

bool compGroup(int a, int b){
    if(group[a] < group[b]){
        return true;
    }
    else if(group[a] == group[b]){
        if(group[a + pos] < group[b + pos]){
            return true;
        }
        else return false;
    }
    else return false;
}

int manber(){
    pos = 1;
    for(; pos < N; pos = (pos << 1)){
        sort(suffixArray.begin(), suffixArray.end(), compGroup);
        vector<int> newGroup(2 * N, 0);
        newGroup[suffixArray[0]] = 1;
        for(int i = 1; i < N; i++){
            newGroup[suffixArray[i]] = newGroup[suffixArray[i - 1]] + compGroup(suffixArray[i - 1], suffixArray[i]);
        }
        group = newGroup;
    }
    for(auto i : suffixArray){
        cout << i + 1 << " ";
    }
    cout << "\n";
    return 0;
}

int kasai(){
    vector<int> invSuff(N, 0);
    for(int i = 0; i < N; i++){
        invSuff[suffixArray[i]] = i;
    }
    int k = 0;
    for(int i = 0; i < N; i++){
        if(invSuff[i] == N - 1){
            k = 0;
            continue;
        }
        int j = suffixArray[invSuff[i] + 1];
        while(i + k < N && j + k < N && str[i + k] == str[j + k]){
            k++;
        }
        LCP[invSuff[i]] = k;
        if(k > 0){
            k--;
        }
    }
    cout << "x ";
    for(int i = 0; i < N - 1; i++){
        cout << LCP[i] << " ";
    }
    cout << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    N = str.size();
    suffixArray = vector<int>(N);
    group = vector<int>(2 * N, 0);
    LCP = vector<int>(N);
    for(int i = 0; i < N; i++){
        suffixArray[i] = i;
        group[i] = str[i] - 'a' + 1;
    }
    manber();
    kasai();
    return 0;
}