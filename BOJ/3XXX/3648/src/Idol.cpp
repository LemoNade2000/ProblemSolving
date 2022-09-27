#include <bits/stdc++.h>

using namespace std;

int N, M;
bool visited[20002];
bool finished[20002];

vector<int> adj[20002];
vector<int> revAdj[20002];
stack<int> s;
vector<int> SCC[20002];
int inSCC[20002];
int sccCount;

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
    while(cin >> N){
        for(int i = 0; i < 20002; i++){
            adj[i].clear();
            revAdj[i].clear();
            SCC[i].clear();
            inSCC[i] = 0;
            visited[i] = false;
            finished[i] = false;
        }
        if(N == -1){
            break;
        }
        adj[2].push_back(3);
    //    adj[2].push_back(3);
        revAdj[3].push_back(2);
    //    revAdj[3].push_back(2);
        cin >> M;
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
        bool possible = true;
        for(int i = 1; i <= N; i++){
            if(inSCC[2 * i + 0] == inSCC[2 * i + 1]){
                possible = false;
                break;
            }
        }
        if(possible == true){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
    return 0;
}
