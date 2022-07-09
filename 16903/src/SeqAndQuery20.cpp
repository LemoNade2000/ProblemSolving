#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Node{
    Node* child[2];
    int l, r; // 0 , 1;
    Node(){
        l = 0;
        r = 0;
    }
    ~Node(){
        if(l != 0){
            delete child[0];
        }
        if(r != 0){
            delete child[1];
        }
    }
    void insert(int pos, string &str){
        if(pos == 30){
            return;
        }
        if(str[pos] == '1'){
            if(r == 0){
                Node *node = new Node();
                child[1] = node;
            }
            r++;
            child[1]->insert(pos + 1, str);
        }
        else if(str[pos] == '0'){
            if(l == 0){
                Node *node = new Node();
                child[0] = node;
            }
            l++;
            child[0]->insert(pos + 1, str);
        }
        return;
    }
    void erase(int pos, string &str){
        if(pos == 30){
            return;
        }
        if(str[pos] == '1'){
            --r;
            if(r == 0){
                delete child[1];
                return;
            }
            child[1]->erase(pos + 1, str);
        }
        else if(str[pos] == '0'){
            --l;
            if(l == 0){
                delete child[0];
                return;
            }
            child[0]->erase(pos + 1, str);
        }
        return;
    }
};

int M;
Node* root;

int travel(Node *node, int pos, string &str, int ans){
    if(pos == 30){
        return ans;
    }
    ans = (ans << 1);
    if(str[pos] == '0'){
        if(node->r > 0){
            ans = ans + 1;
            return travel(node->child[1], pos + 1, str, ans);
        }
        else if(node->l > 0){
            return travel(node->child[0], pos + 1, str, ans);
        }
    }
    if(str[pos] == '1'){
        if(node->l > 0){
            ans = ans + 1;
            return travel(node->child[0], pos + 1, str, ans);
        }
        else if(node->r > 0){
            return travel(node->child[1], pos + 1, str, ans);
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M;
    root = new Node();
    string str = "000000000000000000000000000000";
    root->insert(0, str);
    for(int tc = 0; tc < M; tc++){
        int op;
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            string str = "000000000000000000000000000000"; // 2 ^ 30 - 1
            int pos = 29;
            while(x > 0){
                if(x & 1){
                    str[pos] = '1';
                }
                x = (x >> 1);
                pos--;
            }
            root->insert(0, str);
        }
        else if(op == 2){
            int x;
            cin >> x;
            string str = "000000000000000000000000000000"; // 2 ^ 30 - 1
            int pos = 29;
            while(x > 0){
                if(x & 1){
                    str[pos] = '1';
                }
                x = (x >> 1);
                pos--;
            }
            root->erase(0, str);
        }
        else if(op == 3){
            int x;
            cin >> x;
            string str = "000000000000000000000000000000"; // 2 ^ 30 - 1
            int pos = 29;
            while(x > 0){
                if(x & 1){
                    str[pos] = '1';
                }
                x = (x >> 1);
                pos--;
            }
            cout << travel(root, 0, str, 0) << "\n";
        }
    }
}