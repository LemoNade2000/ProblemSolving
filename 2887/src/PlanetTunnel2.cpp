#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[100001];
struct Coordinate{
	int x;
	int y;
	int z;
};

int dist(Coordinate c1, Coordinate c2){
	int xDiff = abs(c2.x - c1.x);
	int yDiff = abs(c2.y - c1.y);
	int zDiff = abs(c2.z - c1.z);
	int minimum = min(xDiff, yDiff);
	return min(minimum, zDiff);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<Coordinate> coord;
	bool visited[100001];
	for(int i = 0; i < N; i++){
		Coordinate c;
		cin >> c.x >> c.y >> c.z;
		coord.push_back(c);
		for(int j = 0; j <= i; j++){
			if(i != j){
			int distance = dist(coord[i], coord[j]);
				adj[i].push_back(distance);
				adj[j].push_back(distance);
			}
			else{
				adj[i].push_back(0);
			}
		}
	}
	priority_queue<pair<int, int>> pq;
	int count = 0;
	long long int ans = 0;
	pq.push(make_pair(0, 0));
	while(!pq.empty()){
		int weight = -pq.top().first;
		int dest = pq.top().second;
		pq.pop();
		if(visited[dest] == false){
			count++;
			ans += weight;
			if(count == N){
				break;
			}
			visited[dest] = true;
			for(int i = 0; i < adj[dest].size(); i++){
				if(visited[i] == true){
					continue;
				}
				else{
					pq.push(make_pair(-adj[dest][i], i));
				}
			}
		}
	}
	cout << ans;
}
