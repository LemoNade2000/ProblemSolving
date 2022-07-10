#include <bits/stdc++.h>

using namespace std;

int T;
int N, L;

struct Ant{
	int pos;
	int idx;
	int dir;
};

bool compareByPos(Ant a, Ant b){
	return a.pos < b.pos;
}

int solve(){
	cin >> N >> L;
	vector<Ant> antList;
	priority_queue<pair<int, int>> pq;
	priority_queue<pair<int, int>> leftMove; // time, idx
	priority_queue<pair<int, int>> rightMove;
	int leftCount, rightCount;
	leftCount = 0;
	rightCount = 0;
	for(int i = 1; i <= N; i++){
		int pos, dir;
		cin >> pos >> dir;
		Ant ant;
		ant.idx = i;
		ant.pos = pos;
		ant.dir = dir;
		antList.push_back(ant);
		if(dir == 0){
			leftCount++;
		}
		else{
			rightCount++;
		}
	}
	sort(antList.begin(), antList.end(), compareByPos);
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
	while(!pq.empty()){
		cout << -pq.top().second << " ";
		pq.pop();
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		solve();
	}
}
