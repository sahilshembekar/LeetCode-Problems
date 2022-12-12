//Time Complexity = O(NLogN)
//Space Complexity = O(1)
//where N is the elements in the vector nums. 
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int slow=0,fast=0,count=0;
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        while(slow<n && fast<n) {
    
            if (slow==fast || nums[fast]-nums[slow]<k) {
                fast++;
            }
            else if (nums[fast]-nums[slow]>k) {
                slow++;
            }
            else {
                count++;
                slow++;
                fast++;
            //check for uniqeness
                while(fast<n && nums[fast]==nums[fast-1]) {
                    fast++;
                }
            }
        }
        return count;
    }
};