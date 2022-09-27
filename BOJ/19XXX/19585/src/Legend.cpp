#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Node{
    map<char, Node*> child;
    bool finished;

    Node(){
        finished = false;
    }
    ~Node(){
        for(int i = 0; i < 'z' - 'a' + 1; i++){
            if(child.count(i + 'a') > 0){
                delete child[i + 'a'];
            }
        }
    }
    void insert(string &str, int idx){
        if(idx == str.size()){
            finished = true;
            return;
        }
        if(child.count(str[idx]) == 0){
            Node* nextNode = new Node;
            child.insert({str[idx], nextNode});
            nextNode->insert(str, idx + 1);
        }
        else{
            child[str[idx]]->insert(str, idx + 1);
        }
        return;
    }
};

int C, N, Q;
Node* colorRoot;
Node* nameRoot;

void findColor(Node *currNode, string &str, int idx, vector<int> &colorFinish){
    if(currNode->finished == true){
        colorFinish[idx] = 1;
    }
    if(idx == str.size()){
        return;
    }
    if(currNode->child.count(str[idx]) == 0){
        return;
    }
    findColor(currNode->child[str[idx]], str, idx + 1, colorFinish);
    return;
}

void findName(Node *currNode, string &str, int idx, vector<int> &nameFinish, vector<int> &colorFinish){
    if(currNode->finished == true){
        if(colorFinish[idx + 1] == 1){
            cout << "Yes\n";
            return;
        }
    }
    if(idx == -1){
        cout << "No\n";
        return;
    }
    if(currNode->child.count(str[idx]) == 0){
        cout << "No\n";
        return;
    }
    findName(currNode->child[str[idx]], str, idx - 1, nameFinish, colorFinish);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> C >> N;
    colorRoot = new Node;
    nameRoot = new Node;
    for(int i = 0; i < C; i++){
        string str;
        cin >> str;
        colorRoot->insert(str, 0);
    }
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        nameRoot->insert(str, 0);
    }
    cin >> Q;
    for(int tc = 0; tc < Q; tc++){
        string str;
        cin >> str;
        vector<int> colorFinish(2001, 0);
        vector<int> nameFinish(2001, 0);
        findColor(colorRoot, str, 0, colorFinish);
        findName(nameRoot, str, str.size() -1, nameFinish, colorFinish);
    }
    delete colorRoot;
    delete nameRoot;
    return 0;
}