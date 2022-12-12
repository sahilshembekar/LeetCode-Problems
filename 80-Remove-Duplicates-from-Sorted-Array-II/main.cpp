//Time Complexity = O(N)
//Space Complexity = O(1)
//where N is the number of elements in vector nums.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
       }
        //slow pointer for placement fast of traversal and choose elements
        int count = 1;
        int j = 1; // 0 also OK start but start i also with 0
        for (int i = 1; i<nums.size(); i++) { //i fast pointer j slow pointer
            if (nums[i] == nums[i-1]) {
                count ++;
            }
            else {
                count = 1; //Reset the count for new element
            }
            
            if (count <=2) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
        
    }
};