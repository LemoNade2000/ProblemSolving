#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int c, n;

struct Point{
    int idx;
    double x, y;
    double cos;
};

bool cmp(Point &a, Point &b){
    if(a.cos > b.cos){
        return true;
    }
    else if(a.cos == b.cos){
        if(a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> c;
    for(int tc = 0; tc < c; tc++){
        vector<Point> points;
        cin >> n;
        double minY = DBL_MAX;
        double minX = DBL_MAX;
        int minIdx = -1;
        for(int i = 0; i < n; i++){
            double x, y;
            cin >> x >> y;
            points.push_back({i, x, y, 0});
            if(y < minY){
                minY = y;
                minX = x;
                minIdx = i;
            }
            else if(y == minY){
                if(x < minX){
                    minY = y;
                    minX = x;
                    minIdx = i;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(i == minIdx){
                points[i].cos = 2;
                continue;
            }
            points[i].x = points[i].x - points[minIdx].x;
            points[i].y = points[i].y - points[minIdx].y;
            if(points[i].x > 0){
                points[i].cos = points[i].x * points[i].x / (points[i].x * points[i].x + points[i].y * points[i].y);
            }
            else{
                points[i].cos = points[i].x * points[i].x / (points[i].x * points[i].x + points[i].y * points[i].y);
                points[i].cos *= -1;
            }
        }
        sort(points.begin(), points.end(), cmp);
        double lastCos = points[n - 1].cos;
        int lastIdx = n - 1;
        for(; lastIdx >= 0; lastIdx--){
            if(points[lastIdx].cos != lastCos){
                break;
            }
        }
        for(int i = 0; i <= lastIdx; i++){
            cout << points[i].idx << " ";
        }
        for(int i = n - 1; i > lastIdx; i--){
            cout << points[i].idx << " ";
        }
        cout << "\n";
    }
    return 0;
}