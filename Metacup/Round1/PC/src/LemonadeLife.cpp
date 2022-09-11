#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Point{
    ll x, y;
};

int TC;
ofstream out;
ifstream in;
ll N, K, D;
vector<Point*> house;
vector<Point*> hull;
Point* setPoint;
ll ans;

ll dist(Point* a, Point* b){
    return (b->y - a->y) * (b->y - a->y) + (b->x - a->x) * (b->x - a->x);
}

ll crossProduct(int x1, int y1, int x2, int y2){
    return abs(x1 * y2 - x2 * y1);
}

ll ccw(Point* p1, Point* p2, Point* p3){
	return p1->x * p2->y + p2->x * p3->y + p3->x * p1->y - p2->x * p1->y - p3->x * p2->y - p1->x * p3->y;
}

bool compY(Point* p1, Point* p2){
	if(p1->y != p2->y){
		return p1->y < p2->y;
	}
	else{
		return p1->x < p2->x;
	}
}

bool compCounterClockwise(Point* p1, Point* p2){
	ll cc = ccw(setPoint, p1, p2);
	if(cc != 0){
		return cc > 0; // if cc > 0, p2 is on the left-side of p[0] p[1] vector, so it must be bigger than p1->
	}
	else return (p1->x + p1->y) < (p2->x + p2->y); // if on same line, return one with less distance
}

void getConvex(vector<Point*> &originPoints, vector<Point*> &hull, int num){
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

bool compX(Point* a, Point* b){
    if(a->x < b->x){
        return true;
    }
    else return false;
}

int solve(){
    in >> N >> K >> D;
    ll D2 = D * D;
    ans = 0;
    house = vector<Point*>(N);
    hull.clear();
    for(int i = 0; i < N; i++){
        house[i] = new Point;
        in >> house[i]->x >> house[i]->y;
    }
    getConvex(house, hull, N);
    sort(hull.begin(), hull.end(), compX);
    vector<vector<pair<int, ll>>> adj;
    adj = vector<vector<pair<int, ll>>>(hull.size());
    for(int i = 0; i < hull.size(); i++){
        for(int j = i + 1; j < hull.size(); j++){
            if(hull[j]->x - hull[i]->x > D){
                break;
            }
            if(dist(hull[i], hull[j]) > D2){
                continue;
            }
            adj[i].push_back({j, max(K, dist(hull[i], hull[j]))});
        }
    }
    priority_queue<pair<int, ll>> pq;
    vector<ll> dist;
    dist = vector<ll>(hull.size(), LLONG_MAX);
    pq.push({0, 0});
    while(!pq.empty()){
        ll cost = -pq.top().first;
        int idx = pq.top().second;
        if(idx == hull.size() - 1){
            break;
        }
        pq.pop();
        if(dist[idx] < cost){
            continue;
        }
        for(int i = 0; i < adj[idx].size(); i++){
            int nextIdx = adj[idx][i].first;
            ll nextCost = cost + adj[idx][i].second;
            if(dist[nextIdx] > nextCost){
                dist[nextIdx] = nextCost;
                pq.push({ -nextCost, nextIdx});
            }
        }
    }
    if(dist[hull.size() - 1] == LLONG_MAX){
        out << "-1\n";
    }
    else{
        out << dist[hull.size() - 1] << "\n"; 
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    in.open("input.txt");
    if(in.is_open()){
        out.open("output.txt");
        in >> TC;
        for(int tc = 1; tc <= TC; tc++){
        out << "Case #" << tc << ": ";
        solve();
        }
    }
    return 0;
}