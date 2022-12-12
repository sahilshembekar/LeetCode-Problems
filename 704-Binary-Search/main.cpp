// https://leetcode.com/problems/binary-search/

// 704. Binary Search

// O(log n)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //if (nums.size())
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while (low <= high) {
            mid = low + (high-low)/2;
                if (nums[mid] == target) {
                    return mid;
                }
            else if (nums[mid] < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }  
        }
        return -1;
    }
};