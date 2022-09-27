    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef pair<int, int> pii;
    #define MOD 1000000007

    int TC;
    int N;

    struct Node{
        Node* parent;
        string name;
        int cnt;
        int idx;
        Node(string &str, int idx){
            parent = this;
            cnt = 1;
            name = str;
            this->idx = idx;
        }
    };

    map<string, Node*> strMap;

    string find(string &str){
        if(strMap[str]->parent->name == strMap[str]->name){
            return strMap[str]->name;
        }
        else{
            return find(strMap[str]->parent->name);
        }
    }

    void unionNetwork(string &strA, string &strB){
        string parA = find(strA);
        string parB = find(strB);
        if(parA == parB){
            cout << strMap[parA]->cnt << "\n";
            return;
        }
        if(strMap[parA]->idx < strMap[parB]->idx){
            strMap[parB]->parent = strMap[parA];
            strMap[parA]->cnt += strMap[parB]->cnt;
            cout << strMap[parA]->cnt << "\n";
        }
        else{
            strMap[parA]->parent = strMap[parB];
            strMap[parB]->cnt += strMap[parA]->cnt;
            cout << strMap[parB]->cnt << "\n";
        }
        return;
    }

    int solve(){
        cin >> N;
        int idx = 0;
        for(int i = 0; i < N; i++){
            string strA, strB;
            cin >> strA >> strB;
            if(strMap.count(strA) == 0){
                Node* node = new Node(strA, idx);
                strMap.insert({strA, node});
                idx++;
            }
            if(strMap.count(strB) == 0){
                Node* node = new Node(strB, idx);
                strMap.insert({strB, node});
                idx++;
            }
            unionNetwork(strA, strB);
        }
        for(auto i : strMap){
            delete i.second;
        }
        strMap.clear();
        return 0;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> TC;
        for(int tc = 0; tc < TC; tc++){
            solve();
        }
        return 0;
    }