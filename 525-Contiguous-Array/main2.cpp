//Output
	
// nums: {0, 1}
// max1: 2
// count: 0
// map1: {[-1] = 0, [0] = -1}

//Time Complexity = O(N)
//Space Complexity = O(N)
//Where N is the number of the elements in my array. 

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxi = 0;
        map <int, int> m;
        m.insert({0,-1});
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) sum = sum -1;
            else sum = sum +1;
            if(m.find(sum)==m.end())
                m[sum]=i;
            else
                maxi = max(maxi, i - m[sum]);
        }
        return maxi;
    }
};
