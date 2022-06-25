#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M;
bool visited[20002];
bool finished[20002];

vector<int> adj[20002];
vector<int> revAdj[20002];
stack<int> s;
vector<int> SCC[20002];
int inSCC[20002];
int sccCount;
int boolVal[10001];

int dfs(int node){
	visited[node] = true;
	for(auto nextNode : adj[node]){
		if(visited[nextNode] == false){
			dfs(nextNode);
		}
	}
	s.push(node);
	return 0;
}

int revDfs(int node){
	finished[node] = true;
	inSCC[node] = sccCount;
	SCC[sccCount].push_back(node);
	for(auto nextNode : revAdj[node]){
		if(finished[nextNode] == false){
			revDfs(nextNode);
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int start, end;
		cin >> start >> end;
		if(start > 0 && end > 0){
			adj[2 * start + 0].push_back(2 * end + 1);
			adj[2 * end + 0].push_back(2 * start + 1);
			revAdj[2 * end + 1].push_back(2 * start + 0);
			revAdj[2 * start + 1].push_back(2 * end + 0);
		}
		else if(start > 0 && end < 0){
			end = -end;
			adj[2 * start + 0].push_back(2 * end + 0);
			adj[2 * end + 1].push_back(2 * start + 1);
			revAdj[2 * end + 0].push_back(2 * start + 0);
			revAdj[2 * start + 1].push_back(2 * end + 1);
		}
		else if(start < 0 && end > 0){
			start = -start;
			adj[2 * start + 1].push_back(2 * end + 1);
			adj[2 * end + 0].push_back(2 * start + 0);
			revAdj[2 * end + 1].push_back(2 * start + 1);
			revAdj[2 * start + 0].push_back(2 * end + 0);
		}
		else if(start < 0 && end < 0){
			start = -start;
			end = -end;
			adj[2 * start + 1].push_back(2 * end + 0);
			adj[2 * end + 1].push_back(2 * start + 0);
			revAdj[2 * end + 0].push_back(2 * start + 1);
			revAdj[2 * start + 0].push_back(2 * end + 1);
		}
	}
	sccCount = 0;
	for(int i = 0; i <= 2 * N + 1; i++){
		visited[i] = false;
		finished[i] = false;
	}
	for(int i = 2; i <= 2 * N + 1; i++){
		if(visited[i] == false){
			dfs(i);
		}
	}
	while(!s.empty()){
		int node = s.top();
		s.pop();
		if(finished[node] == false){
			revDfs(node);
			sccCount++;
		}
	}
	for(int i = 1; i <= N; i++){
		if(inSCC[2 * i + 0] == inSCC[2 * i + 1]){
			cout << "0";
			return 0;
		}
	}
	cout << "1\n";
    vector<pii> sccSort;
    sccSort.resize(2 * N + 2);
    sccSort[0] = sccSort[1] = {-1, -1};
    for(int i = 2; i <= 2 * N + 1; i++){
        sccSort[i] = {inSCC[i], i};
    }
    sort(sccSort.begin(), sccSort.end());
    for(int i = 1; i <= N; i++){
        boolVal[i] = -1;
    }
    for(int i = 2; i <= 2 * N + 1; i++){
        int node = sccSort[i].second;
        if(boolVal[node / 2] == -1){
            if(node % 2 == 0){
                boolVal[node / 2] = 1;
            }
            else{
                boolVal[node / 2] = 0;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << boolVal[i] << " ";
    }
	return 0;
}
