#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, K, D;
struct Student{
    int M, d;
    vector<int> algo;
};
vector<Student> arr;
vector<int> cnt;

bool comp(Student a, Student b){
    if(a.d > b.d){
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> D;
    for(int i = 0; i < N; i++){
        int M, d;
        cin >> M >> d;
        Student st;
        st.d = d;
        st.M = M;
        for(int j = 0; j < M; j++){
            int a;
            cin >> a;
            st.algo.push_back(a);
        }
        arr.push_back(st);
    }
    sort(arr.begin(), arr.end(), comp);
    int left = 0; int right = 0;
    cnt = vector<int>(31, 0);
    int uni, inter;
    uni = inter = 0;
    int ans = 0;
    for(; left < N; left++){
        while(arr[left].d - arr[right].d <= D && right < N){
            for(int i = 0; i < arr[right].algo.size(); i++){
                int algoNum = arr[right].algo[i];
                cnt[algoNum]++;
            }
            right++;
        }
        int n = right - left;
        uni = inter = 0;
        for(int i = 1; i <= 30; i++){
            if(cnt[i] > 0){
                uni++;
            }
            if(cnt[i] == n){
                inter++;
            }
        }
        ans = max(ans, n * (uni - inter));
        for(int i = 0; i < arr[left].algo.size(); i++){
            int algoNum = arr[left].algo[i];
            cnt[algoNum]--;
        }
    }
    cout << ans;
    return 0;
}