//Time Complexity = O(N)
//Space Complexity = O(1)
//where N is the size of the vector nums.

class Solution {
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    void sortColors(vector<int>& nums) {
        int low =0;
        int high = nums.size()-1;
        int mid=0;
        while (mid <= high) {
            if (nums[mid]==0) {
                swap(nums,mid,low);
                low++;
                mid++;
            }
            else if (nums[mid] ==2) {
                swap(nums,mid,high);
                high--;
            }
            else { //mid is at 1
                mid++;
            }
                
        }
    }
};