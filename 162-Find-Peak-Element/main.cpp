                                                                
//https://leetcode.com/problems/find-peak-element/

//162. Find Peak Element

//Time Complexity = O(log n)
//Space Complexity = O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        
        int low {0};
        int high = nums.size()-1;
        while (low<=high) {
            int mid = low + (high-low)/2;
            if ((mid==0 || nums[mid] > nums[mid-1]) && (mid==nums.size()-1 || nums[mid] > nums[mid+1])) {
                //Peak element condition where mid is greater than both its neighbours
                // Also edge case where if the peak occurs at the 0 or n-1 then there is only 1 element to compare on the right for 0 and left for n-1
                return mid;
            }
            else if (mid>0 && nums[mid]<nums[mid-1]) { //Check if element on left is greater, if yes, move to the left side that is greater
                // check if mid has not reached 0th position as we can't go further left
                high = mid-1;
            }
            else { // element on right is greater and move to the right side that is greater
                low = mid+1;
            }
        }
        return -1;
    }
};
                