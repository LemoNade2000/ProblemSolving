#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;
vector<pair<long long int,long long int>> points;
stack<pair<long long int,long long int>> s;

long long int ccw(pair<long long int,long long int> p1, pair<long long int,long long int> p2, pair<long long int,long long int> p3){
	return p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - p2.first * p1.second - p3.first * p2.second - p1.first * p3.second;
}

bool compY(pair<long long int,long long int> p1, pair<long long int,long long int> p2){
	if(p1.second != p2.second){
		return p1.second < p2.second;
	}
	else{
		return p1.first < p2.first;
	}
}

bool compCounterClockwise(pair<long long int,long long int> p1, pair<long long int,long long int> p2){
	long long int cc = ccw(points[0], p1, p2);
	if(cc != 0){
		return cc > 0; // if cc > 0, p2 is on the left-side of p[0] p[1] vector, so it must be bigger than p1.
	}
	else return (p1.first + p1.second) < (p2.first + p2.second); // if on same line, return one with less distance
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++){
		long long int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}
	sort(points.begin(), points.end(), compY);
	sort(++points.begin(), points.end(), compCounterClockwise);

	s.push(points[0]);
	s.push(points[1]);

	pair<long long int,long long int> first, second;
	for(int i = 2; i < N; i++){
		while(s.size() >= 2){
			second = s.top();
			s.pop();
			first = s.top();
			if(ccw(first, second, points[i]) > 0){
				s.push(second);
				break;
			}
		}
		s.push(points[i]);
	}
	cout << s.size();
	return 0;
}
