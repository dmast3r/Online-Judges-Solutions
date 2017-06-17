#include <bits/stdc++.h>
using namespace std;

bool isPriorityGreater(char previous, char current) {
	switch(current) {
		case '^':
			return true;
		case '/':
			if(previous == '^')
				return false;
			return true;
		case '*':
			if(previous == '^' or previous == '/')
				return false;
			return true;
		case '-':
			if(previous == '+')
				return true;
			return false;
		case '+':
			return false;
	}
}

void emptyStack(stack<char> &charStack, string &target) {
	while(charStack.empty() == false and charStack.top() != '(') { 
		target += charStack.top();
		charStack.pop();
	}
	if(charStack.empty() == false)
		charStack.pop();
	return;
}

void parseCharacter(char character, stack<char> &charStack, string &target) {
	if(isspace(character))
		return;
	else if(isalpha(character))
		target += character;
	else if(character == '(')
		charStack.push(character);
	else if(character == ')')
		emptyStack(charStack, target);
	else {
		if(charStack.top() == '(')
			charStack.push(character);
		else if((charStack.empty() == false and isPriorityGreater(charStack.top(), character)) or charStack.empty() == true)
			target += character;
		else {
			target += charStack.top();
			charStack.pop();
			charStack.push(character);
		}
	}
}

void solve() {
	string source, target;
	stack<char> charStack;
	cin >> source;
	for(auto i : source)
		parseCharacter(i, charStack, target);
	if(charStack.empty() == false)
		emptyStack(charStack, target);
	cout << target << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--)
		solve();
}
