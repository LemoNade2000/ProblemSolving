#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

struct Query{
    int idx;
    int left, right;
    int ans;
};

int N;
vector<int> arr;
vector<int> cnt;
int M;
vector<Query*> query;
vector<int> ansArr;
int root;

bool comp(Query* a, Query* b){
    if((a->left / root) < (b->left / root)){
        return true;
    }
    else if((a->left / root) == (b->left / root)){
        if(a->right < b->right){
            return true;
        }
        else return false;
    }
    else return false;
}

bool compIdx(Query* a, Query* b){
    if(a->idx < b->idx){
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    root = sqrt(N);
    arr = vector<int>(N + 1, 0);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    cin >> M;
    ansArr = vector<int>(M, 0);
    for(int i = 0; i < M; i++){
        Query* q = new Query;
        q->idx = i;
        cin >> q->left >> q->right;
        query.push_back(q);
    }
    sort(query.begin(), query.end(), comp);
    int left, right;
    left = right = 0;
    cnt = vector<int>(1000001, 0);
    int ans = 0;
    for(auto q : query){
        if(left == 0 && right == 0){
            for(int i = q->left; i <= q->right; i++){
                if(cnt[arr[i]] == 0){
                    ans++;
                }
                cnt[arr[i]]++;
            }
            left = q->left;
            right = q->right;
        }
        else{
            if(left <= q->left){
                for(int i = left; i < q->left; i++){
                    --cnt[arr[i]];
                    if(cnt[arr[i]] == 0){
                        ans--;
                    }
                }
            }
            else{
                for(int i = left - 1; i >= q->left; i--){
                    if(cnt[arr[i]] == 0){
                        ans++;
                    }
                    cnt[arr[i]]++;
                }
            }
            if(right <= q->right){
                for(int i = right + 1; i <= q->right; i++){
                    if(cnt[arr[i]] == 0){
                        ans++;
                    }
                    cnt[arr[i]]++;
                }
            }
            else{
                for(int i = right; i > q->right; i--){
                    --cnt[arr[i]];
                    if(cnt[arr[i]] == 0){
                        ans--;
                    }
                }
            }
            left = q->left;
            right = q->right;
        }
        ansArr[q->idx] = ans;
    }
    sort(query.begin(), query.end(), compIdx);
    for(auto q : ansArr){
        cout << q << "\n";
    }
    return 0;
}