#include <bits/stdc++.h>
using namespace std;

// allocate a matirx of order equal to the max possible length of the string.
int matrix[6100][6100];

// process the matrix and find the answer. length is the length of input string text
int findAnswer(int length, string text) {

	// first initialise the entire matirx(currently in our concern) to zero.
	for(int i = 0; i < length; ++i)
		for(int j = 0; j < length; ++j)
			matrix[i][j] = 0;

	// now do computation for each cell. The semantic for computation is obviously same as Top-Down approach. 
	// Only syntax is different
	for(int len = 1; len <= length; ++len) {
		for (int i = 0, j = len - 1; j < length; ++i, ++j){
			
			// if the texts at the end matches there is no need for further addition, simply copy the answer for the next end chars
			if(text[i] == text[j])
				matrix[i][j] = matrix[i+1][j-1];
			else 
				matrix[i][j] = 1 + min(matrix[i+1][j], matrix[i][j-1]); // else drop one char from each end, retain the one at  
				// the other. Compute the values for two patterns thus obtained. And store a value 1 greater than minimum of the 
				// two.
		}	
	}

	// the value for the last chars in text.
	return matrix[0][length-1];	
}

// solves each test case
void solve() {
	string text;
	cin >> text;

	cout << findAnswer(text.length(), text) << endl;
}

int main(int argc, char const *argv[]) {
	int test;
	cin >> test;

	while(test--)
		solve();
	return 0;
}