#include <bits/stdc++.h>

using namespace std;

int N, M;

int generateMinTree(int start, int end, int arr[], vector<int> &minTree, int idx){
	if(start == end){
		minTree[idx] = arr[start];
		return minTree[idx];
	}
	int mid = (start + end) / 2;
	minTree[idx] = min(generateMinTree(start, mid, arr, minTree, idx * 2), generateMinTree(mid + 1, end, arr, minTree, idx * 2 + 1));
	return minTree[idx];
}

int generateMaxTree(int start, int end, int arr[], vector<int> &maxTree, int idx){
	if(start == end){
		maxTree[idx] = arr[start];
		return maxTree[idx];
	}
	int mid = (start + end) / 2;
	maxTree[idx] = max(generateMaxTree(start, mid, arr, maxTree, idx * 2), generateMaxTree(mid + 1, end, arr, maxTree, idx * 2 + 1));
	return maxTree[idx];
}

int getMin(int start, int end, int left, int right, int idx, vector<int> minTree){
	if(left > end || right < start){
		return INT_MAX;
	}
	else if(left <= start && right >= end){
		return minTree[idx];
	}
	int mid = (start + end) / 2;
	return min(getMin(start, mid, left, right, idx * 2, minTree), getMin(mid + 1, end, left, right, idx * 2 + 1, minTree));
}

int getMax(int start, int end, int left, int right, int idx, vector<int> maxTree){
	if(left > end || right < start){
		return -INT_MAX;
	}
	else if(left <= start && right >= end){
		return maxTree[idx];
	}
	int mid = (start + end) / 2;
	return max(getMax(start, mid, left, right, idx * 2, maxTree), getMax(mid + 1, end, left, right, idx * 2 + 1, maxTree));
}


int main() {
	cin >> N >> M;
	int arr[N + 1];
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	vector<int> minTree, maxTree;
	minTree.resize(4 * N);
	maxTree.resize(4 * N);
	generateMinTree(1, N, arr, minTree, 1);
	generateMaxTree(1, N, arr, maxTree, 1);
	for(int i = 0; i < M; i++){
		int left, right;
		cin >> left >> right;
		int minans = getMin(1, N, left, right, 1, minTree);
		int maxans = getMax(1, N, left, right, 1, maxTree);
		cout << minans << " " << maxans << "\n";
	}
}
