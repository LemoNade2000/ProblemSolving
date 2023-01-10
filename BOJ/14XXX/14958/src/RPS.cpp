#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> cpx;
#define MOD 1000000007
#define PI acos(-1)

vector<int> machineR, machineP, machineS;
vector<int> humanR, humanP, humanS;
vector<ll> ret;
vector<int> win;
int N, M;

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
    cin >> N >> M;        
    string str;
    cin >> str;
    machineP = machineR = machineS = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        if(str[i] == 'R'){
            machineR[i] = 1;
        }
        else if(str[i] == 'S'){
            machineS[i] = 1;
        }
        else if(str[i] == 'P'){
            machineP[i] = 1;
        }
    }
    cin >> str;
    humanP = humanR = humanS = vector<int>(M, 0);
    reverse(str.begin(), str.end());
    for(int i = 0; i < M; i++){
        if(str[i] == 'R'){
            humanR[i] = 1;
        }
        else if(str[i] == 'P'){
            humanP[i] = 1;
        }
        else if(str[i] == 'S'){
            humanS[i] = 1;
        }
    }
    win = vector<int>(N + M, 0);
    // R vs S
    multiply(machineS, humanR);
    for(int i = 0; i < N + M; i++){
        win[i] += ret[i];        
    }
    // S vs P
    multiply(machineP, humanS);
    for(int i = 0; i < N + M; i++){
        win[i] += ret[i];        
    }
    // P vs R
    multiply(machineR, humanP);
    int maxi = 0;
    for(int i = M - 1; i < N + M; i++){
        win[i] += ret[i];
        maxi = max(win[i], maxi);
    }
    cout << maxi;
    return 0;
}