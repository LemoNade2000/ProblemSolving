#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

vector<int> arr;
vector<int> box;
vector<bool> solved;
vector<int> lim;
int N, M;

bool comp(int a, int b){
    return a < b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr = vector<int>(N);
    lim = vector<int>(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), comp);
    cin >> M;
    for(int i = 0; i < M; i++){
        int n;
        cin >> n;
        box.push_back(n);
    }
    sort(box.begin(), box.end(), comp);
    if(arr[N - 1] < box[M - 1]){
        cout << "-1\n";
        return 0;
    }
    int idx = 0;
	for(int i = 0; i < M; i++){
		if(arr[idx] >= box[i]){
            lim[idx]++;	
        }
		else{
			idx++;
			i--;
		}
	}
    int cnt = 0;
    int time = 0;
    while(cnt < M){
        for(int i = N - 1; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                if(lim[j] > 0){
                    lim[j]--;
                    cnt++;
                    break;
                }
            }
            if(cnt == M){
                break;
            }
        }
        time++;
    }
    cout << time << "\n";
}