#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	/*
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}
	st.push(arr[0]);
	*/
	stack<pair<int, int>> st;
	long long int ans = 0;
	for(int i = 0; i < N; i++){
		int nextNum;;
		cin >> nextNum;
//		cout << st.size() << "\n";
		int popCount = 0;
//		stack<int> temp;
		int consec = 1;
		while(!st.empty()){
			if(st.top().first > nextNum){
				popCount++;
				break;
			}
			else if(st.top().first == nextNum){
				consec += st.top().second;
				popCount += st.top().second;
				st.pop();
			}
			else if(st.top().first < nextNum){
				popCount += st.top().second;
				st.pop();
			}
		}
		ans += popCount;
		st.push(make_pair(nextNum, consec));
	}
	cout << ans;
}
