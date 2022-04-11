#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int numVert;
	cin >> numVert;
	if(numVert < 3){
		cout << 0;
		return 0;
	}
	long double x[numVert];
	long double y[numVert];
	for(int i = 0; i < numVert; i++){
		cin >> x[i] >> y[i];
	}
	long double area = 0;
	for(int i = 0; i < numVert - 1; i++){
		area += (x[i]*y[i+1]) / 2 - (x[i+1]*y[i]) / 2;
	}
	area += x[numVert - 1]*y[0] / 2 - x[0]*y[numVert - 1] / 2;
	if(area < 0){
		area = -area;
	}
	cout << fixed << setprecision(1) << area;
}
