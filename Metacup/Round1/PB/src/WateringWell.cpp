#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Point{
    ll x, y;
};

int TC;
ifstream in;
ofstream out;
int N, Q;
vector<Point> trees;
vector<Point> wells;

int solve(){
    in >> N;
    trees = vector<Point>(N);
    for(int i = 0; i < N; i++){
        in >> trees[i].x >> trees[i].y;
    }
    in >> Q;
    wells = vector<Point>(Q);
    for(int i = 0; i < Q; i++){
        in >> wells[i].x >> wells[i].y;
    }
    ll sumA, sAsq, sumX, sXsq;
    sumA = sAsq = sumX = sXsq = 0;
    ll sumB, sBsq, sumY, sYsq;
    sumB = sBsq = sumY = sYsq = 0;
    for(auto i : trees){
        sumA += i.x;
        sumA %= MOD;
        ll sq = (i.x * i.x) % MOD;
        sAsq += sq;
        sAsq %= MOD;
        sumB += i.y;
        sumB %= MOD;
        sq = (i.y * i.y) % MOD;
        sBsq += sq;
        sBsq %= MOD;
    }
    for(auto i : wells){
        sumX += i.x;
        sumX %= MOD;
        ll sq = (i.x * i.x) % MOD;
        sXsq += sq;
        sXsq %= MOD;
        sumY += i.y;
        sumY %= MOD;
        sq = (i.y * i.y) % MOD;
        sYsq += sq;
        sYsq %= MOD;
    }
    ll ans = 0;
    ans += ((sXsq) * N) % MOD;
    ans -= (2 * (sumA) * (sumX)) % MOD;
    ans %= MOD;
    ans += (Q * sAsq) % MOD;
    ans %= MOD;
    ans += ((sYsq) * N) % MOD;
    ans %= MOD;
    ans -= (2 * (sumB) * (sumY)) % MOD;
    ans %= MOD;
    ans += (Q * sBsq) % MOD;
    ans %= MOD;
    if(ans < 0){
        ll mul = -ans / MOD;
        ans += mul * MOD;
        while(ans < 0){
            ans += MOD;
        }
    }
    out << ans << "\n";
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