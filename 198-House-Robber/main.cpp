// https://leetcode.com/problems/house-robber/
// 198. House Robber
// Time Complexity = O(N)
// Space Complexity = O(1)
// where N is the size of array nums.

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int rows = nums.size();
    int columns = 2;
    int value = 0;
    vector<vector<int>> dp(rows, vector<int>(columns, value));  // Initilizaing a 2d vector/Matrix with all 0
    dp.at(0).at(1) = nums.at(0);

    for (int i = 1; i < nums.size(); i++) {
      // Not Choose case
      dp.at(i).at(0) = max(dp.at(i - 1).at(0), dp.at(i - 1).at(1));

      // Choose case
      dp.at(i).at(1) = dp.at(i - 1).at(0) + nums.at(i);
    }
    return max(dp.at(nums.size() - 1).at(0),
               dp.at(nums.size() - 1).at(1));  // Maximum of the last row
  }
};

// Output

// nums: {2, 7, 9, 8, 1, 5}
// rows: 6
// columns: 2
// value: 0
// dp: {{0, 2}, {2, 7}, {7, 11}, {11, 15}, {15, 12}, {15, 20}}
