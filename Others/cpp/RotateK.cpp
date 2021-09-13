# include <stdio.h>
# include <iostream>
# include <limits.h>
# include <vector>

using namespace std;

int gcd (int n1 , int n2) {
	if (n1 % n2 == 0) return n2;
	return gcd(n2, n1 % n2);
}

void rotateK(vector<int>& seq, int K) {
	if (seq.size() == 0 || K == 0) {
		return;
	}
	int N = seq.size();

	for (int i = 0; i < gcd(N, K); ++i) {

		int t_ind = i;
		int t = seq[i];
		while(1) {
			int t1 = seq[t_ind + K];
			seq[t_ind + K] = t;
			t = t1;


			if (t_ind == i) break;

			t_ind = (t_ind +K) % N;
		}
	}
}

int main () {

	int N, K;
	cin >> N >> K;
	vector<int> seq(N);
	for (int i = 0; i < N; ++i) {
		cin >> seq[i];
	}
	rotateK(seq, K);
	
	return 0;
}