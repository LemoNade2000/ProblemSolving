#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAX 987654321

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<int> arr;
vector<int> table;
vector<pii> solutions;

bool comp(pii a, pii b){
    if(a.first + a.second < b.first + b.second){
        return true;
    }
    else if(a.first + a.second == b.first + b.second){
        return a.second < b.second;
    }
    else return false;
}

int generateTable(){
	table.resize(arr.size(), 0);
	int j = 0;
	for(int i = 1; i < arr.size(); i++){
		while(j > 0 && arr[i] != arr[j]){
			j = table[j - 1];
		}
		if(arr[i] == arr[j]){
			table[i] = ++j;
		}
	}
	return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr = vector<int>(N);
    for(int i = N - 1; i >= 0; i--){
        cin >> arr[i];
    }
    generateTable();
    for(int i = 0; i < N; i++){
        int K = N - (i + 1);
        int P = i + 1 - table[i];
        solutions.push_back({K, P});
    }
    pii sol = {MAX, MAX};
    for(auto i : solutions){
        if(i.first + i.second < sol.first + sol.second){
            sol = i;
        }
        else if(i.first + i.second == sol.first + sol.second){
            if(i.second < sol.second){
                sol = i;
            }
        }
    }
    cout << sol.first << " " << sol.second << "\n";
    return 0;
}