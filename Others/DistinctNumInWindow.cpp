#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

/*
Problem -
--------

You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:
- If K > N, return empty array.

For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].
*/

vector<int> dNums(vector<int> &A, int B) {
    
    vector<int> distinctCnts;
    map<int, int> elements;
    int currCnt = 0;
    
    for (int i = 0; i < A.size(); ++i) {
        
        if (i - B >= 0) {
            distinctCnts.push_back(currCnt);
            
            elements[A[i - B]]--;
            if (elements[A[i - B]] == 0) {
                currCnt--;
            }
        }
        
        if (elements.find(A[i]) == elements.end()) {
            elements[A[i]] = 0;
        }
        
        if (elements[A[i]] == 0) {
            currCnt++;
        }
        elements[A[i]]++;
    }
    
    distinctCnts.push_back(currCnt);
    
    return distinctCnts;
}