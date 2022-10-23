# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int N;
string matrix[55];
vector<int> rowDollar[55];
vector<int> colDollar[55];
int dp[50][50][50][50];

int findMin(int rowStart, int rowEnd, int colStart, int colEnd){
    if(rowStart >= N || colStart >= N || rowEnd < 0 || colEnd < 0){
        return 0;
    }
    int &ret = dp[rowStart][rowEnd][colStart][colEnd];
    if(ret != -1){
        return ret;
    }
    if(rowStart > rowEnd || colStart > colEnd){
        return ret = 0;
    }
    if(rowStart == rowEnd || colStart == colEnd){
        int cnt = 0;
        if(rowEnd == rowStart){
            cnt = upper_bound(rowDollar[rowStart].begin(), rowDollar[rowStart].end(), colEnd) - lower_bound(rowDollar[rowStart].begin(), rowDollar[rowStart].end(), colStart);
        }
        if(colEnd == colStart){
            cnt = upper_bound(colDollar[colStart].begin(), colDollar[colStart].end(), rowEnd) - lower_bound(colDollar[colStart].begin(), colDollar[colStart].end(), rowStart);
        }
        return ret = cnt;
    }
    int iMax, iMin;
    int jMax, jMin;
    iMax = jMax = -1;
    iMin = jMin = 60;
    int cnt = 0;
    for(int i = rowStart; i <= rowEnd; i++){
        if(rowDollar[i].empty()){
            continue;
        }
        auto it = lower_bound(rowDollar[i].begin(), rowDollar[i].end(), colStart);
        if(it == rowDollar[i].end() || *it > colEnd) continue;
        else {
            iMin = i;
            cnt++;
        }

        if(iMin != 60){
            break;
        }
    }
    for(int i = rowEnd; i >= rowStart; i--){
        if(rowDollar[i].empty()){
            continue;
        }
        auto it = lower_bound(rowDollar[i].begin(), rowDollar[i].end(), colStart);
        if(it == rowDollar[i].end() || *it > colEnd) continue;
        else {
            iMax = i;
            cnt++;
        }
        if(iMax != -1){
            break;
        }
    }
    for(int i = colStart; i <= colEnd; i++){
        if(colDollar[i].empty()){
            continue;
        }
        auto it = lower_bound(colDollar[i].begin(), colDollar[i].end(), rowStart);
        if(it == colDollar[i].end() || *it > rowEnd) continue;
        else {
            jMin = i;
            cnt++;
        }
        if(jMin != 60){
            break;
        }
    }
    for(int i = colEnd; i >= colStart; i--){
        if(colDollar[i].empty()){
            continue;
        }
        auto it = lower_bound(colDollar[i].begin(), colDollar[i].end(), rowStart);
        if(it == colDollar[i].end() || *it > rowEnd) continue;
        else{
            jMax = i;
            cnt++;
        }
        if(jMax != -1){
            break;
        }
    }
    if(cnt <= 2){
        return ret = 2;
    }
    int width = jMax - jMin + 1;
    int height = iMax - iMin + 1;
    ret = max(width, height);
    int erMid = (iMin + iMax) / 2;
    int ecMid = (jMin + jMax) / 2;
    int intLeft = findMin(iMin, iMax, jMin, ecMid) + findMin(iMin, iMax, ecMid + 1, jMax);
    int intRight = findMin(iMin, erMid, jMin, jMax) + findMin(erMid + 1, iMax, jMin, jMax);
    ret = min({ret, intLeft, intRight});
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++){
        cin >> matrix[i];
    }
    int iMax, iMin;
    int jMax, jMin;
    iMax = jMax = -1;
    iMin = jMin = 60;

    deque<int> r, c;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(matrix[i][j] == '$'){
                rowDollar[i].push_back(j);
                r.push_back(i);
            }
            if(matrix[j][i] == '$'){
                colDollar[i].push_back(j);
                c.push_back(i);
            }
        }
    }
    if(r.size() <= 2){
        cout << r.size();
        return 0;
    }
    iMin = r.front();
    iMax = r.back();
    jMin = c.front();
    jMax = c.back();
    int erMid = (iMin + iMax) / 2;
    int ecMid = (jMin + jMax) / 2;
    int ans = N;
    for(int i = iMin; i <= iMax; i++){
        for(int j = jMin; j <= jMax; j++){
            ans = min(ans, findMin(iMin, i, jMin, j) + findMin(i + 1, iMax, jMin, j) + findMin(iMin, i, j + 1, jMax) + findMin(i + 1, iMax, j + 1, jMax));
        }
    }
    cout << ans;
    return 0;
}