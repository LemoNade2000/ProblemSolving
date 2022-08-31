#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

struct Query{
    int idx;
    int left, right;
    Query(int idx, int left, int right){
        this->idx = idx;
        this->left = left;
        this->right = right;
    }
};

int N, C;
int M;
int sqroot;
vector<int> arr;
vector<int> tree;
vector<int> cnt;
vector<int> ans;
vector<int> cntNum;
vector<int> num;
vector<int> col;
vector<int> maxCol;
vector<Query> queries;

bool compRoot(Query a, Query b){
    if((a.left / sqroot) < (b.left / sqroot)){
        return true;
    }
    else if((a.left / sqroot) == (b.left / sqroot)){
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
    cin >> N >> C;
    arr = vector<int>(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    sqroot = sqrt(N);
    cnt = vector<int>(C + 1, 0);
    cin >> M;
    ans = vector<int>(M, 0);
    for(int i = 0; i < M; i++){
        int l, r;
        cin >> l >> r;
        Query q = Query(i, l, r);
        queries.push_back(q);
        num.push_back(r - l + 1);
    }
    sort(queries.begin(), queries.end(), compRoot);
    int leftIdx = queries[0].left; int rightIdx = queries[0].left;
    cnt[arr[leftIdx]]++;
    int max = 1;
    col = vector<int>(M, 0);
    int idx = 0;
    for(auto query : queries){
        while(leftIdx < query.left){
            cnt[arr[leftIdx]]--;
            leftIdx++;
        }
        while(leftIdx > query.left){
            leftIdx--;
            cnt[arr[leftIdx]]++;
        }
        while(rightIdx < query.right){
            rightIdx++;
            cnt[arr[rightIdx]]++;
        }
        while(rightIdx > query.right){
            cnt[arr[rightIdx]]--;
            rightIdx--;
        }
        ans[query.idx] = max;
        int thresh = num[query.idx] / 2;
        for(int i = 1; i <= C; i++){
            if(cnt[i] > thresh){
                col[query.idx] = i;
            }
        }
    }
    for(int i = 0; i < M; i++){
        if(col[i] != 0){
            cout << "yes" << " " << col[i] << "\n";
        }
        else{
            cout << "no\n";
        }
    }
    return 0;
}