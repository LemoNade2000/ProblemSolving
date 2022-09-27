#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> numArray;
bool isPalin[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(isPalin, false, sizeof(isPalin));
	cin >> N;
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		numArray.push_back(num);
	}
	for(int i = 0; i < 2*N; i++){
		if(i % 2 == 0){ // palindrome center is num
			int mid = i / 2;
			int left = mid;
			int right = mid;
			do{
				if(numArray[left] == numArray[right]){
					isPalin[left][right] = true;
				}
				else if(numArray[left] != numArray[right]){
					isPalin[left][right] = false;
					break;
				}
				left--;
				right++;
			}while(left >= 0 && right <= N - 1);
		}
		if(i % 2 == 1){ // palindrome center is space
			int mid = i / 2;
			int left = mid;
			int right = mid + 1;
			do{
				if(numArray[left] == numArray[right]){
					isPalin[left][right] = true;
				}
				else if(numArray[left] != numArray[right]){
					isPalin[left][right] = false;
					break;
				}
				left--;
				right++;
			}while(left >= 0 && right <= N - 1);
		}
	}
	cin >> M;
	int start, end;
	for(int i = 0; i < M; i++){
		cin >> start >> end;
		start -= 1;
		end -= 1;
		if(isPalin[start][end] == true){
			cout << "1\n";
		}
		else{
			cout << "0\n";
		}
	}
	return 0;
}
