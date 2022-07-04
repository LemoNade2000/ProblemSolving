#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<
    ll,
    null_type,
    less_equal<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

int Q;
ordered_set posArr;
ordered_set negArr;
set<ll> crit;
bool zero;

int main(){
    int opnum = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> Q;
    zero = false;
    int posSize = 0;
    int negSize = 0;
    int flag = 0;
    for(int tc = 0; tc < Q; tc++){
        int op;
        cin >> op;
        if(op == 1){
            opnum = 1;
            ll a, b;
            cin >> a >> b;
            if(a > 0){
        //        cout << floor(-b1 / a1);
                posArr.insert(floor((long double)(-b) /(long double)(a)));
                posSize++;
                if(b % a == 0){
                    crit.insert(-b / a);
                }
            }
            else if(a == 0){
                if(b > 0){
                    continue;
                }
                else if(b == 0){
                    zero = true;
                }
                else{
                    flag = (flag ^ 1);
                }
            }
            else{
            //    cout << (long double)(-b) / (long double)(a);
                negArr.insert(floor((long double)(-b) / (long double)(a)));
                negSize++;
                if(b % a == 0){
                    crit.insert(-b / a);
                }
            }
        }
        else if(op == 2){
            ll c;
            cin >> c;
            if(opnum == 0){
                cout << "+\n";
                continue;
            }
            /*
            cout << "pos:";
            for(auto i : posArr){
                cout << i << " ";
            }
            cout << "\n";
            cout << "neg:";
            for(auto i : negArr){
                cout << i << " ";
            }
            cout << "\n";
            */
            if(zero){
                cout << "0\n";
                continue;
            }
            int posNum = posArr.order_of_key(c);
            int negNum = negArr.order_of_key(c);
            if(crit.count(c) > 0){
                cout << "0\n";
                continue;
            }
            posNum = posSize - posNum;
        //    cout << posNum << " " << negNum << " " << flag << " ";
            if((posNum + negNum + flag) % 2 == 0){
                cout << "+\n";
            }
            else{
                cout << "-\n";
            }
        }
    }
    return 0;
}