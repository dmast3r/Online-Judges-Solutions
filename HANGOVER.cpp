#include <bits/stdc++.h>
using namespace std;

long long int findAnswer(float overHang) {

	long long int count = 0;
	float hang = 0.0f;

	for(int i = 2; hang < overHang; ++i, ++count)
		hang += (float)1/i;

	return count;
}

bool solve() {
	
	float overHang;
	cin >> overHang;

	if(overHang == 0.00f)
		return false;

	cout << findAnswer(overHang) << " card(s)" << endl;
	return true;
}

int main(int argc, char const *argv[]){

	while(solve()); 
	return 0;
}