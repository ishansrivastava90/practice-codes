# include <stdio.h>
# include <iostream>
# include <limits.h>
# include <vector>
using namespace std;

int longestAPSeq(const vector<int>& seq) {
	if (seq.size() == 0) {
		return 0;
	}

	int s_len = 1;
	int max_s_len = INT_MIN;
	int prev_diff;
	for (int i = 1; i < seq.size(); ++i) {
		cout << s_len << endl;
		if (i == 1) {
			prev_diff = seq[i] - seq[i-1];
			s_len++;
			continue;
		}

		if (prev_diff == (seq[i] - seq[i-1])) {
			s_len++;

		} else {
			prev_diff = seq[i] - seq[i-1];

			if (s_len > max_s_len) {
				max_s_len = s_len;
				s_len = 2;
			}
		}
	}
	return max_s_len;
}

int main () {

	int N;
	cin >> N;
	vector<int> seq(N);
	for (int i = 0; i < N; ++i) {
		cin >> seq[i];
	}
	cout << longestAPSeq(seq);
	return 0;
}