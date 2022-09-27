# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> gunnar = vector<int>(4);
    vector<int> emma = vector<int>(4);
    cin >> gunnar[0] >> gunnar[1] >> gunnar[2] >> gunnar[3];
    cin >> emma[0] >> emma[1] >> emma[2] >> emma[3];
    int exGun = gunnar[0] + gunnar[1] + gunnar[2] + gunnar[3];
    int exEmm = emma[0] + emma[1] + emma[2] + emma[3];
    if(exGun > exEmm){
        cout << "Gunnar";
        return 0;
    }
    else if(exGun == exEmm){
        cout << "Tie";
        return 0;
    }
    else{
        cout << "Emma";
        return 0;
    }
    return 0;
}