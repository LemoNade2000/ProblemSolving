#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Line{
    ll a, b;
    double x;
};

vector<ll> dp;
int N;
vector<ll> height, cost;
vector<Line> graph;

int binSearch(int x, int idx){
    int left, right;
    left = 0; right = idx;
    int ret = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(graph[mid].x < x){
            ret = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ret;
}

double intersect(Line &l1, Line &l2){
    return ((l2.b - l1.b) / (l1.a - l2.a + 0.0));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    height = cost = vector<ll>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> height[i];
    }
    int minIdx = N;
    for(int i = 0; i < N; i++){
        cin >> cost[i];
        if(cost[i] == 0){
            minIdx = min(minIdx, i);
        }
    }
    if(cost[0] == 0){
        cout << "0\n";
        return 0;
    }
    dp = vector<ll>(N, 0);
    dp[0] = 0;
    int idx = 0;
    for(int i = 1; i < N; i++){
        Line l;
        l = {cost[i - 1], dp[i - 1], 0};
        while(graph.size() >= 1){
            l.x = intersect(l, graph.back());
            if(l.x < graph.back().x){
                graph.pop_back();
            }
            else{
                break;
            }
        }
        graph.push_back(l);
        idx = binSearch(height[i], graph.size() - 1);
        dp[i] = graph[idx].a * height[i] + graph[idx].b;
    }
    cout << dp[N - 1];
    return 0;
}
