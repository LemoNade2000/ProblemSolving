#include <bits/stdc++.h>

using namespace std;

int T;
int N, L, K;

struct Ant{
	int pos;
	int idx;
	int dir;
};

bool compareByPos(Ant a, Ant b){
	return a.pos < b.pos;
}

int solve(){
	cin >> N >> L >> K;
	vector<Ant> antList;
	priority_queue<pair<int, int>> pq;
	priority_queue<pair<int, int>> leftMove; // time, idx
	priority_queue<pair<int, int>> rightMove;
	int leftCount, rightCount;
	leftCount = 0;
	rightCount = 0;
	for(int i = 1; i <= N; i++){
		int pos, id;
		cin >> pos >> id;
		Ant ant;
		ant.pos = pos;
		ant.idx = id;
		if(id < 0){
			ant.dir = 0;
		}
		else{
			ant.dir = 1;
		}
		antList.push_back(ant);
		if(ant.dir == 0){
			leftCount++;
		}
		else{
			rightCount++;
		}
	}
// 	sort(antList.begin(), antList.end(), compareByPos);
	for(int i = 0; i < N; i++){
		Ant currAnt = antList[i];
		if(currAnt.dir == 0){
			leftMove.push(make_pair(-currAnt.pos, currAnt.idx));
		}
		else if(currAnt.dir == 1){
			rightMove.push(make_pair(L - currAnt.pos, currAnt.idx));
		}
	}
	for(int i = 0; i < N; i++){
		Ant currAnt = antList[i];
		if(leftCount > 0){
			int time = -leftMove.top().first;
			leftMove.pop();
			pq.push(make_pair(-time, -currAnt.idx));
			leftCount--;
		}
		else{
			int time = rightMove.top().first;
			rightMove.pop();
			pq.push(make_pair(-time, -currAnt.idx));
			rightCount--;
		}
	}
	for(int i = 1; i < K; i++){
		pq.pop();
	}
	cout << -pq.top().second << "\n";
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for(int tc = 1; tc <= T; tc++){
//		cout << "Case #" << tc << ": ";
		solve();
	}
}
