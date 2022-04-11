#include <iostream>
using namespace std;

struct Line{
	int x1, y1, x2, y2;
};

Line line[3001];
int root[3001];
int count[3001];

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	int n = (x1*y2 + x2*y3 + x3*y1) - (y1*x2 + y2*x3 + y3*x1);
	if(n < 0) return -1;
	if(n > 0) return 1;
	else return 0;
}

int findRoot(int a){
	if(root[a] == a)return a;
	else return root[a] = findRoot(root[a]);
}

bool isCross(Line l1, Line l2){
	int d1 = ccw(l1.x1, l1.y1, l1.x2, l1.y2, l2.x1, l2.y1);
	int d2 = ccw(l1.x1, l1.y1, l1.x2, l1.y2, l2.x2, l2.y2);
	int d3 = ccw(l2.x1, l2.y1, l2.x2, l2.y2, l1.x1, l1.y1);
	int d4 = ccw(l2.x1, l2.y1, l2.x2, l2.y2, l1.x2, l1.y2);
	if(d1 * d2 <= 0 && d3 * d4 <= 0){
		if(l1.x1 > l2.x1 && l1.x1 > l2.x2 && l1.x2 > l2.x1 && l1.x2 > l2.x2){
			return false;
		}
		else if(l1.x1 < l2.x1 && l1.x1 < l2.x2 && l1.x2 < l2.x1 && l1.x2 < l2.x2){
			return false;
		}
		else if(l1.y1 > l2.y1 && l1.y1 > l2.y2 && l1.y2 > l2.y1 && l1.y2 > l2.y2){
			return false;
		}
		else if(l1.y1 < l2.y1 && l1.y1 < l2.y2 && l1.y2 < l2.y1 && l1.y2 < l2.y2){
			return false;
		}
		else return true;
	}
	return false;
}

void group(int i, int j){
	root[findRoot(i)] = findRoot(j);
}

int main() {
	cin.tie(NULL);
	int numLine;
	cin >> numLine;
	for(int i = 1; i <= numLine; i++){
		cin >> line[i].x1 >> line[i].y1 >> line[i].x2 >> line[i].y2;
		root[i] = i;
	}
	for(int i = 1; i <= numLine; i++){
		for(int j = 1; j <= i; j++){
			if(isCross(line[i], line[j])){
				group(i, j);
			}
		}
	}

	for(int i = 1; i <= numLine; i++){
		count[findRoot(i)]++;
	}
	int groupCount = 0;
	int groupMax = 0;
	for(int i = 1; i <= numLine; i++){
		if(count[i] > 0) groupCount++;
		if(count[i] > groupMax) groupMax = count[i];
	}
	cout << groupCount << "\n" << groupMax;
}
