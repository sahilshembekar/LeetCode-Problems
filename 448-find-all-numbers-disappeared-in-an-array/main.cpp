
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// 448. Find All Numbers Disappeared in an Array

//Time Complexity = O(N)
//Space Complexity = O(1)
//Where N is the Number of elements int the vector nums.
//Here the space complexity is O(1) because we are taking the extra space (vector<int> ans) and returning the same through the function.

// Can use hashset -> same time but O(N) space

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector <int> result;
        int n = nums.size();
        for (int i =0; i< n; i++) {
            int idx = abs(nums[i])-1; //abs of val and then -1
            if (nums[idx] > 0) {
                nums[idx] *= -1;
            }
        }
        
        for (int i =0; i <n; i++) {
            if (nums[i] < 0) {
                nums[i] *=-1;
            }
            else {
                result.push_back(i+1);
            }
        }
        return result;
    }
};
  
