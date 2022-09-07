#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Point{
    ll x, y;
    int idx;
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
    if(num == 0){
        return;
    }
    else if(num == 1){
        hull.push_back(originPoints[0]);
        return;
    }
    stack<Point> s;
    sort(originPoints.begin(), originPoints.end(), compY);
    setPoint = originPoints[0];
    sort(originPoints.begin() + 1, originPoints.end(), compCounterClockwise);
	for(auto i : originPoints){
		while (hull.size() >= 2 && ccw(i, hull[hull.size() - 2], hull.back()) <= 0) hull.pop_back();
		hull.push_back(i);
	}
    return;
}

bool checkInner(Point &point, vector<Point> &hull){
    int cross = 0;
    int hS = hull.size();
    pair<double, double> pp = {point.x, point.y};
    for(int i = 0; i < hS; i++){
        pair<double, double> ii, jj;
        ii = {hull[i].x, hull[i].y}; jj = {hull[(i + 1) % hS].x, hull[(i + 1) % hS].y};
        if((hull[i].y < point.y) ^ (hull[(i + 1) % hS].y < point.y)){
            double xPoint = (jj.first - ii.first) * (pp.second - ii.second) / (jj.second - ii.second) + ii.first;
            if(pp.first < xPoint){
                cross++;
            }
        }
    }
    return (cross % 2) > 0;
}

bool disjoint(ll a, ll b, ll c, ll d){
    if(a > b){
        swap(a, b);
    }
    if(c > d){
        swap(c, d);
    }
    if(b < c || a > d){
        return true;
    }
    else return false;
}

bool check(Point &a, Point &b, Point &c, Point &d){
    ll abc = ccw(c, a, b);
    ll abd = ccw(d, a, b);
    ll cda = ccw(a, c, d);
    ll cdb = ccw(b, c, d);
    if(abc * abd == 0 && cda * cdb == 0){
        if(!disjoint(a.x, b.x, c.x, d.x) && !disjoint(a.y, b.y, c.y, d.y)){
            return true;
        }
        else return false;
    }
    if(abc * abd <= 0 && cda * cdb <= 0){
        return true;
    }
    else return false;
}

int solve(){
    black.clear();
    white.clear();
    blackHull.clear();
    whiteHull.clear();
    bool flag = true;
    cin >> N >> M;
    black = vector<Point>(N);
    white = vector<Point>(M);
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
    if(N + M <= 2){
        cout << "YES\n";
        return 0;
    }
    getConvex(black, blackHull, N);
    getConvex(white, whiteHull, M);
    // for(auto i : blackHull){
    //     cout << i.x << " " << i.y << "\n";
    // }
    for(int i = 0; i < whiteHull.size(); i++){
        if(checkInner(whiteHull[i], blackHull)){
            flag = false;
        }
    }

    for(int i = 0; i < blackHull.size(); i++){
        if(checkInner(blackHull[i], whiteHull)){
            flag = false;
        }
    }
    for(int i = 0; i < blackHull.size(); i++){
        for(int j = 0; j < whiteHull.size(); j++){
            int ip = (i + 1) % blackHull.size();
            int jp = (j + 1) % whiteHull.size();
            if(check(blackHull[i], blackHull[ip], whiteHull[j], whiteHull[jp])){
                flag = false;
            }
        }
    }
    if(flag){
        cout << "YES\n";
        return 0;
    }
    else{
        cout << "NO\n";
        return 0;
    }
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