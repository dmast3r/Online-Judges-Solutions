#include <bits/stdc++.h>
using namespace std;

// A utility function that recursively computes the answer.
int findAnswer(int start, int end, string text, map<pair<int, int>, int> &myMap) {

	// if the length of text remaining to be examined is less than 3 then 
	if(end - start <= 1) {
		
		// if starting and ending characters match then no need for further addition.
		if(text[start] == text[end])
			return 0;
		return 1; // else add one more character to make it palindrome.
	}

	// if there exists an answer for start to end the return the answer.
	pair<int, int> checkPair = make_pair(start, end);
	if(myMap.count(checkPair) != 0)
		return myMap[checkPair];

	// else recursively find and return the answer.
	// if start and end chars match-
	if(text[start] == text[end])
		return myMap[checkPair] = findAnswer(start + 1, end - 1, text, myMap);
	return myMap[checkPair] = 1 + min(findAnswer(start + 1, end, text, myMap), findAnswer(start, end - 1, text, myMap));
}

// solves the question for each test case
void solve() {
	
	string text;
	cin >> text;
	map<pair<int, int>, int> myMap;

	cout << findAnswer(0, text.length() - 1, text, myMap) << endl;
}

int main(int argc, char const *argv[]) {
	
	int test;
	cin >> test;

	while(test--)
		solve();
	return 0;
}