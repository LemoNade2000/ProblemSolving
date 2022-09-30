#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N, M;
int parent[100001][21]; // Nth node's 2^M'th parent
vector<pii> adj[100001];
bool visited[100001];
int depth[100001];
ll cost[100001][21];

void dfs(int start, int currDepth){
	visited[start] = true;
	depth[start] = currDepth;
	for(int i = 0; i < adj[start].size(); i++){
		int dest = adj[start][i].first;
		if(visited[dest] == false){
			parent[dest][0] = start;
			cost[dest][0] = adj[start][i].second;
			dfs(dest, currDepth + 1);
		}
	}
}

void memo(){
	for(int i = 1; i < 21; i++){
		for(int node = 1; node <= N; node++){
			int prevParent = parent[node][i-1];
			parent[node][i] = parent[prevParent][i-1];
			cost[node][i] = cost[node][i - 1] + cost[prevParent][i - 1];
 			if(parent[prevParent][i-1] == 0){
				continue;
			}
		}
	}
}

ll getCost(int firstNode, int secondNode){
	if(depth[secondNode] > depth[firstNode]){
		int temp = secondNode;
		secondNode = firstNode;
		firstNode = temp;
	}
	ll ans = 0;
	for(int i = 21; i >= 0; i--){
		int diff = 1 << i;
		if(depth[firstNode] - depth[secondNode] >= diff){
			ans += cost[firstNode][i];
			firstNode = parent[firstNode][i];
		}
	}
	if(firstNode == secondNode) return ans;
	else{
		for(int i = 20; i >= 0; i--){
			if(parent[firstNode][i] == parent[secondNode][i]){
				continue;
			}
			ans += (cost[firstNode][i] + cost[secondNode][i]);
			firstNode = parent[firstNode][i];
			secondNode = parent[secondNode][i];
		}
	}
	ans += (cost[firstNode][0] + cost[secondNode][0]);
	return ans;
}

int getParent(int node, int order){
//	cout << node << " " << order << "\n";
	for(int i = 21; i >= 0; i--){
		int diff = 1 << i;
		if(order >= diff){
			node = parent[node][i];
			order -= diff;
		}
	}
	return node;
}

int getRoute(int firstNode, int secondNode, int order){
	bool flip;
	int depthStart = depth[firstNode];
	int depthEnd = depth[secondNode];
	int origin = firstNode;
	int dest = secondNode;
	order--;
	if(depth[secondNode] > depth[firstNode]){
		flip = true;
		int temp = secondNode;
		secondNode = firstNode;
		firstNode = temp;
	}
	for(int i = 21; i >= 0; i--){
		int diff = 1 << i;
		if(depth[firstNode] - depth[secondNode] >= diff){
			firstNode = parent[firstNode][i];
		}
	}
	if(firstNode == secondNode){
		if(depthStart > depthEnd){
			return getParent(origin, order);
		}
		else{
			order = (depthEnd - depthStart) - order;
			return getParent(dest, order);
		}
	}
	else{
		for(int i = 20; i >= 0; i--){
			if(parent[firstNode][i] == parent[secondNode][i]){
				continue;
			}
			firstNode = parent[firstNode][i];
			secondNode = parent[secondNode][i];
		}
	}
	int midNode = parent[firstNode][0];
	int depthLCA = depth[midNode];
	int length = depthStart + depthEnd - (2 * depthLCA);
	if(order > depthStart - depthLCA){
		order = order - (depthStart - depthLCA);
		order = (depthEnd - depthLCA) - order;
		return getParent(dest, order);
	}
	else{
		return getParent(origin, order);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i = 1; i < N; i++){
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(end, weight));
		adj[end].push_back(make_pair(start, weight));
	}
	dfs(1, 0);
	memo();
	int op;
    int u, v;
	cin >> M;
	for(int tc = 0; tc < M; tc++){
		cin >> op;
        if(op == 1){
            cin >> u >> v;
			cout << getCost(u, v) << "\n";
        }
        else if(op == 2){
            int k;
            cin >> u >> v >> k;
			cout << getRoute(u, v, k) << "\n";
        }
	}
}
