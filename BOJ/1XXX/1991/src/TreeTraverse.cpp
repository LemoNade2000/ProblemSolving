#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int leftNode[26];
int rightNode[26];
queue<char> result;

int preorder(int node){
	result.push(node);
	if(leftNode[node] != -1){
		preorder(leftNode[node]);
	}
	if(rightNode[node] != -1){
		preorder(rightNode[node]);
	}
	return 0;
}

int inorder(int node){
	if(leftNode[node] != -1){
		inorder(leftNode[node]);
	}
	result.push(node);
	if(rightNode[node] != -1){
		inorder(rightNode[node]);
	}
	return 0;
}

int postorder(int node){
	if(leftNode[node] != -1){
		postorder(leftNode[node]);
	}
	if(rightNode[node] != -1){
		postorder(rightNode[node]);
	}
	result.push(node);
	return 0;
}

int main() {
	int nodeNum;
	cin >> nodeNum;
	for(int i = 0; i < nodeNum; i++){
		char nodeC, leftC, rightC;
		cin >> nodeC >> leftC >> rightC;
		int node, left, right;
		node = nodeC - 'A';
		left = leftC - 'A';
		right = rightC - 'A';
		leftNode[node] = -1;
		rightNode[node] = -1;
		if(leftC != '.'){
			leftNode[node] = left;
		}
		if(rightC != '.'){
			rightNode[node] = right;
		}
	}
	preorder(0);
	for(int i = 0; i < nodeNum; i++){
		int node;
		node = result.front();
		char nodeC;
		nodeC = 'A' + node;
		cout << nodeC;
		result.pop();
	}
	cout << "\n";
	inorder(0);
	for(int i = 0; i < nodeNum; i++){
		int node;
		node = result.front();
		char nodeC;
		nodeC = 'A' + node;
		cout << nodeC;
		result.pop();
	}
	cout << "\n";
	postorder(0);
	for(int i = 0; i < nodeNum; i++){
		int node;
		node = result.front();
		char nodeC;
		nodeC = 'A' + node;
		cout << nodeC;
		result.pop();
	}
}
