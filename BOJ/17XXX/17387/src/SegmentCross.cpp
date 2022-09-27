#include <bits/stdc++.h>

using namespace std;

double ccw(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
	return p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - p2.first * p1.second - p3.first * p2.second - p1.first * p3.second;
}

int main() {
	pair<double, double> p1, p2, p3, p4;
	double x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	p1.first = x1;
	p1.second = y1;
	p2.first = x2;
	p2.second = y2;
	p3.first = x3;
	p3.second = y3;
	p4.first = x4;
	p4.second = y4;
	double ccw123 = ccw(p1, p2, p3);
	double ccw124 = ccw(p1, p2, p4);
	double ccw341 = ccw(p3, p4, p1);
	double ccw342 = ccw(p3, p4, p2);
//	cout << ccw123 << " " << ccw124 << " " << ccw341 << " " << ccw342 << "\n";
	if(ccw123 * ccw124 < 0 && ccw341 * ccw342 < 0){
		cout << 1;
		return 0;
	}
	else if (ccw123 * ccw124 == 0 && ccw341 * ccw342 == 0){
		if(p1 > p2) {
			swap(p1, p2);
		}
		if(p3 > p4) {
			swap(p3, p4);
		}
		if(p1 <= p4 && p2 >= p3){
			cout << 1;
			return 0;
		}
		else if(p4 <= p1 && p3 >= p2){
			cout << 1;
			return 0;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	else if(ccw123 * ccw124 == 0 || ccw341 * ccw342 == 0){
		if(ccw123 * ccw124 == 0){
			if(ccw341 * ccw342 < 0){
				cout << 1;
				return 0;
			}
			else{
				cout << 0;
				return 0;
			}
		}
		else if(ccw341 * ccw342 == 0){
			if(ccw123 * ccw124 < 0){
				cout << 1;
				return 0;
			}
			else{
				cout << 0;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
