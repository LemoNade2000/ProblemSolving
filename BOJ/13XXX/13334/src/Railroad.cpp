#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<long long int, long long int>> seg;
vector<pair<long long int, bool>> times; // true = start, false = end;
vector<long long int> endTimes;
long long int length;

long long int min(long long int a, long long int b){
	if(a < b){
		return a;
	}
	else return b;
}

long long int max(long long int a, long long int b){
	if(a > b){
		return a;
	}
	else return b;
}

int main() {
	int ans = 0;
	int count = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		long long int start, end;
		cin >> start >> end;
		long long int s = min(start, end);
		long long int e = max(start, end);
		seg.push_back(make_pair(s, e));
		endTimes.push_back(e);
	}
	cin >> length;
	for(int i = 0; i < N; i++){
		long long int s = seg[i].first;
		long long int e = seg[i].second;
		if(e - s > length){
			continue;
		}
		times.push_back(make_pair(s, true));
		times.push_back(make_pair(endTimes[i] - length, false));
	}
	sort(times.begin(), times.end());
	for(int i = 0; i < times.size(); i++){
		if(times[i].second == false){
			count++;
		}
		else if(times[i].second == true){
			count--;
		}
		if(count > ans){
			ans = count;
		}
		cout << times[i].first << " " << times[i].second << " " << count << "\n";
	}
	cout << ans;
}
