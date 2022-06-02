#include <bits/stdc++.h>

using namespace std;

vector<int> histo;
vector<int> tree;
int N;

int generateTree(int start, int end, int idx){
	if(start == end){
		return tree[idx] = start;
	}
	int mid = (start + end) / 2;
	int leftSeg = generateTree(start, mid, idx * 2);
	int rightSeg = generateTree(mid + 1, end, idx * 2 + 1);
	if(histo[leftSeg] < histo[rightSeg]){
		return tree[idx] = leftSeg;
	}
	else{
		return tree[idx] = rightSeg;
	}
}

int minIdx(int start, int end, int left, int right, int idx){
	if(start > right || end < left){
		return -1;
	}
	else if(start >= left && end <= right){
		return tree[idx];
	}
	int mid = (start + end) / 2;
	int leftSeg = minIdx(start, mid, left, right, idx * 2);
	int rightSeg = minIdx(mid + 1, end, left, right, idx * 2 + 1);
	if(leftSeg == -1){
		return rightSeg;
	}
	else if(rightSeg == -1){
		return leftSeg;
	}
	if(histo[leftSeg] < histo[rightSeg]){
		return leftSeg;
	}
	else{
		return rightSeg;
	}
}

int solve(int left, int right, long long int &ans){
	if(left > right){
		return -1;
	}
	int idx = minIdx(1, N, left, right, 1);
	long long int height = histo[idx];
	long long int area = height * (right - left + 1);
	if(area > ans){
		ans = area;
	}
	solve(left, idx - 1, ans);
	solve(idx + 1, right, ans);
	return 0;
}

int main() {
	while(true){
		cin >> N;
		if(N == 0){
			break;
		}
		long long int ans = -1;
		histo.resize(N + 1, 0);
		histo[0] = -1;
		tree.resize(4 * N, 0);
		for(int i = 1; i <= N; i++){
			cin >> histo[i];
		}
		generateTree(1, N, 1);
		solve(1, N, ans);
		cout << ans << "\n";
	}
}
