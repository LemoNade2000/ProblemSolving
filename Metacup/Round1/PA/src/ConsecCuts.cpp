#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define MAX 987654321

int TC;
int N, K;
vector<int> arr;
vector<int> pattern;
vector<int> table;
vector<ll> solutions;
ll minimum, maximum;
ofstream out;
ifstream in;

void generateTable(vector<int> pattern){
    table = vector<int>(N);
    int j = 0;
    for(int i = 1; i < N; i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j - 1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return;
}

int KMP(){
    int j = 0;
    int i = 0;
    if(K == 1){
        i = 1;
        for(; i < arr.size() - 1; i++){
            if(j > 0 && arr[i] != pattern[j]){
                j = table[j - 1];
            }
            if(arr[i] == pattern[j]){
                if(j == pattern.size() - 1){
                    solutions.push_back(i - j);
                    j = table[j];
                    break;
                }
                else{
                    j++;
                }
            }
        }
        return 0;
    }
    for(; i < arr.size(); i++){
        if(j > 0 && arr[i] != pattern[j]){
            j = table[j - 1];
        }
        if(arr[i] == pattern[j]){
            if(j == pattern.size() - 1){
                solutions.push_back(i - j);
                j = table[j];
                break;
            }
            else{
                j++;
            }
        }
    }
    return 0;
}

int solve(){
    in >> N >> K;
    arr = vector<int>(2 * N);
    pattern = vector<int>(N);
    solutions.clear();
    minimum = K;
    maximum = (N - 1) * K;
    for(int i = 0; i < N; i++){
        in >> arr[i];
        arr[i + N] = arr[i];
    }
    for(int i = 0; i < N; i++){
        in >> pattern[i];
    }
    if(K == 0){
        for(int i = 0; i < N; i++){
            if(arr[i] != pattern[i]){
                out << "NO\n";
                return 0;
            }
        }
        out << "YES\n";
        return 0;
    }
    if(N == 2){
        if(arr[0] == arr[1]){
            out << "YES\n";
            return 0;
        }
        else if(arr[0] != pattern[0]){
            if(K & 1){
                out << "YES\n";
                return 0;
            }
            else{
                out << "NO\n";
                return 0;
            }
        }
        else if(arr[0] == pattern[0]){
            if(K & 1){
                out << "NO\n";
                return 0;
            }
            else{
                out << "YES\n";
                return 0;
            }
        }
    }
    generateTable(pattern);
    KMP();
    if(solutions.empty()){
        out << "NO\n";
        return 0;
    }
    else{
        out << "YES\n";
        return 0;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    in.open("input.txt");
    if(in.is_open()){
        out.open("output.txt");
        in >> TC;
        for(int tc = 1; tc <= TC; tc++){
        out << "Case #" << tc << ": ";
        solve();
        }
    }
    return 0;
}