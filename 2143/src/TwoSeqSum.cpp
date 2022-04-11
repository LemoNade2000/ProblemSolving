#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int ans;
int a[1000];
int b[1000];

int main() {
	long long int count = 0;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> ans;
	int lenA;
	int lenB;
	cin >> lenA;
	for(int i = 0; i < lenA; i++){
		cin >> a[i];
	}
	cin >> lenB;
	for(int i = 0; i < lenB; i++){
		cin >> b[i];
	}
	int aIt1, aIt2;
	vector<long long int> aSum;
	vector<long long int> bSum;
	for(int i = 0; i < lenA; i++){
		long long int sum = a[i];
		aSum.push_back(sum);
		for(int j = i + 1; j < lenA; j++){
			sum += a[j];
			aSum.push_back(sum);
		}
	}
	for(int i = 0; i < lenB; i++){
		long long int sum = b[i];
		bSum.push_back(sum);
		for(int j = i + 1; j < lenB; j++){
			sum += b[j];
			bSum.push_back(sum);
		}
	}
	sort(aSum.begin(), aSum.end());
	sort(bSum.begin(), bSum.end());
	for(int i = 0; i < aSum.size(); i++){
		long long int obj = ans - aSum[i];
		auto pre = lower_bound(bSum.begin(), bSum.end(), obj);
		auto post = upper_bound(bSum.begin(), bSum.end(), obj);
		count += (post - pre);
	}
	cout << count;
	return 0;
}
