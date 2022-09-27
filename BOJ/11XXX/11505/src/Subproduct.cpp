#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long ll;
int N, M, K;

ll getProduct(int start, int end, int left, int right, vector<ll> &tree, int idx){
	if(left > end || right < start){
		return 1;
	}
	else if(left <= start && right >= end){
		return tree[idx];
	}
	int mid = (start + end) / 2;
	return (getProduct(start, mid, left, right, tree, idx * 2) * getProduct(mid + 1, end, left, right, tree, idx * 2 + 1)) % MOD;
}

ll update(int start, int end, int pos, vector<ll> &tree, int lastNum, int nextNum, int idx){
	if(pos > end || pos < start){
		return tree[idx];
	}
	if(start == end){
		tree[idx] = nextNum;
		return tree[idx];
	}
	int mid = (start + end) / 2;
	return tree[idx] = (update(start, mid, pos, tree, lastNum, nextNum, idx * 2) * update(mid + 1, end, pos, tree, lastNum, nextNum, idx * 2 + 1)) % MOD;
}

ll generateTree(int start, int end, vector<ll> &tree,int array[], int idx){
	if(start == end){
		return tree[idx] = array[start];
	}
	int mid = (start + end) / 2;
	return tree[idx] = (generateTree(start, mid, tree, array, idx * 2) * generateTree(mid + 1, end, tree, array, idx * 2 + 1)) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	int arr[N + 1];
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	vector<ll> tree;
	tree.resize(4 * N);
	generateTree(1, N, tree, arr, 1);
	for(int i = 0; i < M + K; i++){
		int operand;
		cin >> operand;
		if(operand == 1){
			int pos, nextNum;
			cin >> pos >> nextNum;
			int lastNum = arr[pos];
			update(1, N, pos, tree, lastNum, nextNum, 1);
		}
		else{
			int left, right;
			cin >> left >> right;
			cout << getProduct(1, N, left, right, tree, 1) << "\n";
		}
	}
	return 0;
}
