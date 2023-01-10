#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> cpx;
#define MOD 1000000007
#define PI acos(-1)

string aStr, bStr;
vector<int> aVec, bVec;
vector<ll> ret;

void fft(vector<cpx> &a, bool inv = false){
    int n = a.size();
    vector<cpx> rou(n >> 1);
    for(int i = 1, j = 0; i < n; i++){
        int bit = (n >> 1);
        while(j >= bit){
            j -= bit;
            bit = (bit >> 1);
        }
        j += bit;
        if(i < j){
            swap(a[i], a[j]);
        }
    }
    double angle = 2 * PI / n;
    if(inv){
        angle *= -1;
    }
    for(int i = 0; i < (n >> 1); i++){
        rou[i] = cpx(cos(angle * i), sin(angle * i));
    }
    for(int i = 2; i <= n; i = (i << 1)){
        int angleStep = n / i;
        for(int j = 0; j < n; j += i){
            for(int k = 0; k < (i >> 1); k++){
                cpx u = a[j + k];
                cpx v = a[j + k + (i >> 1)] * rou[angleStep * k];
                a[j + k] = u + v;
                a[j + k + (i >> 1)] = u - v;
            }
        }
    }
    if(inv){
        for(int i = 0; i < n; i++){
            a[i] /= n;
        }
    }
    return;
}

vector<ll> multiply(vector<int> &a, vector<int> &b){
    vector<cpx> aFFT(a.begin(), a.end());
    vector<cpx> bFFT(b.begin(), b.end());
    int n = 2;
    while(n < (a.size() +  b.size())){
        n = (n << 1);
    }
    aFFT.resize(n); bFFT.resize(n);
    fft(aFFT, false); fft(bFFT, false);
    for(int i = 0; i < n; i++){
        aFFT[i] *= bFFT[i];
    }
    fft(aFFT, true);
    ret = vector<ll>(n);
    for(int i = 0; i < n; i++){
        ret[i] = round(aFFT[i].real());
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> aStr >> bStr;
    if(aStr == "0" || bStr == "0"){
        cout << "0\n";
        return 0;
    }
    for(int i = aStr.size() - 1; i >= 0; i--){
        aVec.push_back(aStr[i] - '0');
    }
    for(int i = bStr.size() - 1; i >= 0; i--){
        bVec.push_back(bStr[i] - '0');
    }
    multiply(aVec, bVec);
    // for(auto i : ret){
    //     cout << i << "\n";
    // }
    for(int i = 0; i < ret.size(); i++){
        ret[i + 1] += ret[i] / 10;
        ret[i] = ret[i] % 10;
    }
    int i = ret.size() - 1;
    while(ret[i] == 0){
        i--;
    }
    for(; i >= 0; i--){
        cout << ret[i];
    }
    cout << "\n";
    return 0;
}