#include <bits/stdc++.h>

using namespace std;

int H, W;
int R, C;

int main() {
	cin >> H >> W;
	cin >> R >> C;
	int ans = 4;
	if(R + 1 > H){
		ans--;
	}
	if(R - 1 <= 0){
		ans--;
	}
	if(C + 1 > W){
		ans--;
	}
	if(C - 1 <= 0){
		ans--;
	}
	cout << ans;
}
