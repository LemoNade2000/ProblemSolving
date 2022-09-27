#include <bits/stdc++.h>

using namespace std;

int K, N;
vector<string> numbers;
string maxString;

bool comp(string str1, string str2){
	return str1 + str2 > str2 + str1;
}

int main() {
	cin >> K >> N;
	maxString = "0";
	for(int i = 0; i < K; i++){
		string num;
		cin >> num;
		numbers.push_back(num);
		if(maxString.size() <= num.size()){
			if(maxString.size() < num.size() || (maxString.size() == num.size() && maxString < num)){
				maxString = num;
			}
		}
	}
	for(int i = 0; i < N - K; i++){
		numbers.push_back(maxString);
	}
	sort(numbers.begin(), numbers.end(), comp);
	string answer;
	for(int i = 0; i < numbers.size(); i++){
		answer.append(numbers[i]);
	}
	cout << answer;
}
