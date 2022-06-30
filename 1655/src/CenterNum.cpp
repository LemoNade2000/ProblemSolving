#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<int> arr;
priority_queue<int> minPQ, maxPQ;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    for(int i = 0; i < N; i++){
        if(maxPQ.size() > minPQ.size()){
            minPQ.push(-arr[i]);
        }
        else{
            maxPQ.push(arr[i]);
        }

        if(!maxPQ.empty() && !minPQ.empty()){
            if(maxPQ.top() > -minPQ.top()){
                int maximum = maxPQ.top();
                int minimum = -minPQ.top();
                maxPQ.pop();
                minPQ.pop();
                maxPQ.push(minimum);
                minPQ.push(-maximum);
            }
        }

        cout << maxPQ.top() << "\n";
    }
    return 0;
}