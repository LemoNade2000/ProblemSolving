#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

struct Line{
    ll m;
    ll b;
    double xPos;
    Line(ll m, ll b, double xPos){
        this->m = m;
        this->b = b;
        this->xPos = xPos;
    }
    ll f(ll x){
        return m * x + b;
    }
};

int N;
ll a, b, c;
int lineIdx;
vector<ll> arr;
vector<ll> dp;
vector<Line> convex;

double intersect(Line &a, Line &b){
    return (double)-(b.b - a.b) / (b.m - a.m);
}

int addLine(ll slope, ll intercept){
    Line curr = Line(slope, intercept, 0);
    if(convex.empty()){
        convex.push_back(Line(slope, intercept, -1e9));
        return 0;
    }
    while(!convex.empty()){
        double inter = intersect(convex.back(), curr);
        if(inter <= convex.back().xPos){
            convex.pop_back();
        }
        else{
            break;
        }
    }
    double inter = intersect(convex.back(), curr);
    convex.push_back(Line(slope, intercept, inter));
    if(lineIdx >= convex.size()){
        lineIdx = convex.size() - 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> a >> b >> c;
    lineIdx = 0;
    arr = vector<ll>(N + 1, 0);
    dp = vector<ll>(N + 1, 0);
    for(int i = 1; i <= N; i++){
        ll n;
        cin >> n;
        arr[i] = arr[i - 1] + n;
    }
    dp[1] = a * arr[1] * arr[1] + b * arr[1] + c;
    addLine(-2 * arr[1] * a, a * arr[1] * arr[1] - b * arr[1] + dp[1]);
    for(int i = 2; i <= N; i++){
        // for(auto i : convex){
        //     cout << i.m << " " << i.b << " " << i.xPos << "\n";
        // }
        ll x = arr[i];
        while(true){
            if(lineIdx < convex.size() - 1 && convex[lineIdx + 1].xPos < x){
                lineIdx++;
            }
            else{
                break;
            }
        }
        dp[i] = max(a * x * x + b *x + c, convex[lineIdx].f(x) + x * x * a + x * b + c);
        addLine(-2 * a * arr[i], a * arr[i] * arr[i] - b * arr[i] + dp[i]);
        // cout << dp[i] << "\n";
    }
    cout << dp[N];
    return 0;
}