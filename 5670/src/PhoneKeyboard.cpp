#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
int cnt;

struct Trie{
    bool isRoot;
    bool isEnd;
    unique_ptr<Trie> Node['z' - 'a' + 1];
    int childCnt;
    Trie(){
        isEnd = false;
        isRoot = false;
        childCnt = 0;
        for(int i = 0; i < 'z' - 'a' + 1; i++){
            Node[i] = NULL;
        }
    }
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;
    ~Trie() = default;
    /*
    ~Trie(){
        for(int i = 0; i < 'z' - 'a' + 1; i++){
            if(Node[i]) delete Node[i];
        }
    }
    */
};

void generateTrie(string str, unique_ptr<Trie> &parent, int pos){
    char currChar = str[pos];
    if(parent->Node[currChar - 'a'] == nullptr){
        unique_ptr<Trie> currNode = make_unique<Trie>();
        parent->childCnt++;
        parent->Node[currChar - 'a'] = move(currNode);
        if(pos == str.length() - 1){
            parent->Node[currChar - 'a']->isEnd = true;
            return;
        }
        generateTrie(str, parent->Node[currChar - 'a'], pos + 1);
        return;
    }
    else if(parent->Node[currChar - 'a'] != nullptr){
        if(pos == str.length() - 1){
            parent->Node[currChar - 'a']->isEnd = true;
            return;
        }
        generateTrie(str, parent->Node[currChar - 'a'], pos + 1);
        return;
    }
}

int findTrie(unique_ptr<Trie> &parent, string str, int pos){
    int count = 0;
    char currChar = str[pos];
    if(parent->isRoot == true){
        count++;
//        cout <<"here1";
        if(pos == str.length() - 1){
            return count;
        }
        count += findTrie(parent->Node[currChar - 'a'], str, pos + 1);
        return count;
    }
    if(parent->childCnt >= 2 || parent->isEnd == true){
//        cout << pos << " " << parent->childCnt << "\n";
        count = 1;
    }

    if(pos == str.length() - 1){
        return count;
    }
    count += findTrie(parent->Node[currChar - 'a'], str, pos + 1);
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
        unique_ptr<Trie> root = make_unique<Trie>();
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
    }
    return 0;
}
