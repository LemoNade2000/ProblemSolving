#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

class Point{
    public:
        int idx;
        ll x, y;
};

int TC;
int N, M;
Point setPoint;
vector<Point> black;
vector<Point> white;
vector<Point> blackHull;
vector<Point> whiteHull;

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

void getConvex(vector<Point> &originPoints, vector<Point> &hull, int num){
    if(num == 1){
        hull.push_back(originPoints[0]);
        return;
    }
    else if(num == 0){
        return;
    }
    stack<Point> s;
    sort(originPoints.begin(), originPoints.end(), compY);
    setPoint = originPoints[0];
    sort(++originPoints.begin(), originPoints.end(), compCounterClockwise);
    s.push(originPoints[0]);
    s.push(originPoints[1]);
    Point first, second;
    for(int i = 2; i < num; i++){
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
        hull.push_back(s.top());
        s.pop();
    }
    reverse(hull.begin(), hull.end());
    return;
}

bool checkInLine(Point &point, Point &p1, Point &p2){
    if(point.x < min(p1.x, p2.x) || point.x > max(p1.x, p2.x)){
        return false;
    }
    if(point.y < min(p1.y, p2.y) || point.y > max(p1.y, p2.y)){
        return false;
    }
    if((((long double)p2.y - p1.y) / ((long double)p2.x - p1.x)) == (((long double)p2.y - point.y) / ((long double)p2.x - point.x))){
        return true;
    }
    return false;
}

bool check(Point &point, vector<Point> &hull){
    if(hull.size() == 1){
        return false;
    }
    int cross = 0;
    Point rightEnd;
    rightEnd.x = 10001;
    rightEnd.y = point.y;
    for(int i = 0; i < hull.size(); i++){
        Point p1 = hull[i];
        Point p2 = hull[(i + 1) % hull.size()];
        if(checkInLine(point, p1, p2)){
            return true;
        }
        if(ccw(point, p1, p2) * ccw(rightEnd, p1, p2) <= 0 && ccw(p1, point, rightEnd) * ccw(p2, point, rightEnd) <= 0){
            if(ccw(point, p1, p2) * ccw(rightEnd, p1, p2) == 0 && ccw(p1, point, rightEnd) * ccw(p2, point, rightEnd) == 0){
                continue;
            }
            cross++;
        }
    }
    if(cross % 2){
        return true;
    }
    return false;
}

int solve(){
    cin >> N >> M;
    black = vector<Point>(N);
    white = vector<Point>(M);
    blackHull.clear();
    whiteHull.clear();
    for(int i = 0; i < N; i++){
        black[i].idx = i;
        ll x, y;
        cin >> x >> y;
        black[i].x = x;
        black[i].y = y;
    }
    for(int i = 0; i < M; i++){
        white[i].idx = i;
        ll x, y;
        cin >> x >> y;
        white[i].x = x;
        white[i].y = y;
    }
    if(N == 0 || M == 0){
        cout << "YES\n";
        return 0;
    }
    getConvex(black, blackHull, N);
    getConvex(white, whiteHull, M);
    if(whiteHull.size() >= 3){
        for(int i = 0; i < blackHull.size(); i++){
            if(check(blackHull[i] ,whiteHull)){
                cout << "NO\n";
                return 0;
            }
        }
    }
    if(blackHull.size() >= 3){
        for(int i = 0; i < whiteHull.size(); i++){
            if(check(whiteHull[i], blackHull)){
                cout << "NO\n";
                return 0;
            }
        }
    }
    for(auto i : blackHull){
        for(int j = 0; j < whiteHull.size(); j++){
            if(checkInLine(i, whiteHull[j], whiteHull[(j + 1) % whiteHull.size()])){
                cout << "NO\n";
                return 0;
            }
        }
    }
    for(auto i : whiteHull){
        for(int j = 0; j < blackHull.size(); j++){
            if(checkInLine(i, blackHull[j], blackHull[(j + 1) % blackHull.size()])){
                cout << "NO\n";
                return 0;
            }
        }
    }
    if(whiteHull.size() < 3 && blackHull.size() < 3){
        Point a, b, c, d;
        a = b = blackHull[0];
        c = d = whiteHull[0];
        if(blackHull.size() == 2){
            b = blackHull[1];
        }
        if(whiteHull.size() == 2){
            d = whiteHull[1];
        }
        ll ab = ccw(c, a, b) * ccw(d, a, b);
        ll cd = ccw(a, c, d) * ccw(b, c, d);
        if(ab == 0 && cd == 0){
            if(checkInLine(a, c, d) || checkInLine(b, c, d) || checkInLine(c, a, b) || checkInLine(d, a, b)){
                cout << "NO\n";
                return 0;
            }
            else{
                cout << "YES\n";
                return 0;
            }
        }
        else if(ab <= 0 && cd <= 0){
            cout << "NO\n";
            return 0;
        }
        else{
            cout << "YES\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        solve();
    }
    return 0;
}