               
                
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// 153. Find Minimum in Rotated Sorted Array

//Time Complexity = O(log n)
//Space Complexity = O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
    if (nums.empty()) {
        return -1; 
    }
        //Rotated sorted array has one side always sorted
        int low =0;
        int high = nums.size()-1;
        ///CHECK  just < once
        
        if (nums[low]<=nums[high]) { // that is we have been given a sorted array pivot at the start index
            return nums[low];
        }
        while(low<=high) {
            if (nums[low]<=nums[high]) { // that is we have a sorted array situation after going through binary search
                // We don't want to go to the unsorted side and choose the wrong value
                
                return nums[low];
            }   
            int mid = low + (high-low)/2;
            
            if ((mid==0 || nums[mid-1] > nums[mid]) && (mid==nums.size()-1 || nums[mid] < nums[mid+1])) { 
                //If mid is less than both its neighboiurs we have the min of the Rotated sorted array
                // Edge cases compared with their only neighbour
                return nums[mid];
            }
            else if (nums[low]<=nums[mid]) { // will check if the left side is sorted 
                //if yes move to the unsorted side that is right
                low = mid+1;
                }
            else { // else right is sorted and move to the left 
                high = mid-1;
            }
                
        }
        return -1;
        
    }
};
