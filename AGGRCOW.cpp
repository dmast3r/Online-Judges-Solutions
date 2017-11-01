// Read https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/ before reading this code snippet

/* The intuition for a solution to this problem is following: 
1. Select a number x such that the difference between two cows is atleast x. What we need to do here is to find a set of c
coordinates, where c being the number of cows such that the distance between any two cows is greater than or equal to x.
2. We apply greedy approach and place the first cow on the smallest coordinate(we first sort the array and then place the first
cow on arr[0]). Now we do iterate over the array from the second element to the last one(arr[1....N - 1]) and maintain a variable
(here it is last_pos) that records the coordinate of the last placed cow. Now for every index we check if the distance between
last_pos and the coordinate represented by current index. If this distance is greater than or equal to x then place a new cow
here and update last_pos to current index. For every placement of a cow increment the number of cows that has been placed so far
and return true if cows placed so far equals cows that are actually needed to be placed.
3. If all cows can not be placed, i.e. cows placed so far never equals cows that are actually needed to be placed then we finally
reach the end of iteration and our predicate function returns false. This means that this distance x is too high to place all 
cows.
4. Now to apply Binary Search we need to determine what action to take when the predicate returns false and true. If predicate 
returns false then obviously all values greater than x must be discarded, so we set hi to x - 1 but if it returns true we need
to look for a number that is greater than or equal to x and still makes predicate return true when passed to it, so we set lo
to x in this case. Here x is ofcourse equal to mid value of lo and high. Here we have used lo-high+1 instead of just lo-high
because in the former case our mid in search converge to lo, this leads to an infinite loop. 
5. This way we can search for largest x that when passed to predicate makes it return true, ofcourse at this value lo = hi = 
value. So, we simply print lo.
*/

#include <bits/stdc++.h>
using namespace std;

// This is the predicate function. x is the least distance between two cows, c is the number of cows to be placed and 
// dist is sorted array of coordinates.
bool pred(int x, int cows, int dist[], int elems) {
	int c = 1, last_pos = 0;
	for(int i = 1; i < elems; ++i) {
		if(dist[i] - dist[last_pos] >= x) {
			if(++c == cows) 
				return true;
			last_pos = i;
		}
	}
	return false;
}

void solve() {
	int n, cows, lo = 1, hi, mid;
	cin >> n >> cows;
	int dist[n];

	for(auto &i : dist)
		cin >> i;
	sort(dist, dist + n);
	hi = dist[n-1] - dist[0];

	while(lo < hi) {
		mid = lo + (hi - lo + 1) / 2;
		if(pred(mid, cows, dist, n)) 
			lo = mid;
		else 
			hi = mid - 1;
	}

	cout << lo << endl;
}

int main(int argc, char const *argv[]) {
	int test;
	cin >> test;

	while(test--)
		solve();
	return 0;
}
