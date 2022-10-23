#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Point{
    ll x;
    ll y;
};

Point setPoint;
int N;
vector<Point> pntArr;

ll dist(Point &a, Point &b){
    return (b.y - a.y) * (b.y - a.y) + (b.x - a.x) * (b.x - a.x);
}

ll crossProduct(int x1, int y1, int x2, int y2){
    return abs(x1 * y2 - x2 * y1);
}

ll ccw(Point &p1, Point &p2, Point &p3){
	return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p2.x * p1.y - p3.x * p2.y - p1.x * p3.y;
}

bool compY(Point &p1, Point &p2){
	if(p1.y != p2.y){
		return p1.y < p2.y;
	}
	else{
		return p1.x < p2.x;
	}
}

bool compCounterClockwise(Point &p1, Point &p2){
	ll cc = ccw(setPoint, p1, p2);
	if(cc != 0){
		return cc > 0; // if cc > 0, p2 is on the left-side of p[0] p[1] vector, so it must be bigger than p1.
	}
	else return (p1.x + p1.y) < (p2.x + p2.y); // if on same line, return one with less distance
}

ll outerProduct(Point &p1, Point &p2, Point &p3, Point &p4){
    Point v1, v2;
    v1.x = p2.x - p1.x;
    v1.y = p2.y - p1.y;
    v2.x = p4.x - p3.x;
    v2.y = p4.y - p3.y;
    return v1.x * v2.y - v1.y * v2.x;
}

void getConvex(vector<Point> &originPoints, vector<Point> &points, int N){
    stack<Point> s;
    sort(originPoints.begin(), originPoints.end(), compY);
    setPoint = originPoints[0];
    sort(++originPoints.begin(), originPoints.end(), compCounterClockwise);
    s.push(originPoints[0]);
    s.push(originPoints[1]);

    Point first, second;
	for(int i = 2; i < N; i++){
		while(s.size() >= 2){
			second = s.top();
			s.pop();
			first = s.top();
			if(ccw(first, second, originPoints[i]) > 0){
				s.push(second);
				break;
			}
		}
		s.push(originPoints[i]);
	}
    while(!s.empty()){
        points.push_back(s.top());
        s.pop();
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    pntArr = vector<Point>(N);
    for(int i = 0; i < N; i++){
        cin >> pntArr[i].x >> pntArr[i].y;
    }
    vector<Point> hull;
    getConvex(pntArr, hull, N);
    reverse(hull.begin(), hull.end());
        Point a, b, c, d;
    a = hull[0]; b = hull[1]; c = hull[1]; d = hull[2];
    int idxA, idxB, idxC, idxD;
    idxA = 0; idxB = 1; idxC = 1; idxD = 2;
    ll maxDist = -1;
    pair<Point, Point> ans;
    int hullSize = hull.size();
    while(idxA <= hullSize){
        ll temp = dist(a, c);
        if(temp > maxDist){
            maxDist = temp;
            ans.first.x = a.x;
            ans.first.y = a.y;
            ans.second.x = c.x;
            ans.second.y = c.y;
        }
        if(outerProduct(a, b, c, d) > 0){
            idxC++;
            idxD++;
            c = hull[idxC % hullSize];
            d = hull[idxD % hullSize];
        }
        else{
            idxA++;
            idxB++;
            a = hull[idxA % hullSize];
            b = hull[idxB % hullSize];
        }
    }
    cout << maxDist << "\n";
    return 0;
}