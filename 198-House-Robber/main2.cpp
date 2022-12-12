//Time Complexity = O(2^N)
//Space Complexity = O(N)
//where N is the size of array nums.
//Here time limit will exceed.
class Solution {
    public:
        int helper(vector<int> nums, int index, int cash) {
            //base case
            if(index>=nums.size())
                return cash;

            //logic
            /*
            1 is to skip that house and go to next
            2 is to use that house and hence skip the next and got index + 2
            */
            return max(helper(nums,index+1,cash), helper(nums,index+2, cash+nums[index]));
        }
        
        int rob(vector<int>& nums) {
        
        return helper(nums, 0,0);
        
        }

};

//Time Limit Exceeded //Output Correct //Brute force approach