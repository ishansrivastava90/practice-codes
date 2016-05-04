# include <iostream>
# include <stdio.h>
# include <vector>
# include <climits>


using namespace std;

int maxGap (const vector<int> &num, int N) {
	if (N < 2) {
		return 0;
	}

	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0; i < N; ++i) {
		max = num[i] > max ? num[i] : max;
		min = num[i] < min ? num[i] : min;
	}
	int offset = min < 0 ? min * -1 : 0;

	int b_size = (max + min ) >> 2;
	vector< pair<int, int> > buckets(N+1, make_pair(INT_MAX, INT_MIN));

	for (int i = 0; i < N; ++i) {
		int b_ind = (num[i] + offset)/b_size;
		max = num[i] > buckets[b_ind].second ? num[i] : buckets[b_ind].second;
		min = num[i] < buckets[b_ind].first ? num[i] : buckets[b_ind].first;

		buckets[b_ind] = make_pair(min, max);

	}

	int max_gap = buckets[0].second - buckets[0].first;
	// Assert that it can't be > b_size
	int prev_max = buckets[0].second;
	for (int b = 1; b < buckets.size(); ++b) {
		if (buckets[b].first == INT_MAX || buckets[b].second == INT_MIN) {
			continue;
		}
		max_gap  = buckets[b].first - prev_max > max_gap 
			? buckets[b].first - prev_max 
			: max_gap;
		max_gap = buckets[b].second - buckets[b].first > max_gap 
			? buckets[b].second - buckets[b].first
			: max_gap;
		prev_max = buckets[b].second;
	}

	return max_gap;

}
int main() {

	int N;
	cin >> N;

	vector <int> num(N);
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}

	cout << maxGap(num, N);
}