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
	vector<Ant> antList;
	priority_queue<pair<int, int>> pq;
	priority_queue<pair<int, int>> leftMove; // time, idx
	priority_queue<pair<int, int>> rightMove;
	int leftCount, rightCount;
	leftCount = 0;
	rightCount = 0;
	for(int i = 1; i <= N; i++){
		int pos;
		char dir;
		cin >> pos >> dir;
		Ant ant;
		ant.pos = pos;
		ant.idx = pos;
		if(dir == 'L'){
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
	int max = 0;
	vector<int> posList;
	for(int i = 0; i < N; i++){
		Ant currAnt = antList[i];
		if(leftCount > 0){
			int time = -leftMove.top().first;
			leftMove.pop();
			pq.push(make_pair(-time, -currAnt.idx));
			if(time > max){
				max = time;
				posList.clear();
				posList.push_back(currAnt.idx);
			}
			else if(time == max){
				max = time;
				posList.push_back(currAnt.idx);
			}
			leftCount--;
		}
		else{
			int time = rightMove.top().first;
			rightMove.pop();
			pq.push(make_pair(-time, -currAnt.idx));
			if(time > max){
				max = time;
				posList.clear();
				posList.push_back(currAnt.idx);
			}
			else if(time == max){
				max = time;
				posList.push_back(currAnt.idx);
			}
			rightCount--;
		}
	}
	sort(posList.begin(), posList.end());
	cout << "The last ant will fall down in " << max << " seconds - started at ";
	if(posList.size() == 1){
		cout << posList[0] << ".\n";
	}
	else if(posList.size() == 2){
		cout << posList[0] << " and " << posList[1] << ".\n";
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> L >> N){
		solve();
	}
}
