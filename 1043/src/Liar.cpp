#include <iostream>

int x[51];
int parent[51];
bool truth[51];

int merge(int person1, int person2){
	if(person1 == person2){
		return 0;
	}
	if(parent[person1] != person1){
		return merge(parent[person1], person2);
	}
	else if(parent[person2] != person2){
		return merge(person1, parent[person2]);
	}
	if(person1 > person2){
		parent[person1] = person2;
		return 0;
	}
	else{
		parent[person2] = person1;
		return 0;
	}
}

int findRoot(int person){
	if(parent[person] != parent[parent[person]]){
		parent[person] = parent[parent[person]];
		findRoot(person);
		return 0;
	}
	else if(parent[person] == parent[parent[person]]){
		return 0;
	}
	return 0;
}

int main() {
	int count = 0;
	int population, numParty;
	std::cin >> population >> numParty;
	for(int i = 1; i <= population; ++i){
		parent[i] = i;
	}
	int truthNum;
	count = numParty;
	std::cin >> truthNum;
	int truePerson[truthNum];
	for(int i = 0; i < truthNum; i++){
		int id;
		std::cin >> id;
		truth[id] = true;
		truePerson[i] = id;
	}
	int party[50][50];
	for(int i = 0; i < 50; i++){
		for(int j = 0; j < 50; j++){
			party[i][j] = -1;
		}
	}
	int partySize[numParty];
	for(int i = 0; i < numParty; ++i){
		std::cin >> partySize[i];
		int partyMember[partySize[i]];
		int smallest = 55;
		for(int j = 0; j < partySize[i]; ++j){
			std::cin >> partyMember[j];
			party[i][j] = partyMember[j];
			if(partyMember[j] < smallest){
				smallest = partyMember[j];
			}
		}
		for(int j = 0; j < partySize[i]; ++j){
			merge(smallest, partyMember[j]);
		}
	}
	bool trueRoot[51];
	for(int i = 1; i <= population; i++){
		if(truth[i] == true){
			findRoot(i);
			trueRoot[parent[i]] = true;
		}
		else findRoot(i);
	}
	for(int i = 1; i <= population; i++){
		if(trueRoot[parent[i]]){
			truth[i] = true;
		}
	}
	for(int i = 0; i < numParty; i++){
		for(int j = 0; j < partySize[i]; j++){
			if(truth[party[i][j]]){
				count--;
				break;
			}
		}
	}
	std::cout << count << std::endl;
}
