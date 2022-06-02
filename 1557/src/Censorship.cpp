#include <bits/stdc++.h>

using namespace std;

string T, A;
string revT, revA;
vector<int> originTable, revTable;
vector<int> solutions;
int l_start, r_start;

int generateTable(string P, vector<int> &table){
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

int KMP(string text, string P, vector<int> table, int start){
	int j = 0;
	for(int i = start; i < text.size(); i++){
		if(j > 0 && text[i] != P[j]){
			j = table[j - 1];
		}
		if(text[i] == P[j]){
			if(j == P.size() - 1){
				/*
				solutions.push_back(i - j + 1); // +1 to compensate for starting from 1 in boj
				*/
				return i - j;
			}
			else{
				j++;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, A);
	getline(cin, T);

	revA = A;
	revT = T;
	int t_len = T.length();
	int a_len = A.length();
	reverse(revA.begin(), revA.end());
	reverse(revT.begin(), revT.end());
	generateTable(A, originTable);
	generateTable(revA, revTable);
	int count = 0;
	int l_end = 0;
	int r_end = 0;
	l_start = 0;
	r_start = 0;
	while(true){
		if(count % 2 == 0){
			int end = KMP(T, A, originTable, l_start);
			if(end == -1){
				break;
			}
			else{
				T.erase(end, a_len);
				revT.erase(t_len - (end + a_len), a_len);
				t_len -= a_len;
			}
			count++;
			l_end = end;
			l_start = end - a_len - 1;
			if(l_start < 0){
				l_start = 0;
			}
		}
		else{
			int end = KMP(revT, revA, revTable, r_start);
			if(end == -1){
				break;
			}
			else{
				revT.erase(end, a_len);
				T.erase(t_len - (end + a_len), a_len);
				t_len -= a_len;
			}
			count++;
			r_end = end;
			r_start = end - a_len - 1;
			if(r_start < 0){
				r_start = 0;
			}
		}
//		cout << T << "\n" << revT << "\n";
		if(l_end > t_len - r_end){
			break;
		}
	}
	deque<char> dq;
	for(int i = 0; i < T.size(); i++){
		dq.push_back(T[i]);
		string tail;
		if(dq.size() >= A.size()){
			bool wrong = false;
			int idx = dq.size() - 1;
			for(int i = A.size() - 1; i >= 0; i--){
				if(dq[idx] != A[i]){
					wrong = true;
					break;
				}
				idx--;
			}
			if(wrong == false){
				for(int i = 0; i < A.size(); i++){
					dq.pop_back();
				}
			}
		}
	}
	int ans_len = dq.size();
	for(int i = 0; i < ans_len; i++){
		cout << dq.front();
		dq.pop_front();
	}
//	cout << T;
	return 0;
}


