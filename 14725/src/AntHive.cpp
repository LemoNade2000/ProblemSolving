#include <bits/stdc++.h>

using namespace std;

struct Node{
	map<string, Node> child;
};

Node root;
int T;

void insert(Node &v, vector<string> &arr, int idx){
	if(idx == arr.size()){
		return;
	}
	if(v.child.count(arr[idx]) == 0){
		v.child[arr[idx]] = Node();
	}
	insert(v.child[arr[idx]], arr, idx+1);
	return;
}

void dfs(Node &v, int dep = 0){
	for(auto i : v.child){
		for(int j = 0; j < dep; j++){
			cout << "--";
		}
		cout << i.first << "\n";
		dfs(i.second, dep + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for(int i = 0; i < T; i++){
		int N;
		cin >> N;
		vector<string> v;
		for(int j = 0; j < N; j++){
			string str;
			cin >> str;
			v.push_back(str);
		}
		insert(root, v, 0);
	}
	dfs(root, 0);
}
