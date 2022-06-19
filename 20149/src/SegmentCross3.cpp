#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Line{
    long double x1, y1, x2, y2;
    long double slope;
    long double intercept;
    long double domainStart;
    long double domainEnd;
    long double rangeStart;
    long double rangeEnd;
    bool vertical = false;
    
    void doMath(){
        if(x2 == x1){
            slope = 0;
            vertical = true;
        }
        else{
            slope = (y2 - y1) / (x2 - x1);
        }
        intercept = y1 - (x1 * slope);
        domainStart = min(x1, x2);
        domainEnd = max(x1, x2);
        rangeStart = min(y1, y2);
        rangeEnd = max(y1, y2);
    }
    long double getY(long double x){
        return x * slope + intercept;
    }
};

int doMoreMath(Line &l1, Line &l2){
    if(l1.slope == l2.slope){
        if(l1.intercept != l2.intercept){
            cout << "0";
            return 0;
        }
        else if(l1.domainStart == l2.domainEnd){
            cout << "1\n";
            cout << l1.domainStart << " " << l1.getY(l1.domainStart);
            return 0;
        }
        else if(l2.domainStart == l1.domainEnd){
            cout << "1\n";
            cout << l2.domainStart << " " << l2.getY(l2.domainStart);
            return 0;
        }
        else if(l1.domainEnd > l2.domainStart && l1.domainStart < l2.domainEnd){
            cout << "1\n";
            return 0;
        }
        else if(l2.domainEnd > l1.domainStart && l2.domainStart < l1.domainEnd){
            cout << "1\n";
            return 0;
        }
        else{
            cout << "0";
            return 0;
        }
    }
    else{
        long double px = (l1.x1 * l1.y2 - l1.x2 * l1.y1) * (l2.x1 - l2.x2) - (l1.x1 - l1.x2) * (l2.x1 * l2.y2 - l2.x2 * l2.y1);
        long double py = (l1.x1 * l1.y2 - l1.x2 * l1.y1) * (l2.y1 - l2.y2) - (l1.y1 - l1.y2) * (l2.x1 * l2.y2 - l2.x2 * l2.y1);
        long double p = (l1.x1 - l1.x2) * (l2.y1 - l2.y2) - (l1.y1 - l1.y2) * (l2.x1 - l2.x2);    
        long double intPx = px / p;
        long double intPy = py / p;
        if(intPx >= l1.domainStart && intPx <= l1.domainEnd){
            cout << "1\n" << intPx << " " << intPy;
            return 0;
        }
        else{
            cout << "0";
            return 0;
        }
    }   
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Line l1;
    l1.x1 = x1; l1.y1 = y1; l1.x2 = x2; l1.y2 = y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Line l2;
    l2.x1 = x1; l2.y1 = y1; l2.x2 = x2; l2.y2 = y2;
    l1.doMath();
    l2.doMath();
    if(l1.vertical == true){
        if(l2.vertical == true){
            if(l1.domainStart != l2.domainStart){
                cout << "0";
                return 0; 
            }
            else{
                if(l1.rangeEnd == l2.rangeStart){
                    cout << "1\n";
                    cout << l1.domainStart << " " << l1.rangeEnd;
                    return 0;
                }
                else if(l2.rangeEnd == l1.rangeStart){
                    cout << "1\n";
                    cout << l1.domainStart << " " << l2.rangeEnd;
                    return 0;
                }
                else if(l1.rangeEnd > l2.rangeStart && l1.rangeStart < l2.rangeEnd){
                    cout << "1\n";
                    return 0;
                }
                else if(l2.rangeEnd > l1.rangeStart && l2.rangeStart < l1.rangeEnd){
                    cout << "1\n";
                    return 0;
                }
                else{
                    cout << "0";
                    return 0;
                }
            }
        }
        else{
            long double intPx = l1.domainStart;
            if(intPx <= l2.domainEnd && intPx >= l2.domainStart){
                long double intPy = l2.getY(intPx);
                if(intPy <= l1.rangeEnd && intPy >= l1.rangeStart){
                    cout << "1\n";
                    cout << intPx << " " << intPy;
                    return 0;
                }
                else{
                    cout << "0";
                    return 0;
                }
            }
            else{
                cout << "0";
                return 0;
            }
        }
    }
    else if(l2.vertical == true){
        long double intPx = l2.domainStart;
        if(intPx <= l1.domainEnd && intPx >= l1.domainStart){
            long double intPy = l1.getY(intPx);
            if(intPy <= l2.rangeEnd && intPy >= l2.rangeStart){
                cout << "1\n";
                cout << intPx << " " << intPy;
                return 0;
            }
            else{
                cout << "0";
                return 0;
            }
        }
        else{
            cout << "0";
            return 0;
        }
    }
    else{
        doMoreMath(l1, l2);
    }
    return 0;
}