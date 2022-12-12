// https://leetcode.com/problems/spiral-matrix/
// 54. Spiral Matrix

// Time Complexity = O(M*N)
// Space Complexity = O(1)
// Where M is the number of rows and N is the number of coloumns in the matrix.
// The space complexity is O(1) because the extra space (vector<int> ans) is the
// same which we our function is returning.

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
      // top row
      for (int j = left; j <= right; j++) {
        result.push_back(matrix[top][j]);
      }

      top++;                                 // Squeeze the top
      
      if (top <= bottom && left <= right) {  // We can use this or skip it.
        for (int i = top; i <= bottom; i++) {
          result.push_back(matrix[i][right]);
        }
        right--;
      }
      
      if (top <= bottom && left <= right) {  
        // In the above step we do top++ and we are already
        // inside the while loop. Condition will not be
        // checked again. Hence we need this if statement
        // we can also use only if(top<=bottom)
        // here we are checking (top<=bottom) because the value of top has been
        // modified and has to satisfy our while loop constraint. if my top
        // become more than bottom this means the row which we are trying to
        // enter in our ans vector has already been inserted.
        
        for (int j = right; j >= left; j--) {
          result.push_back(matrix[bottom][j]);
        }
        
        bottom--;
      }
      
      if (top <= bottom && left <= right) {
        // we can also use only if(left<=right)
        // here we are checking (left<=right) because the value of right has
        // been modified and has to satisfy our while loop constraint. if my left
        // become more than right this means the coloumn which we are trying to
        // enter in our ans vector has already been inserted.
        for (int i = bottom; i >= top; i--) {
          result.push_back(matrix[i][left]);
        }
        left++;
      }
    }
    return result;
  }
};

/*
Example 1:

Input:

[

[ 1, 2, 3 ],

[ 4, 5, 6 ],

[ 7, 8, 9 ]

] Output: [1,2,3,6,9,8,7,4,5] Example 2:

Input:

[

[1, 2, 3, 4],

[5, 6, 7, 8],

[9,10,11,12]

] Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
