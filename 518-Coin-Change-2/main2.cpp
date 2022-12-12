// Time Complexity = O(M*N)
// Space Complexity = O(M*N)
// Where M is the size of the vector coins and N is the amount.

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    int rows = coins.size() + 1;
    int columns = amount + 1;
    int value = 0;
    vector<vector<int>> dp(rows, vector<int>(columns, value));  // Initilizaing a 2d vector/Matrix with all 0
    // Can also use a 2D array

    for (int i = 1; i < rows; i++) {
      dp.at(i).at(0) = 1;
    }
    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < columns; j++) {
        if (j < coins.at(i - 1)) {  // Till j i.e. amount is less than
                                    // denomination of the coin
          dp.at(i).at(j) = dp.at(i - 1).at(j);
        } 
        else {  // No of ways fromabove and from the denomination times steps
                  // back
          dp.at(i).at(j) = dp.at(i - 1).at(j) + dp.at(i).at(j - coins.at(i - 1));
        }
      }
    }
    return dp.at(rows - 1).at(columns - 1);
  }
};