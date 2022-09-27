#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

struct Node{
    int lazy, val;
};

int C, O, N;
vector<Node> minTree;
vector<Node> maxTree;

int updateMin(int start, int end, int left, int right, int idx, int diff){
    if(minTree[idx].lazy != 0){
        minTree[idx].val += minTree[idx].lazy;
        if(start != end){
            minTree[idx * 2].lazy += minTree[idx].lazy;
            minTree[(idx * 2) + 1].lazy += minTree[idx].lazy;
        }
        minTree[idx].lazy = 0;
    }
    if(start > right || end < left){
        return minTree[idx].val;
    }
    else if(start >= left && end <= right){
        minTree[idx].val += diff;
        if(start != end){
            minTree[idx * 2].lazy += diff;
            minTree[(idx * 2) + 1].lazy += diff;
        }
        return minTree[idx].val;
    }
    int mid = (start + end) / 2;
    return minTree[idx].val = min(updateMin(start, mid, left, right, idx * 2, diff), updateMin(mid + 1, end, left, right, (idx * 2) + 1, diff));
}

int updateMax(int start, int end, int left, int right, int idx, int diff){
    if(maxTree[idx].lazy != 0){
        maxTree[idx].val += maxTree[idx].lazy;
        if(start != end){
            maxTree[idx * 2].lazy += maxTree[idx].lazy;
            maxTree[(idx * 2) + 1].lazy += maxTree[idx].lazy;
        }
        maxTree[idx].lazy = 0;
    }
    if(start > right || end < left){
        return maxTree[idx].val;
    }
    else if(start >= left && end <= right){
        maxTree[idx].val += diff;
        if(start != end){
            maxTree[idx * 2].lazy += diff;
            maxTree[(idx * 2) + 1].lazy += diff;
        }
        return maxTree[idx].val;
    }
    int mid = (start + end) / 2;
    return maxTree[idx].val = max(updateMax(start, mid, left, right, idx * 2, diff), updateMax(mid + 1, end, left, right, (idx * 2) + 1, diff));
}

int queryMin(int start, int end, int left, int right, int idx){
    if(minTree[idx].lazy != 0){
        minTree[idx].val += minTree[idx].lazy;
        if(start != end){
            minTree[idx * 2].lazy += minTree[idx].lazy;
            minTree[(idx * 2) + 1].lazy += minTree[idx].lazy;
        }
        minTree[idx].lazy = 0;
    }
    if(start > right || end < left){
        return INT_MAX;
    }
    else if(start >= left && end <= right){
        return minTree[idx].val;
    }
    int mid = (start + end) / 2;
    return min(queryMin(start, mid, left, right, idx * 2), queryMin(mid + 1, end, left, right, (idx * 2) + 1));
}

int queryMax(int start, int end, int left, int right, int idx){
    if(maxTree[idx].lazy != 0){
        maxTree[idx].val += maxTree[idx].lazy;
        if(start != end){
            maxTree[idx * 2].lazy += maxTree[idx].lazy;
            maxTree[(idx * 2) + 1].lazy += maxTree[idx].lazy;
        }
        maxTree[idx].lazy = 0;
    }
    if(start > right || end < left){
        return INT_MIN;
    }
    else if(start >= left && end <= right){
        return maxTree[idx].val;
    }
    int mid = (start + end) / 2;
    return max(queryMax(start, mid, left, right, idx * 2), queryMax(mid + 1, end, left, right, (idx * 2) + 1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> C >> N >> O;
    int depth = ceil(log2(C));
    minTree = vector<Node>((1 << (depth + 1)));
    maxTree = vector<Node>((1 << (depth + 1)));
    for(int o = 0; o < O; o++){
        string str;
        cin >> str;
        if(str == "state"){
            int x;
            cin >> x;
            x++;
            cout << queryMin(1, C, x, x, 1) << "\n";
        }
        else if(str == "change"){
            int x, s;
            cin >> x >> s;
            x++;
            int maximum = queryMax(1, C, x, x, 1);
            int minimum = queryMin(1, C, x, x, 1);
            if(s + maximum > N){
                s = N - maximum;
            }
            else if(minimum + s < 0){
                s = -minimum;
            }
            cout << s << "\n";
            updateMin(1, C, x, x, 1, s);
            updateMax(1, C, x, x, 1, s);
        }
        else if(str == "groupchange"){
            int a, b, s;
            cin >> a >> b >> s;
            a++; b++;
            int maximum = queryMax(1, C, a, b, 1);
            int minimum = queryMin(1, C, a, b, 1);
            if(s + maximum > N){
                s = N - maximum;
            }
            else if(minimum + s < 0){
                s = -minimum;
            }
            cout << s << "\n";
            updateMin(1, C, a, b, 1, s);
            updateMax(1, C, a, b, 1, s);
        }
        // cout << queryMin(1, C, 1, C, 1);
    }
    return 0;
}