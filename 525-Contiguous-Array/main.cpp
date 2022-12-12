//https://leetcode.com/problems/contiguous-array/
	
// 525. Contiguous Array

//Time Complexity = O(N)
//Space Complexity = O(N)
//Where N is the number of the elements in my array. 



class Solution {
    
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size()==0) {
            return 0;
        }
        int max1=0;
        int count =0;
        map <int,int> map1;
        map1.insert({0,-1});
        
        for (int i=0;i<nums.size();i++) {
            if (nums.at(i) ==0) {
                count = count-1;
            }
            else {
                count = count +1;
            }
            auto it = map1.find(count);
            if (it == map1.end()) {
                map1.insert({count, i});
            }
            else {
                
                max1 = max(max1, i- it->second);
            }
        }
        return max1;
    }
}; 

	
    //Can Also be done
    // if(m.find(sum)==m.end())
    //     m[sum]=i;
    // else
    //     maxi = max(maxi, i - m[sum]);
	
	
//Output
	
// nums: {0, 1}
// max1: 2
// count: 0
// map1: {[-1] = 0, [0] = -1}