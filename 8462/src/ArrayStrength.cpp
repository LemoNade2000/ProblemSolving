#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Query{
    int idx;
    int left;
    int right;
    int val;
    Query(int idx, int left, int right){
        this->idx = idx;
        this->left = left;
        this->right = right;
        this->val = 0;
    }
};

int root;
ll N, T;
vector<ll> arr;
vector<ll> ans;
vector<ll> cnt;
vector<Query> queries;

bool compIdx(Query a, Query b){
    if(a.idx < b.idx){
        return true;
    }
    else return false;
}

bool compRoot(Query a, Query b){
    if(a.left / root < b.left / root){
        return true;
    }
    else if(a.left / root == b.left / root){
        if(a.right < b.right){
            return true;
        }
        else return false;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> T;
    arr = vector<ll>(N);
    ans = vector<ll>(T, 0);
    root = sqrt(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }  
    for(int i = 0; i < T; i++){
        int l, r;
        cin >> l >> r;
        queries.push_back(Query(i, l - 1, r - 1));
    }
    sort(queries.begin(), queries.end(), compRoot);
    int leftIt = 0; int rightIt = 0;
    cnt = vector<ll>(1010101, 0);
    ll score = 0;
    cnt[arr[0]]++;
    score += cnt[arr[0]] * cnt[arr[0]] * arr[0];
    for(Query query : queries){
        while(rightIt < query.right){
            rightIt++;
            score -= cnt[arr[rightIt]] * cnt[arr[rightIt]] * arr[rightIt];
            cnt[arr[rightIt]]++;
            score += cnt[arr[rightIt]] * cnt[arr[rightIt]] * arr[rightIt];
        }
        while(rightIt > query.right){
            score -= cnt[arr[rightIt]] * cnt[arr[rightIt]] * arr[rightIt];
            cnt[arr[rightIt]]--;
            score += cnt[arr[rightIt]] * cnt[arr[rightIt]] * arr[rightIt];
            rightIt--;
        }
        while(leftIt > query.left){
            leftIt--;
            score -= cnt[arr[leftIt]] * cnt[arr[leftIt]] * arr[leftIt];
            cnt[arr[leftIt]]++;
            score += cnt[arr[leftIt]] * cnt[arr[leftIt]] * arr[leftIt];
        }
        while(leftIt < query.left){
            score -= cnt[arr[leftIt]] * cnt[arr[leftIt]] * arr[leftIt];
            cnt[arr[leftIt]]--;
            score += cnt[arr[leftIt]] * cnt[arr[leftIt]] * arr[leftIt];
            leftIt++;
        }
        ans[query.idx] = score;
        // cout << query.idx << " " << query.left << " " <<  query.right << " " << score << "\n";
    }
    sort(queries.begin(), queries.end(), compIdx);
    for(auto i : ans){
        cout << i << "\n";
    }
    return 0;
}