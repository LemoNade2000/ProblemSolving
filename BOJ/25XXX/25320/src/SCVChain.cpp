#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Operations{
    int player; // 0 == A, 1 == B;
    int type; // 0 == Block, 1 == chain
    int num;
};

int N, M;
set<int> blocks;
vector<Operations> history, full, ans;
int minimum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    minimum = INT_MAX;
    for(int i = 1; i <= 2 * N; i++){
        blocks.insert(i);
    }
    for(int i = 0; i < M; i++){
        char p; int n; string str;
        cin >> p >> str >> n;
        auto it = blocks.lower_bound(n);
        history.push_back({p - 'A', 0, n});
        blocks.erase(it);
        minimum = min(minimum, n);
    }
    if(minimum != 1){
        cout << "NO\n";
        return 0;
    }
    Operations preOp = history[0];
    full.push_back(preOp);
    for(int i = 1; i < M; i++){
        Operations currOp = history[i];
        if(preOp.player == currOp.player){
            auto it = blocks.lower_bound(preOp.num);
            if(it == blocks.end()){
                cout << "NO\n";
                return 0;
            }
            int n = *it;
            full.push_back({(preOp.player ^ 1), 1, n});
            blocks.erase(it);
        }
        full.push_back(currOp);
        preOp = currOp;   
    }
    if(preOp.player == 0){
        auto it = blocks.lower_bound(preOp.num);
        if(it == blocks.end()){
            cout << "NO\n";
            return 0;
        }
        int n = *it;
        full.push_back({(preOp.player ^ 1), 1, n});
        blocks.erase(it);
    }
    if(blocks.size() % 2 != 0){
        cout << "NO\n";
        return 0;
    }
    bool flag = false;
    for(int i = 0; i < full.size(); i++){
        if(flag == true){
            flag = false;
            if(full[i].type == 0){
                int np = full[i].player;
                while(!blocks.empty()){
                    auto it = blocks.begin();
                    ans.push_back({np, 1, *it});
                    blocks.erase(it);
                    np = (1 ^ np);
                }
                ans.push_back({full[i].player, full[i].type, full[i].num});
                continue;
            }
            else if(full[i].type == 1){
                ans.push_back({full[i].player, full[i].type, full[i].num});
                int np = (1 ^ full[i].player);
                while(!blocks.empty()){
                    auto it = blocks.begin();
                    ans.push_back({np, 1, *it});
                    blocks.erase(it);
                    np = (1 ^ np);
                }
                continue;
            }
        }
        ans.push_back({full[i].player, full[i].type, full[i].num});
        if(full[i].num == minimum){
            flag = true;
        }
    }
    if(flag == true){
        flag = false;
        int np = (1 ^ full[full.size() - 1].player);
        while(!blocks.empty()){
            auto it = blocks.begin();
            ans.push_back({np, 1, *it});
            blocks.erase(it);
            np = (1 ^ np);
        }
    }
    if(ans.size() != 2 * N){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n"; 
    for(auto i : ans){
        char P = i.player + 'A';
        string T = (i.type == 0) ? "BLOCK" : "CHAIN";
        cout << P << " " << T << " " << i.num << "\n";
    }
    return 0;
}