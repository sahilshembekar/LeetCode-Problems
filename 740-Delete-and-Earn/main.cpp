// https://leetcode.com/problems/delete-and-earn/

// 740. Delete and Earn

// Time Complexity = O(Maximum_Element+1) or O(N)
// Space Complexity = O(Maximum_Element+1)
// Where N is the size of the vector nums.

class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }

    int maxi = INT_MIN;  // -2147483648
    for (auto num : nums) {
      maxi = max(maxi, num);
    }

    vector<int> vec(maxi + 1, 0);  // if size is 15 then we need total elements
                                   // as 16 (maxi+1) i.e. 0 to 15
    for (auto num : nums) {
      vec.at(num) = vec.at(num) + num;
    }

    int skip = 0, take = vec.at(0), PreviousSkip;
    for (int i = 0; i < vec.size(); i++) {  // it will go from 0 till 15 as vec.size () is 16

      PreviousSkip = skip;
      // Not choose
      skip = max(skip, take);

      // Choose
      take = PreviousSkip + vec.at(i);
    }
    return max(skip, take);
  }
};

// Output
// nums: {3, 4, 2}
// maxi: 4
// vec: {0, 0, 2, 3, 4}
// skip: 3
// take: 6
// PreviousSkip: 2
---------------------------

                          // Time Complexity = Exponential
