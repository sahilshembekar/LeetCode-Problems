class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int skip = 0;
    int take = nums.at(0);

    for (int i = 1; i < nums.size(); i++) {
      int PreviousSkip = skip;
      // Not Choose case
      skip = max(skip, take);

      // Choose case
      take = PreviousSkip + nums.at(i);
    }
    return max(skip, take);  // Maximum of the last row
  }
};

// Output
// nums: {2, 7, 9, 8, 1, 5}
// skip: 15
// take: 20