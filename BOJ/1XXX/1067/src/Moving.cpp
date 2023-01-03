#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> cpx;
#define MOD 1000000007

vector<int> a, b;
int N;
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
    double angle = 2 * acos(-1) / n;
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
    while(n < (3 * N)){
        n = (n << 1);
    }
    aFFT.resize(n); bFFT.resize(n);
    fft(aFFT, false); fft(bFFT, false);
    for(int i = 0; i < n; i++){
        aFFT[i] *= bFFT[i];
    }
    fft(aFFT, true);
    ret = vector<ll>(n);
    ll maxi = LLONG_MIN;
    for(int i = 0; i < n; i++){
        ret[i] = round(aFFT[i].real());
        maxi = max(ret[i], maxi);
    }
    cout << maxi;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    a = vector<int>(N * 2);
    b = vector<int>(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
        a[i + N] = a[i];
    }
    for(int i = 0; i < N; i++){
        cin >> b[N - 1 - i];
    }
    multiply(a, b);
    return 0;
}