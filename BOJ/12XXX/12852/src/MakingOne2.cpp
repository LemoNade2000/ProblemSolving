#include <bits/stdc++.h>

using namespace std;

int N;
bool visited[1000001];
int ans;
queue<pair<int, int>> q;
unordered_map<int, int> hashmap;
stack<int> route;

struct Node{
	int *prev;
	int num;
};

int bfs(){
	q.push(make_pair(N, 0));
	while(!q.empty()){
		int num = q.front().first;
		int depth = q.front().second;
		q.pop();
		if(num == 1){
			ans = depth;
			cout << depth << "\n";
			break;
		}
		if(num % 3 == 0){
			if(visited[num / 3] == false){
				q.push(make_pair((num / 3), depth + 1));
				hashmap[num / 3] = num;
				visited[num / 3] = true;
			}
		}
		if(num % 2 == 0){
			if(visited[num / 2] == false){
				q.push(make_pair((num / 2), depth + 1));
				hashmap[num / 2] = num;
				visited[num / 2] = true;
			}
		}
		if(visited[num - 1] == false){
			q.push(make_pair((num - 1), depth + 1));
			hashmap[num - 1] = num;
			visited[num - 1] = true;
		}
	}
	int prev = 1;
	for(int i = 0; i <= ans; i++){
		route.push(prev);
		prev = hashmap[prev];
	}
	while(!route.empty()){
		cout << route.top() << " ";
		route.pop();
	}
	return 0;
}

int main() {
	memset(visited, false, sizeof(visited));
	cin >> N;
	bfs();
}
