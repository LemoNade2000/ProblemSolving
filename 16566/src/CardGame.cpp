#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> m;
vector<int> k;
vector<int> parent;

int find(int node){
	if(node == M){
		return M;
	}
	if(node == parent[node]){
		return node;
	}
	else return find(parent[node]);
}

int uni(int node1, int node2){
	int n = find(node1);
	int m = find(node2);
	if(n != m){
		parent[node1] = m;
	}
	return 0;
}

int main(){
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++){
		int n;
		cin >> n;
		m.push_back(n);
		parent.push_back(i);
	}
	for(int i = 0; i < K; i++){
		int n;
		cin >> n;
		k.push_back(n);
	}
	sort(m.begin(), m.end());
	for(int i = 0; i < K; i++){
		int num = k[i];
		int idx = find(distance(m.begin(), upper_bound(m.begin(), m.end(), num)));
		cout << m[idx] << "\n";
		uni(idx, idx+1);
	}
	return 0;
}
