// https://leetcode.com/problems/diagonal-traverse/
// 498. Diagonal Traverse

// Time Complexity = O(M*N)
// Space Complexity = O(1)
// Here the Time complexity is O(1) because the extra space (vector<int> ans)
// which we are using is the same which we are returning

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> result(m * n, 0);

    if (mat.size() == 0) {
      return result;
    }
    int i = 0;
    int r = 0;
    int c = 0;
    int dir = 1;

    while (i < m * n) {
      result[i] = mat[r][c];
      i++;
      if (dir == 1) {      // when traversing bottom to top diagonally.
        if (c == n - 1) {  // The order of if-else here matters a lot.
          // when traversing bottom to top diagonally, at one point we reach the
          // row=0, then we increment our coloumn by 1, at one time when coloumn
          // becomes coloumn+1, we get out of bound. To manage this we have this
          // order of if else.
          r++;
          dir = 0;
        } 
        else if (r == 0) {
          c++;
          dir = 0;

        } 
        else {
          r--;
          c++;
        }
      } 
      
      else {
        if (r == m - 1) {  // when traversing top to bottom diagonally, at one point
                      // we reach the coloumn=0, then we increment our row by 1,
                      // at one time when row becomes row+1, we get out of bound.
                      // To manage this we have this order of if else.

          c++;
          dir = 1;
        } 
        else if (c == 0) {
          r++;
          dir = 1;
        } 
        else {
          r++;
          c--;
        }
      }
    }
    return result;
  }
};

/*
Example:

Input:

[

[ 1, 2, 3 ],

[ 4, 5, 6 ],

[ 7, 8, 9 ]

]

Output: [1,2,4,7,5,3,6,8,9]
*/