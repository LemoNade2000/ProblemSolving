# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> cpx;
#define MOD 1000000007
#define PI acos(-1)

vector<int> arr, doubleArr;
vector<int> ret;
int N;

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

vector<int> multiply(vector<int> &a){
    vector<cpx> aFFT(a.begin(), a.end());
    int n = 2;
    while(n < (2 * a.size())){
        n = (n << 1);
    }
    aFFT.resize(n);
    fft(aFFT, false);
    for(int i = 0; i <= n; i++){
        aFFT[i] *= aFFT[i];
    }
    fft(aFFT, true);
    ret = vector<int>(n);
    for(int i = 0; i < 500001; i++){
        ret[i] = round(aFFT[i].real());
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    arr = vector<int>(1000001, 1);
    for(int i = 2; i <= sqrt(1000000); i++){
        if(arr[i] == 1){
            for(int j = i * i; j <= 1000000; j += i){
                arr[j] = 0;
            }
        }
    }
    arr[0] = arr[1] = 0;
    doubleArr = vector<int>(500001, 0);
    for(int i = 3; i <= 1000000; i++){
        if(arr[i] == 1){
            doubleArr[(i - 1) / 2] = 1;
        }
    }
    multiply(doubleArr);
    for(int i = 0; i < N; i++){
        int k;
        cin >> k;
        if(k == 4){
            cout << "1\n";
            continue;
        }
        if(arr[k / 2] == 1){
            cout << ((ret[(k / 2) - 1] + 1) / 2) << "\n"; 
        }
        else{
            cout << (ret[(k / 2) - 1] / 2) << "\n";
        }
    }
    return 0;
}