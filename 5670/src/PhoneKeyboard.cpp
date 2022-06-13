#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
int cnt;

struct Trie{
    bool isRoot;
    bool isEnd;
    Trie *Node['z' - 'a' + 1];
    int childCnt;
    Trie(){
        isEnd = false;
        isRoot = false;
        childCnt = 0;
        for(int i = 0; i < 'z' - 'a' + 1; i++){
            Node[i] = NULL;
        }
    }
    ~Trie(){
        for(int i = 0; i < 'z' - 'a' + 1; i++){
            if(Node[i]) delete Node[i];
        }
    }
};

void generateTrie(string str, Trie *parent, int pos){
    char currChar = str[pos];
    if(parent->Node[currChar - 'a'] == NULL){
        Trie *currNode = new Trie();
        parent->childCnt++;
        parent->Node[currChar - 'a'] = currNode;
        if(pos == str.length() - 1){
            (*currNode).isEnd = true;
            return;
        }
        generateTrie(str, currNode, pos + 1);
        return;
    }
    else if(parent->Node[currChar - 'a'] != NULL){
        Trie *currNode = parent->Node[currChar - 'a'];
        if(pos == str.length() - 1){
            currNode->isEnd = true;
            return;
        }
        generateTrie(str, currNode, pos + 1);
        return;
    }
}

int findTrie(Trie *parent, string str, int pos){
    int count = 0;
    char currChar = str[pos];
    if(parent->isRoot == true){
        count++;
//        cout <<"here1";
        if(pos == str.length() - 1){
            return count;
        }
        Trie *currNode = parent->Node[currChar - 'a'];
        count += findTrie(currNode, str, pos + 1);
        return count;
    }
    Trie *currNode = parent->Node[currChar - 'a'];
    if(parent->childCnt >= 2 || parent->isEnd == true){
//        cout << pos << " " << parent->childCnt << "\n";
        count = 1;
    }

    if(pos == str.length() - 1){
        return count;
    }
    count += findTrie(currNode, str, pos + 1);
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(2);
    while(cin >> N){
        if(N == -1){
            break;
        }
        vector<string> dict;
        for(int i = 0; i < N; i++){
            string str;
            cin >> str;
            dict.push_back(str);
        }
        Trie *root = new Trie();
        (*root).isRoot = true;
        for(int i = 0; i < N; i++){
            string str = dict[i];
            generateTrie(str, root, 0);
        }
        cnt = 0;
        for(int i = 0; i < N; i++){
            string str = dict[i];
            cnt += findTrie(root, str, 0);
        }
        double ans = (double)cnt / (double)N;
        cout << ans << "\n";
        delete root;
    }
    return 0;
}
