
#include <iostream>
#include <math.h>
#include <algorithm>

int main() {
	int house;
	std::cin >> house;
	int housePos[house];
	for(int i = 0; i < house; i++){
		std::cin >> housePos[i];
	}
	if(house == 1){
		std::cout << housePos[0] << std::endl;
		return 0;
	}
	int antennaPos = ceil(double(house) / 2);
	std::sort(housePos, housePos + house);
	std::cout << housePos[antennaPos - 1] << std::endl;
}
