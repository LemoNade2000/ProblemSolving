#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
vector<int> dest;
vector<int> sortedV;
vector<int> pos;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	bool used[N];
	for(int i = 0; i < N; i++){
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
		used[i] = false;
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < N; i++){
		dest.push_back(v[i].second);
	}
	sortedV.push_back(dest[0]);
	pos.push_back(0);
	for(int i = 1; i < dest.size(); i++){
		int next = dest[i];
		if(next > sortedV[sortedV.size() - 1]){
			sortedV.push_back(next);
			pos.push_back(sortedV.size() - 1);
		}
		else{
			auto it = lower_bound(sortedV.begin(), sortedV.end(), next);
			*it = next;
			pos.push_back(distance(sortedV.begin(), it));
		}
	}
	int idx = sortedV.size() - 1;
	for(int i = pos.size() -1; i >= 0; i--){
		if(pos[i] == idx){
			idx--;
			used[i] = true;
		}
	}
	cout << v.size() - sortedV.size() << "\n";
	for(int i = 0; i < v.size(); i++){
		if(used[i] == false){
			cout << v[i].first << "\n";
		}
	}
}
