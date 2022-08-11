#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Dist{
	int val;
	int u, v;
};

int N;
vector<int> parent;
vector<Dist> dist;
int find(int node){
	if(parent[node] == node){
		return node;
	}
	else return parent[node] = find(parent[node]);
}

bool uni(int u, int v){
	int uPar = find(u);
	int vPar = find(v);
	if(uPar == vPar){
		return false;
	}
	else{
		parent[uPar] = vPar;
		return true;
	}
}

bool comp(Dist a, Dist b){
	if(a.val < b.val){
		return true;
	}
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	parent = vector<int>(N, 0);
	vector<pii> x, y, z;
	x = y = z = vector<pii>(N);
	for(int i = 0; i < N; i++){
		cin >> x[i].first >> y[i].first >> z[i].first;
		x[i].second = y[i].second = z[i].second = i;
		parent[i] = i;
	}
	sort(x.begin(), x.end()); sort(y.begin(), y.end()); sort(z.begin(), z.end());
	for(int i = 1; i < N; i++){
		dist.push_back({x[i].first - x[i - 1].first, x[i].second, x[i - 1].second});
		dist.push_back({y[i].first - y[i - 1].first, y[i].second, y[i - 1].second});
		dist.push_back({z[i].first - z[i - 1].first, z[i].second, z[i - 1].second});
	}
	sort(dist.begin(), dist.end(), comp);
	ll ans = 0;
	for(auto i : dist){
		if(uni(i.u, i.v)){
			ans += i.val;
		}
	}
	cout << ans;
	return 0;
}
