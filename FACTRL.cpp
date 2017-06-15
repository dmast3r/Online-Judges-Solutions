/*
Problem Name :- Factorial
Problem ID :- FACTRL
Problem Link :- http://www.spoj.com/problems/FCTRL2/
Date :- 16th June 2017
By :- Sourabh Khandelwal(http://www.spoj.com/users/themast3r)
*/

#include <bits/stdc++.h>
using namespace std;
// A utility function to find the largest power of 5 such that the resulting number when 5 is raised to it will be smaller or equal to the input number. 
long long int getMaxPower(long long int number) {
	long long int power = 0;
	while(number >= 5) { // is the number greater than or equal to 5? 
		++power; 
		number /= 5;
		// if yes then increment the power by 1 and divide the number by 5.
	}
	return power;
}

// solve a particular test case
void solve() {
	long long int count = 0, number, maxPower, previousDivides = 0;
	cin >> number;
	maxPower = getMaxPower(number); // get the max power.
	for(long long int i = maxPower; i > 0; --i) { 
		int currentDivisor = int(pow(5, i)), currentDivides = number / currentDivisor;
		count += (currentDivides - previousDivides) * i;
		previousDivides = currentDivides; 
	}

	cout << count << endl;
}
 int main() {
 	int test;
 	cin >> test;
 	while(test--)
 		solve();
 }
