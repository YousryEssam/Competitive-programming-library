#include <bits/stdc++.h>
using namespace std;

//1-based matrix
//Append extra top row and col with zero
void Prefix_Sum_2D(vector<vector<int>>&A){
    // Accumulate each row
    for (int i = 1; i < (int) A.size(); i++){
      for (int j = 1; j < (int) A[0].size(); j++) {
            A[i][j] += A[i][j-1];
        }
    }
    // Accumulate each col
    for (int j = 1; j < (int) A[0].size(); j++) {
        for (int i = 1; i < (int) A.size(); i++){
          A[i][j] += A[i-1][j];
        }
    }
}
int sum_range_2D(int i, int j, int k, int l, vector<vector<int>> & S) {
    return S[k][l] - S[k][j-1] - S[i-1][l] + S[i-1][j-1];
}