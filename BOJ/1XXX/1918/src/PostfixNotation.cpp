#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char oper){
	if(oper == '/' || oper == '*'){
		return 1;
	}
	else if(oper == '+' || oper == '-'){
		return 2;
	}
	else return 3;
}

int main() {
	string infix;
	cin >> infix;
	string result;
	stack<char> temp;
	for(int i = 0; i < infix.length(); i++){
		char c = infix[i];
		if(c >= 'A' && c <= 'Z'){
			result += c;
		}
		else if(c == '('){
			temp.push('(');
		}
		else if(c == ')'){
			while(temp.top() != '('){
				result += temp.top();
				temp.pop();
			}
			temp.pop();
		}
		else if(c == '+' || c == '-' || c == '/' || c == '*'){
			while(!temp.empty() && priority(c) >= priority(temp.top())){
				result += temp.top();
				temp.pop();
			}
			temp.push(c);
		}
	}
	while(!temp.empty()){
		result += temp.top();
		temp.pop();
	}
	cout << result;

}
