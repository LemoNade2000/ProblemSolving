#include <bits/stdc++.h>

using namespace std;

int N;
vector<double> adj[101];
struct Coordinate{
	double x;
	double y;
};

double dist(Coordinate c1, Coordinate c2){
	double xDiff = abs(c2.x - c1.x);
	double yDiff = abs(c2.y - c1.y);
	return sqrt(xDiff * xDiff + yDiff * yDiff);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<Coordinate> coord;
	bool visited[101];
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < N; i++){
		Coordinate c;
		cin >> c.x >> c.y;
		coord.push_back(c);
		for(int j = 0; j <= i; j++){
			if(i != j){
			double distance = dist(coord[i], coord[j]);
				adj[i].push_back(distance);
				adj[j].push_back(distance);
			}
			else{
				adj[i].push_back(0);
			}
		}
	}
	/*
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	priority_queue<pair<double, int>> pq;
	int count = 0;
	double ans = 0;
	pq.push(make_pair(0, 0));
	while(!pq.empty()){
		double weight = -pq.top().first;
		int dest = pq.top().second;
		pq.pop();
		if(visited[dest] == false){
//			cout << dest << " ";
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
	cout << fixed << setprecision(2);
	cout << ans;
}
