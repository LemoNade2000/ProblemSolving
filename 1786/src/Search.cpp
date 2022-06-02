#include <bits/stdc++.h>

using namespace std;

string T, P;
vector<int> table;
vector<int> solutions;

int generateTable(){
	table.resize(P.size(), 0);
	int j = 0;
	for(int i = 1; i < P.size(); i++){
		while(j > 0 && P[i] != P[j]){
			j = table[j - 1];
		}
		if(P[i] == P[j]){
			table[i] = ++j;
		}
	}
	return 0;
}

int KMP(){
	int j = 0;
	for(int i = 0; i < T.size(); i++){
		if(j > 0 && T[i] != P[j]){
			j = table[j - 1];
		}
		if(T[i] == P[j]){
			if(j == P.size() - 1){
				solutions.push_back(i - j + 1); // +1 to compensate for starting from 1 in boj
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, T);
	getline(cin, P);

	generateTable();
	KMP();

	cout << solutions.size() << "\n";
	for(int i = 0; i < solutions.size(); i++){
		cout << solutions[i] << "\n";
	}

	return 0;
}
