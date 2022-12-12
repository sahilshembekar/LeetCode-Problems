// https://leetcode.com/problems/product-of-array-except-self/
// 238. Product of Array Except Self

// Time Complexity = O(N)
// Space Complexity = O(1)
// Here the space complexity is O(1) because the function return type is vector
// and we are taking the extra space(vector<int> temp) but returning the
// vector<int> temp.

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 0);

    if (nums.size() == 0) {
      return result;
    }

    int rp = 1;
    result[0] = rp;

    for (int i = 1; i < nums.size(); i++) {
      rp = rp * nums[i - 1];
      result[i] = rp;
    }

    // Important to rest the running product
    rp = 1;
    
    for (int i = nums.size() - 2; i >= 0; i--) {
      rp = rp * nums[i + 1];
      result[i] = result[i] * rp;
    }

    return result;
  }
};
/*
Example:

Input: [1,2,3,4] Output: [24,12,8,6] Note: Please solve it without division and
in O(n).

*/