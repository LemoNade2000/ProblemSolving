#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

multiset<int> bagLimit;
vector<pair<int, int>> treasure;

bool compTreas(pair<int, int > first, pair<int, int> second){
	if(first.first == second.first){
		if(first.second < second.second){
			return true;
		}
		else return false;
	}
	if(first.first > second.first){
		return true;
	}
	else return false;
}

int main() {
	int treasureNum;
	int bagNum;
	cin >> treasureNum >> bagNum;
	bool used[treasureNum];
	for(int i = 0; i < treasureNum; i++){
		int mass, value;
		cin >> mass >> value;
		treasure.push_back(make_pair(value, mass));
		used[i] = false;
	}
	sort(treasure.begin(), treasure.end(), compTreas);
	for(int i = 0; i < bagNum; i++){
		int limit;
		cin >> limit;
		bagLimit.insert(limit);
	}
	long long int answer = 0;
	for(int i = 0; i < treasureNum; i++){
		int value = treasure[i].first;
		int mass = treasure[i].second;
		auto it = bagLimit.lower_bound(mass);
		if(it != bagLimit.end()){
			answer += value;
			bagLimit.erase(it);
		}
		if(bagLimit.size() == 0){
			break;
		}
	}
	cout << answer;
}
