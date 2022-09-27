#include <bits/stdc++.h>

using namespace std;

int N;

long long int dist(int x1, int y1, int x2, int y2){
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<pair<int, int>> house;
	vector<long long int> maxDist;
	maxDist.resize(N, 0);
	for(int i = 0; i < N; i++){
		int x, y;
		cin >> x >> y;
		house.push_back(make_pair(x, y));
	}
	for(int i = 0; i < N; i++){
		int houseX, houseY;
		houseX = house[i].first;
		houseY = house[i].second;
		for(int j = 0; j < N; j++){
			int convX, convY;
			convX = house[j].first;
			convY = house[j].second;
			long long int currDist = dist(houseX, houseY, convX, convY);
			if(currDist > maxDist[i]){
				maxDist[i] = currDist;
			}
		}
	}
	int idx;
	long long int minDist;
	idx = 0;
	minDist = maxDist[0];
	for(int i = 0; i < N; i++){
		if(minDist > maxDist[i]){
			minDist = maxDist[i];
			idx = i;
		}
	}
	cout << house[idx].first << " " << house[idx].second << " " << maxDist[idx];
}
