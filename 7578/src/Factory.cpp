#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N;
vector<ll> tree;

ll update(int start, int end, int updatePos, int idx){
	if(updatePos > end || updatePos < start){
		return 0;
	}
	tree[idx]++;
	if(start == end){
		return 0;
	}
	int mid = (start + end) / 2;
	update(start, mid, updatePos, idx * 2);
	update(mid + 1, end, updatePos, idx * 2 + 1);
	return 0;
}

ll getSum(int start, int end, int left, int right, int idx){
	if(start > right || end < left){
		return 0;
	}
	else if(start >= left && end <= right){
		return tree[idx];
	}
	int mid = (start + end) / 2;
	return getSum(start, mid, left, right, idx * 2) + getSum(mid + 1, end, left, right, idx * 2 + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	map<ll, int> line1;
	ll line2[N];
	int depth = ceil(log2(N));
	tree.resize(1 << depth + 1);
	for(int i = 1; i <= N; i++){
		ll num;
		cin >> num;
		line1[num] = i;
	}
	for(int i = 1; i <= N; i++){
		ll num;
		cin >> num;
		line2[i] = line1[num];
	}

	ll ans = 0;

	for(int i = 1; i <= N; i++){
		int idx = line2[i];
		ans += getSum(1, N, idx + 1, N, 1);
		update(1, N, idx, 1);
	}
	cout << ans;
}
