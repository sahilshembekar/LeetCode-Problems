//https://leetcode.com/problems/subarray-sum-equals-k/

//560. Subarray Sum Equals K

//Time Complexity = O(N)
//Space Complexity = O(N)
//where N is the number of elements in the array.

	
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size()==0) {
            return 0;
        }
        int count =0;
        int rSum = 0;
        map <int,int> map1;
        map1.insert({0,1});
        for (int i=0; i<nums.size(); i++) {
            rSum = rSum + nums.at(i);
            auto it = map1.find(rSum-k);
            if (it != map1.end()) {
                count = count + it->second;
            } 
            auto it2 = map1.find(rSum);
            if (it2 == map1.end()) {
                map1.insert({rSum,1});
            }
            else {
                it2->second = it2->second+1;
            }
        }
        return count;
        
    }
};
	
// Other way
	
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m.insert({0,1});
        int rsum=0, count=0;
        for(int i=0;i<nums.size();i++)
        {
            rsum+=nums[i];
            if(m.find(rsum-k)!=m.end())
                count += m[rsum-k];
            m[rsum]++;
        }
        return count;
    }
};

					  

//Output
// nums: {1, 1, 1}
// k: 2
// count: 2
// rSum: 3
// map1: {[0] = 1, [1] = 1, [2] = 1, [3] = 1}
					  
					  