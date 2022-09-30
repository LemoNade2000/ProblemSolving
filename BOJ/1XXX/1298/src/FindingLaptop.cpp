#include <iostream>
#include <cstring>

using namespace std;

bool graph[101][101];

bool bpm(int numStudent, int student, bool seen[], int match[]){
	for(int i = 1; i <= numStudent; i++){
		if(graph[student][i] && !seen[i]){
			seen[i] = true;
			if(match[i] < 0 || bpm(numStudent, match[i], seen, match)){
				match[i] = student;
				return true;
			}
		}
	}
	return false;
}

int maxMatch(int numStudent){
	int result = 0;
	int match[numStudent + 1];
	memset(match, -1, sizeof(match));
	for(int i = 1; i <= numStudent; i++){
		bool seen[numStudent + 1];
		memset(seen, false, sizeof(seen));
		if(bpm(numStudent, i, seen, match)){
			result++;
		}
	}
	return result;
}

int main() {
	int numStudent, numPred;
	cin >> numStudent >> numPred;
	memset(graph, 0, sizeof(graph));
	for(int i = 0; i < numPred; i++){
		int student, laptop;
		cin >> student >> laptop;
		graph[student][laptop] = 1;
	}
	cout << maxMatch(numStudent);
}
