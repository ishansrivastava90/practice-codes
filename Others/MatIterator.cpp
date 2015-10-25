#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

class MatrixIterator {

	vector< vector<int> > mat;
	int row_ind;
	int col_ind;

	int find_next_row() {
		for (int i = row_ind+1; i < mat.size(); ++i) {
			if (mat[i].size() > 0) {
				return i;
			}
		}
		return mat.size();
	}

	public:
		MatrixIterator(vector<vector<int> > &m) { //: mat(m) {
			mat = m;
			row_ind = -1;
			row_ind = find_next_row();
			col_ind = 0;
		}

		bool hasNext() {
			if (row_ind < mat.size()) {
				if (col_ind < mat[row_ind].size()) {
					return true;
				}
				row_ind = find_next_row();
				if (row_ind < mat.size()) {
					col_ind = 0;
					return true;
				}
			}
			return false;

		}

		int next() {
			if (hasNext()) {
				int ret =  mat[row_ind][col_ind];
				col_ind++;
				if (col_ind == mat[row_ind].size()) {
					row_ind = find_next_row();
					col_ind = row_ind < mat.size() ? 0 : -1;
				} 

				return ret;
			}
			//throw new exception("Wrong");
		}

		void remove() {
			if (hasNext()) {
				mat[row_ind].erase(mat[row_ind].begin() + col_ind);
				if (mat[row_ind].size() == 0) {
					row_ind = find_next_row();
					col_ind = 0;
				} 
			} 
		}
};

int main() {
	vector<vector <int> > v1({{}, {1,2,3},{},{4},{5,6},{}});
	MatrixIterator it(v1);
	
	cout<< it.next() <<endl;
	it.remove();
	it.remove();
	it.remove();

	while(it.hasNext()) {
		cout << it.next() << endl;
	}
	return 0;
}