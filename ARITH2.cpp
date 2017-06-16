#include <bits/stdc++.h>
using namespace std;

long long int result(long long int operandA, long long int operandB, char operatr) {
	switch(operatr) {
		case '+' :
			return operandA + operandB;
		case '-' :
			return operandA - operandB;
		case '*' :
			return operandA * operandB;
		case '/':
			return operandA / operandB;
		default:;
	}
}

void solve() {
	long long int operandA, operandB, sum = 0;
	char operatr;
	cin >> operandA >> operatr >> operandB;
	operandA = sum = result(operandA, operandB, operatr);
	while(true) {
		cin >> operatr;
		if(operatr == '=')
			break;
		cin >> operandB; 
		operandA = sum = result(operandA, operandB, operatr);
	}
	cout << sum << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--)
		solve();
}
