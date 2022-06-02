#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<int> tree;

int update(int start, int end, int updatePos, int diff, int idx){
	if(updatePos > end || updatePos < start){
		return 0;
	}
	tree[idx] += diff;
	if(start == end){
		return 0;
	}
	int mid = (start + end) / 2;
	update(start, mid, updatePos, diff, idx * 2);
	update(mid + 1, end, updatePos, diff, idx * 2 + 1);
	return 0;
}

int query(int start, int end, int rank, int idx){
	if(start == end){
		return start;
	}
	int leftSum = tree[idx * 2];
	int rightSum = tree[idx * 2 + 1];
	int mid = (start + end) / 2;
	if(leftSum >= rank){
		return query(start, mid, rank, idx * 2);
	}
	else if(leftSum < rank){
		return query(mid + 1, end, rank - leftSum, idx * 2 + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int depth = ceil(log2(MAX));
	tree.resize(1 << (depth + 1));
	for(int i = 0; i < N; i++){
		int op;
		cin >> op;
		if(op == 1){
			int B;
			cin >> B;
			int ans;
			ans = query(1, MAX, B, 1);
			cout << ans << "\n";
			update(1, MAX, ans, -1, 1);
		}
		else{
			int B, C;
			cin >> B >> C;
			update(1, MAX, B, C, 1);
		}
	}
	return 0;
}
