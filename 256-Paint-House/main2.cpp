// Time Complexity = O(N)
// Space Complexity = O(1)
// Where N is the number of rows in matrix.

class Solution {
 public:
  int minCost(vector<vector<int>>& costs) {
    // vector <vector<int>> dp[costs.size()][3]; //Make a new matrix
    int rows = costs.size();
    int columns = 3;
    int value = 0;
    vector<vector<int>> dp(rows, vector<int>(columns, value));

    for (int j = 0; j < 3; j++) {
      dp[rows - 1][j] = costs[costs.size() - 1][j];
    }

    for (int i = costs.size() - 2; i >= 0; i--) {
      dp[i][0] = costs[i][0] + min(dp[i + 1][1], dp[i + 1][2]);
      dp[i][1] = costs[i][1] + min(dp[i + 1][0], dp[i + 1][2]);
      dp[i][2] = costs[i][2] + min(dp[i + 1][0], dp[i + 1][1]);
    }
    return min(dp[0][0], min(dp[0][1], dp[0][2]));
  }
};