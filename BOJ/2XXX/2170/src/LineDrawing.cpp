#include <bits/stdc++.h>

using namespace std;

int N;
int len;

int main() {
	cin >> N;
	len = 0;
	deque<pair<int, int>> lines;
	for(int i = 0; i < N; i++){
		int start, end;
		cin >> start >> end;
		lines.push_back(make_pair(start, end));
	}
	sort(lines.begin(), lines.end());
	for(int i = 1; i < N; i++){
		int l1Start = lines.front().first;
		int l1End = lines.front().second;
		lines.pop_front();
		int l2Start = lines.front().first;
		int l2End = lines.front().second;
		if(l2Start <= l1End){ // Overlap
			lines.front().first = l1Start;
			lines.front().second = max(l1End, l2End);
			continue;
		}
		else{
			len += l1End - l1Start;
		}
	}
	len += lines.front().second - lines.front().first;
	cout << len;
}
