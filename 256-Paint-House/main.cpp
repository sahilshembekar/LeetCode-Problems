// https://leetcode.com/problems/paint-house/

// 256. Paint House

// Time Complexity =O(2^(N))
// Space Complexity = O(1)
// Where N is the number of rows in matrix.

class Solution {
  int helper(vector<vector<int>>& costs, int row, int CurrentColour, int minCost) {
    // base case
    if (row == costs.size()) {
      return minCost;
    }

    // logic
    if (CurrentColour == 0) {
      return min(helper(costs, row + 1, 1, minCost + costs.at(row).at(0)),
                 helper(costs, row + 1, 2, minCost + costs.at(row).at(0)));
    }
    if (CurrentColour == 1) {
      return min(helper(costs, row + 1, 0, minCost + costs.at(row).at(1)),
                 helper(costs, row + 1, 2, minCost + costs.at(row).at(1)));
    }
    if (CurrentColour == 2) {
      return min(helper(costs, row + 1, 0, minCost + costs.at(row).at(2)),
                 helper(costs, row + 1, 1, minCost + costs.at(row).at(2)));
    }
    return 1234;  // Random number
  }

 public:
  int minCost(vector<vector<int>>& costs) {
    if (costs.size() == 0) {
      return 0;
    }

    int Case1 = helper(costs, 0, 0, 0);
    int Case2 = helper(costs, 0, 1, 0);
    int Case3 = helper(costs, 0, 2, 0);
    return min(Case1, min(Case2, Case3));
  }
};
