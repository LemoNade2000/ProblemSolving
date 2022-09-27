#include <iostream>

int main(){
	int caseNum;
	std::cin >> caseNum;
	for(int i = 0; i < caseNum; i++){
		int step = 0;
		int start, end;
		long long int possibleTravel = 0;
		std::cin >> start >> end;
		long long int distance = end - start;
		while(possibleTravel < distance){
			possibleTravel += step/2 + 1;
			step++;
		}
		std::cout << step << std::endl;
	}
}
