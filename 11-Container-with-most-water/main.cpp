 // https://leetcode.com/problems/container-with-most-water/
// 11. Container With Most Water

//Time Complexity = O(N*N)
//Space Complexity = O(1)
//where N is the size of the vector height
//here time limit will exceed.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int Max = 0;
        if (height.size()==0) {
            return 0;
        }
        for (int i = 0; i<height.size(); i++) {
            for (int j = i+1; j<height.size(); j++) {
                Max = max(Max, (j-i)*(min(height[i],height[j])));
            }
        }
        return Max;
    }
};
    


//Time Complexity = O(N)
//Space Complexity = O(1)
//where N is the size of the vector height.
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size()==0) {
            return 0;
        }
        int Max =0;
        int low =0;
        int high = height.size()-1;
        while (low<high) {
            Max = max(Max, (high-low) * min (height[low], height[high]) );
                if (height[low] <= height[high]) {
                    low++;
                }
            else {
                high--;
            }
        }
        return Max;
    }
};    
 
    
