/*
Problem Name :- Small factorials
Problem ID :- FCTRL2
Link :- http://www.spoj.com/problems/FCTRL2/
Date :- 16th June 2017
By : Sourabh Khandelwal(http://www.spoj.com/users/themast3r)
*/

#include <bits/stdc++.h>
using namespace std;

void multiply(int answer[], int number, int &length) {
	int carry = 0;
	for(int i = 1; i <= length; ++i) {
		int product = answer[500-i] * number + carry;
		answer[500-i] = product % 10;
		carry = product / 10;
	}
	while(carry != 0) {
		answer[500 - ++length] = carry % 10;
		carry /= 10; 
	}
}

void solve() {
	int number, length = 1, answer[500];
	cin >> number;
	answer[499] = 1;
	for(int i = 1; i <= number; ++i)
		multiply(answer, i, length);
	for(int i = length; i > 0; --i)
		cout << answer[500-i];
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		solve();
		cout << endl;
	}
}
