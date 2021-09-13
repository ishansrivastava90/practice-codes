# include <iostream>
# include <stdio.h>
# include <limits.h>

using namespace std;

int addOne (int num) {
	
	if ((num & 1) == 0) {
		return (num | 1);
	}

	int n = num;
	int bit_factor = INT_MAX;
	int t = 1;
	while (n & 1) {
		n = n >> 1;
		bit_factor = bit_factor << 1;
		t = t << 1;
	}
	return ((num & bit_factor) | t);	
}
int main() {
	cout << "Enter a number";
	int num;
	cin >> num;

	cout << addOne(num);
	return 0;
}