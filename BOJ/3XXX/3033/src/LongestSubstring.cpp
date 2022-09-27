#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 10003

int N;
string str;

int power(int a, int pow){
    int res = 1;
    if(a == 1) return 1;
    while(pow > 0){
        if(pow & 1 == 1){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        pow = pow >> 1;
    }
    return res % MOD;
}

ll getModInv(ll a){
    return power(a, MOD - 2);
}

int binary(int left, int right){
    if(left == right){
        return left;
    }
    unordered_map<int, vector<int>*> hashMap;
    int mid = (left + right) / 2;
    int hashVal = 0;
    for(int i = 0; i < mid; i++){
        hashVal = (hashVal << 1);
        hashVal += str[i] - 'a' + 1;
        hashVal %= MOD;
    }
    vector<int>* v = new vector<int>(1, 0);
    hashMap.insert({hashVal, v});
    bool flag = false;
    // cout << mid << " " << hashVal << "\n";
    for(int i = 1; i + mid <= N; i++){
        hashVal -= ((str[i - 1] - 'a' + 1) * power(2, mid - 1)) % MOD;
        hashVal = (hashVal << 1);
        hashVal %= MOD;
        hashVal += str[i + mid - 1] - 'a' + 1;
        hashVal %= MOD;
        if(hashVal < 0){
            hashVal += MOD;
        }
        // cout << mid << " " << hashVal << "\n";
        if(hashMap.count(hashVal) == 0){
            vector<int>* nv = new vector<int>(1, i);
            hashMap.insert({hashVal, nv});
        }
        else{
            // cout << "yes" << " " << mid << "\n";
            for(auto startIdx : (*hashMap[hashVal])){
                if(str.compare(startIdx, mid, str, i, mid) == 0){
                    flag = true;
                    break;
                }
            }
            hashMap[hashVal]->push_back(i);
        }
        if(flag == true){
            break;
        }
    }
    if(flag == true){
        if(right - mid == 1){
            return mid;
        }
        return binary(mid, right);
    }
    else {
        if(mid - left == 1){
            return left;
        }
        return binary(left, mid);
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> str;
    cout << binary(0, N - 1);
    return 0;
}