class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==0) {
            return -1;
        }
        int low =0;
        int high, mid;
        high = nums.size()-1;
        while (low<=high) {
            mid = low + (high-low)/2;
            
            if (nums[mid]==target) {
                return mid;
            }
            else if (nums[low]<=nums[mid]) {
                // left side is sorted
                if (nums[low]<= target && target< nums[mid]) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            else {
                // right side is sorted
                if (nums[mid] < target && target <=nums[high]) {
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};