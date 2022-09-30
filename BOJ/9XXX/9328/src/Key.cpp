#include <bits/stdc++.h>

using namespace std;

int TC, h, w;
vector<string> keyMap;
bool currKeys[30];
queue<pair<int, int>> travel;
vector<pair<int, int>> door;
bool visited[100][100];
int ans;

void openDoors(){
	vector<int> toErase;
	for(int i = 0; i < door.size(); i++){
		int row = door[i].first;
		int col = door[i].second;
		int reqKeyNum = keyMap[row][col] - 'A';
		if(currKeys[reqKeyNum] == true){
			travel.push(make_pair(row, col));
			visited[row][col] = false;
			keyMap[row][col] = '.';
			door.erase(door.begin() + i);
			i--;
		}
	}
	return;
}

bool haveKey(int row, int col){
	if(currKeys[keyMap[row][col] - 'A'] == true){
		return true;
	}
	else return false;
}

void bfs(int row, int col){
	if(row < 0 || row >= h || col < 0 || col >= w){
		return;
	}
	if(visited[row][col] == true){
		return;
	}
	if(keyMap[row][col] == '*'){
		visited[row][col] = true;
		return;
	}
//	cout << row << " " << col << "\n";
	if(keyMap[row][col] == '.'){
		travel.push(make_pair(row - 1, col));
		travel.push(make_pair(row, col -1));
		travel.push(make_pair(row + 1, col));
		travel.push(make_pair(row, col + 1));
		visited[row][col] = true;
		return;
	}
	if(keyMap[row][col] <= 'Z' && keyMap[row][col] >= 'A'){
		if(haveKey(row, col) == true){
			travel.push(make_pair(row - 1, col));
			travel.push(make_pair(row, col -1));
			travel.push(make_pair(row + 1, col));
			travel.push(make_pair(row, col + 1));
			visited[row][col] = true;
			return;
		}
		else{
			door.push_back(make_pair(row, col));
			visited[row][col] = true;
			return;
		}
	}
	if(keyMap[row][col] <= 'z' && keyMap[row][col] >= 'a'){
		currKeys[keyMap[row][col] - 'a'] = true;
		openDoors();
		travel.push(make_pair(row - 1, col));
		travel.push(make_pair(row, col -1));
		travel.push(make_pair(row + 1, col));
		travel.push(make_pair(row, col + 1));
		visited[row][col] = true;
		return;
	}
	if(keyMap[row][col] == '$'){
		ans++;
		travel.push(make_pair(row - 1, col));
		travel.push(make_pair(row, col -1));
		travel.push(make_pair(row + 1, col));
		travel.push(make_pair(row, col + 1));
		visited[row][col] = true;
	}
	return;
}

int solve(){
	cin >> h >> w;
	ans = 0;
	keyMap.clear();
	door.clear();
	travel = {};
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < h; i++){
		string str;
		cin >> str;
		keyMap.push_back(str);
	}
	string keyStr;
	cin >> keyStr;
	memset(currKeys, false, sizeof(currKeys));
	if(keyStr == "0"){
	}
	else{ // keyStr != "0"
		for(int i = 0; i < keyStr.size(); i++){
			int keyNum = keyStr[i] - 'a';
			currKeys[keyNum] = true;
		}
	}
	for(int i = 0; i < h; i++){
		if(i == 0 || i == h - 1){
			for(int j = 0; j < w; j++){
				travel.push(make_pair(i, j));
			}
		}
		else{
			travel.push(make_pair(i, 0));
			travel.push(make_pair(i, w-1));
		}
	}
	while(!travel.empty()){
		int row = travel.front().first;
		int col = travel.front().second;
		travel.pop();
		bfs(row, col);
	}
	cout << ans << "\n";
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> TC;
	for(int tc = 0; tc < TC; tc++){
		solve();
	}
}
