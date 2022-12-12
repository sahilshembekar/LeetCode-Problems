// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// 34. Find First and Last Position of Element in Sorted Array

//Time Complexity = O(log n)
//Space Complexity = O(1)

class Solution {
public:
    int binarySearchLeft(vector<int>& nums, int target) {
        int low {0};
        int high = nums.size()-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if (nums[mid]== target) {
                if (mid ==0 || nums[mid] >nums[mid-1]) //Only then this is the first instance of the target. Also check with edge case, because first instance can be at 0 
                    //and it will throw an index out of bound error otherwise while comparing with previous element
                    return mid;
                else { // else move left
                    high = mid-1;
                }
            }
            else if (nums[mid]>target) {
                high = mid-1;
            }
            else {
                low= mid+1;
            }
            
        }
        return -1; // If not found
    }
    
    int binarySearchRight(vector<int>& nums, int target) {
        int low {0};
        int high = nums.size()-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if (nums[mid]== target) {
                if (mid ==(nums.size()-1) || nums[mid] < nums[mid+1]) //Only then this is the last instance of the target. Also check with edge case, because first instance can be at n-1 
                    //and it will throw an index out of bound error otherwise while comparing with next element
                    return mid;
                else { // else move right
                    low = mid+1;
                }
            }
            else if (nums[mid]>target) {
                high = mid-1;
            }
            else {
                low= mid+1;
            }
            
        }
        return -1; // If not found
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> result;
        if (nums.empty()) { //If the vector is empty return -1,-1
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        if (nums.at(0) >target || nums.at(nums.size()-1)< target) { //check edge condition if teh target isnot within the range of vector return -1,-1
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        
        result.push_back(binarySearchLeft(nums, target));
        result.push_back(binarySearchRight(nums, target));
        return result;
    }
};