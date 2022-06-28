#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Point{
    int x;
    int y;
};

double minimum;
Point setPoint;

double crossProduct(int x1, int y1, int x2, int y2){
    return abs(x1 * y2 - x2 * y1);
}

long long int ccw(Point p1, Point p2, Point p3){
	return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p2.x * p1.y - p3.x * p2.y - p1.x * p3.y;
}

bool compY(Point p1, Point p2){
	if(p1.y != p2.y){
		return p1.y < p2.y;
	}
	else{
		return p1.x < p2.x;
	}
}

bool compCounterClockwise(Point p1, Point p2){
	long long int cc = ccw(setPoint, p1, p2);
	if(cc != 0){
		return cc > 0; // if cc > 0, p2 is on the left-side of p[0] p[1] vector, so it must be bigger than p1.
	}
	else return (p1.x + p1.y) < (p2.x + p2.y); // if on same line, return one with less distance
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
    int N;
    cout << fixed << setprecision(2);
    int caseNum = 1;
    while(true){
        cin >> N;
        if(N == 0){
            break;
        }
        vector<Point> points, originPoints;
        minimum = DBL_MAX;
        for(int i = 0; i < N; i++){
            int X, Y;
            cin >> X >> Y;
            originPoints.push_back({X, Y});
        }
        getConvex(originPoints, points, N);
        N = points.size();
        Point p1 = points[N - 1];
        Point p2 = points[0];
        Point vect1 = {p2.x - p1.x, p2.y - p1.y};
        double vectSize = sqrt(vect1.x * vect1.x + vect1.y * vect1.y);
        double maximum = 0;
        for(int i = 1; i < N - 1; i++){
            Point p3 = points[i];
            Point vect2 = {p3.x - p1.x, p3.y - p1.y};
            maximum = max(maximum, crossProduct(vect1.x, vect1.y, vect2.x, vect2.y) / vectSize);
        }
        minimum = min(minimum, maximum);
        for(int i = 0; i < N - 1; i++){
            p1 = points[i];
            p2 = points[i + 1];
            vect1 = {p2.x - p1.x, p2.y - p1.y};
            vectSize = sqrt(vect1.x * vect1.x + vect1.y * vect1.y);
            maximum = 0;
            for(int j = 0; j < N; j++){
                if(j == i || j == i + 1){
                    continue;
                }
                Point p3 = points[j];
                Point vect2 = {p3.x - p1.x, p3.y - p1.y};
                maximum = max(maximum, crossProduct(vect1.x, vect1.y, vect2.x, vect2.y) / vectSize);
            }
            minimum = min(minimum, maximum);
        }
        minimum = (ceil(minimum * 100))/100;
        cout << "Case " << caseNum << ": " << minimum << "\n";
        caseNum++;
    }
}