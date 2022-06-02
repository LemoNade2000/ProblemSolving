#include <bits/stdc++.h>

using namespace std;

int T;
long long int N;
double X, Y;

int solve(){
	cin >> N >> X >> Y;
	long long int sum;
	sum = (N) * (N + 1) / 2;
	double ratioX = (X) / (X + Y);
	double ratioY = Y / (X + Y);
	long long int partX = sum * ratioX;
	long long int partY = sum * ratioY;
//	cout << partX << " " << partY << " " << sum << " ";
	if(partX + partY != sum){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	long long int num = N;
	vector<long long int> alanNum;
	while(num >= 0){
		if(partX > num){
			partX -= num;
			alanNum.push_back(num);
		}
		else if(partX <= num){
			alanNum.push_back(partX);
			partX -= partX;
			break;
		}
		if(partX == 0){
			break;
		}
		num--;
	}
	if(partX == 0){
		cout << "POSSIBLE\n";
	}
	else {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < alanNum.size(); i++){
		ans += alanNum[i];
	}
	if(ans != sum - partY){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	cout << alanNum.size() << "\n";
	for(int i = 0; i < alanNum.size(); i++){
		cout << alanNum[i] << " ";
	}
	cout << "\n";
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		solve();
	}
}
