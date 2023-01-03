#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

int N, M;
vector<int> arr;
vector<vector<int>> tree;

vector<int> generateTree(int start, int end, int idx){
    if(start == end){
        tree[idx].push_back(arr[start]);
        return tree[idx];
    }
    int mid = (start + end) / 2;
    vector<int> v1 = generateTree(start, mid, idx << 1);
    vector<int> v2 = generateTree(mid + 1, end, (idx << 1) + 1);
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(tree[idx]));
    return tree[idx];
}

int getSmaller(int start, int end, int left, int right, int idx, int pivot){
    if(left > end || right < start){
        return 0;
    }
    if(start >= left && end <= right){
        auto it = lower_bound(tree[idx].begin(), tree[idx].end(), pivot);
        return it - tree[idx].begin();
    }
    int mid = (start + end) / 2;
    return getSmaller(start, mid, left, right, idx << 1, pivot) + getSmaller(mid + 1, end, left, right, (idx << 1) + 1, pivot);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    arr = vector<int>(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    int height = ceil(log2(N));
    tree = vector<vector<int>>(1 << (height + 1));
    generateTree(1, N, 1);
    for(int tc = 0; tc < M; tc++){
        int left, right, k;
        cin >> left >> right >> k;
        int low = -1000000000;
        int high = 1000000000;
        int mid;
        while(low < high){
            mid = (low + high) / 2;
            if(low + high < 0){
                mid--;
            }
            int numSmaller = getSmaller(1, N, left, right, 1, mid);
            if(numSmaller < k){
                low = mid + 1;
            }
            else{
                high = mid;
            }
            // cout << low << " " << high << " " << mid << " "  << numSmaller << "\n";
        }
        cout << low - 1 << "\n";
    }
    // cout << getSmaller(1, N, 2, 5, 1, 2);
    // cout << getSmaller(1, N, 2, 5, 1, 3);
    // cout << getSmaller(1, N, 2, 5, 1, 4);
    // cout << getSmaller(1, N, 2, 5, 1, 5);
    // cout << getSmaller(1, N, 2, 5, 1, 6);


    return 0;
}