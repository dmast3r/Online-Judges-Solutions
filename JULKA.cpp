#include <bits/stdc++.h>
#define toNum(c) (int(c - '0'))
#define toChar(i) (char(i + '0'))
using namespace std;

string divide(string source) {
	int length = source.length(), last = 0;
	string target;
	for(int i = 0; i < length; ++i) {
		int num = last * 10 + toNum(source[i]);
		target += toChar(num / 2);
		last = num % 2;
	}
	return target;
}

void substract(string &minuend, string subtrahend) {
	int slength = subtrahend.length(), mlength = minuend.length(), carry = 0, index = mlength - 1;
	for(int i = slength - 1; i >= 0; --i) {
		int a = toNum(minuend[index]), b = toNum(subtrahend[i]), diff;
		diff = (a - b - carry >= 0) ? a - b - carry : a - b - carry + 10;
		carry = (a - b - carry >= 0) ? 0 : 1; 
		minuend[index--] = toChar(diff);
	}
	while(carry != 0) {
		int a = toNum(minuend[index]), diff;
		diff = (a - carry >= 0) ? a - carry : a - carry + 10;
		carry = (a - carry >= 0) ? 0 : 1;
		minuend[index--] = toChar(diff);
	}
}

void addition(string &number, string add) {
	int alength = add.length(), nlength = number.length(), carry = 0, index = nlength - 1;
	for(int i = alength - 1; i >= 0; --i) {
		int a = toNum(number[index]), b = toNum(add[i]), sum;
		sum = (a + b + carry) % 10;
		carry = (a + b + carry) / 10;
		number[index--] = toChar(sum);
	}
	while(carry != 0) {
		int a = toNum(number[index]), sum;
		sum = (a+carry) % 10;
		carry = (a+carry) / 10;
		number[index--] = toChar(sum);
	}
}

void printResult(string result) {
	int length = result.length(), index = 0;
	while(result[index] == '0')
		index++;
	while(index != length)
		cout << result[index++];
	cout << endl;
}

void solve() {
	string sum, greater, natalia, klaudia;
	cin >> sum >> greater;
	substract(sum, greater);
	natalia = klaudia = divide(sum);
	addition(klaudia, greater);
	printResult(klaudia);
	printResult(natalia);
}

int main() {
	int test = 10;
	while(test--)
		solve();
}
