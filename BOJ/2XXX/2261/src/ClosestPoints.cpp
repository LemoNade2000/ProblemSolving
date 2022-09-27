#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point{
	int x;
	int y;
};

int N;
vector<Point> points;

bool comp(Point a, Point b){
	if(a.x < b.x){
		return true;
	}
	else if(a.x == b.x){
		return a.y < b.y;
	}
	else{
		return false;
	}
}

bool setComp(Point a, Point b){
	if(a.y < b.y){
		return true;
	}
	else if(a.y == b.y){
		return a.x < b.x;
	}
	else{
		return false;
	}
}

ll dist(Point a, Point b){
	return (b.y - a.y) * (b.y - a.y) + (b.x - a.x) * (b.x - a.x);
}

int solve(){
	set<Point, decltype(&setComp)> s(&setComp);
	s.insert(points[0]);
	s.insert(points[1]);
	ll minDist = dist(points[0], points[1]);
	int start = 0;
	for(int i = 2; i < points.size(); i++){
		Point currPoint = points[i];
		while(start < i){
			Point p = points[start];
			int xDist = currPoint.x - p.x;
			if(xDist * xDist > minDist){
				s.erase(p);
				start++;
			}
			else{
				break;
			}
		}
		Point upPoint, lowPoint;
		upPoint.x = 100000;
		lowPoint.x = -100000;
		upPoint.y = currPoint.y + sqrt(minDist);
		lowPoint.y = currPoint.y - sqrt(minDist);
		auto upper = s.upper_bound(upPoint);
		auto lower = s.lower_bound(lowPoint);
		for(auto it = lower; it != upper; it++){
			minDist = min(minDist, dist(currPoint, *it));
		}
		s.insert(currPoint);
	}
	return minDist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		Point p;
		cin >> p.x >> p.y;
		points.push_back(p);
	}
	sort(points.begin(), points.end(), comp);
	cout << solve();
}
