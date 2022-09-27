#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<long long int> segTree;
vector<long long int> numArray;

long long int buildTree(int start, int end, int idx){
	if(start == end){
		return segTree[idx] = numArray[start];
	}
	int mid = (end + start) / 2;
	return segTree[idx] = buildTree(start, mid, 2 * idx) + buildTree(mid+1, end, 2 * idx + 1);
}

long long int update(int start, int end, int treeIdx, int updatePos, long long int updateDiff){
	if(updatePos > end || updatePos < start){
		return 0;
	}
	segTree[treeIdx] += updateDiff;
	if(start == end){
		return 0;
	}
	int mid = (start + end) / 2;
	update(start, mid, 2 * treeIdx, updatePos, updateDiff);
	update(mid + 1, end, 2 * treeIdx + 1, updatePos, updateDiff);
	return 0;
}

long long int sum(int start, int end, int treeIdx, int left, int right){
	if(start > right || end < left){
		return 0;
	}
	else if(start >= left && end <= right){
		return segTree[treeIdx];
	}
	int mid = (end + start) / 2;
	return sum(start, mid, 2 * treeIdx, left, right) + sum(mid + 1, end, 2 * treeIdx + 1, left, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	numArray.resize(N + 1, 0);
	for(int i = 1; i <= N; i++){
		long long int num;
		cin >> num;
		numArray[i] = num;
	}
	segTree.resize(4 * N, 0);
	buildTree(1, N, 1);
	for(int t = 0; t < M + K; t++){
		int op;
		cin >> op;
		if(op == 1){ // update
			int updateNode;
			long long updateNum;
			cin >> updateNode >> updateNum;
			long long int diff = updateNum - numArray[updateNode];
			numArray[updateNode] = updateNum;
			update(1, N, 1, updateNode, diff);
		}
		else if(op == 2){ // sum
			int left, right;
			cin >> left >> right;
			cout << sum(1, N, 1, left, right) << "\n";
		}
	}

	return 0;
}
