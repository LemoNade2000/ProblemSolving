#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> sortedV;
vector<int> pos;

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int n;
		cin >> n;
		v.push_back(n);
	}
	sortedV.push_back(v[0]);
	pos.push_back(0);
	for(int i = 1; i < v.size(); i++){
		int next = v[i];
		if(next > sortedV[sortedV.size() - 1]){
			sortedV.push_back(next);
			pos.push_back(sortedV.size() - 1);
		}
		else{
			auto it = lower_bound(sortedV.begin(), sortedV.end(), next);
			*it = next;
			pos.push_back(distance(sortedV.begin(), it));
		}
	}
	cout << sortedV.size() << "\n";
	int idx = sortedV.size() - 1;
	int k = 0;
	for(int i = pos.size() - 1; i >= 0; i--){
		if(pos[i] == idx){
			sortedV[idx] = v[i];
			idx--;
		}
	}
	for(int i = 0; i < sortedV.size(); i++){
		cout << sortedV[i] << " ";
	}
}
