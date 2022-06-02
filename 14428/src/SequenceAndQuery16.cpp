#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> seq;

pair<int,int> min(pair<int,int> a, pair<int, int> b){
	if(a.first < b.first){
		return a;
	}
	else if(a.first == b.first){
		if(a.second <= b.second){
			return a;
		}
		else return b;
	}
	else return b;
}

pair<int,int> generateTree(int start, int end, vector<pair<int, int>> &tree, int idx){
	if(start == end){
		tree[idx].first = seq[start];
		tree[idx].second = start;
		return tree[idx];
	}
	int mid = (start + end) / 2;
	return tree[idx] = min(generateTree(start, mid, tree, idx * 2), generateTree(mid + 1, end, tree, idx * 2 + 1));
}

pair<int, int> update(int start, int end, vector<pair<int, int>> &tree, int updatePos, int updateNum, int idx){
	if(updatePos < start || updatePos > end){
		return tree[idx];
	}
//	tree[idx] = min(tree[idx], make_pair(updateNum, updatePos));
	if(start == end){
		tree[idx].first = updateNum;
		tree[idx].second = start;
		return tree[idx];
	}
	int mid = (start + end) / 2;
	return tree[idx] = min(update(start, mid, tree, updatePos, updateNum, idx * 2), update(mid + 1, end, tree, updatePos, updateNum, idx * 2 + 1));
}

pair<int,int> getMin(int start, int end, int left, int right, vector<pair<int, int>> &tree, int idx){
	if(start > right || end < left){
		return make_pair(INT_MAX, -1);
	}
	else if(start >= left && end <= right){
		return tree[idx];
	}
	int mid = (start + end) / 2;
	return min(getMin(start, mid, left, right, tree, idx * 2), getMin(mid + 1, end, left, right, tree, idx * 2 + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	seq.push_back(0);
	vector<pair<int, int>> seqTree;
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		seq.push_back(num);
	}
	seqTree.resize(4 * N);
	generateTree(1, N, seqTree, 1);
	cin >> M;
	for(int i = 0; i < M; i++){
		int op;
		cin >> op;
		if(op == 1){
			int i, v;
			cin >> i >> v;
			update(1, N, seqTree, i, v, 1);
		}
		else if(op == 2){
			int i, j;
			cin >> i >> j;
			cout << getMin(1, N, i, j, seqTree, 1).second << "\n";
		}
	}
}
