// https://leetcode.com/problems/delete-and-earn/

// 740. Delete and Earn	


//Time Complexity = O(Maximum_Element+1) or O(N)
//Space Complexity = O(Maximum_Element+1)
//Where N is the size of the vector nums. 


class Solution {
public:
int deleteAndEarn(vector<int>& nums) {
if (nums.size() == 0) {
return 0;
}

int maxi = INT_MIN; // -2147483648
for (auto num : nums) {
maxi = max(maxi,num);
}

vector <int> vec(maxi+1, 0); // if size is 15 then we need total elements as 16 (maxi+1) i.e. 0 to 15
for (auto num : nums) {
vec.at(num) = vec.at(num) + num;
}

int skip = 0, take = vec.at(0), PreviousSkip;
for (int i = 0; i < vec.size(); i++) { // it will go from 0 till 15 as vec.size () is 16

PreviousSkip = skip;
//Not choose
skip = max(skip,take);

//Choose
take = PreviousSkip + vec.at(i);
}
return max(skip,take);

}
};

// Output
// nums: {3, 4, 2}
// maxi: 4
// vec: {0, 0, 2, 3, 4}
// skip: 3
// take: 6
// PreviousSkip: 2
---------------------------

//Time Complexity = Exponential
//Space Complexity = O(Maximum_Element)
//Here Time limit will exceed.
// class Solution {
// public:
//     int helper(vector<int> temp, int index, int profit)
//     {
//         if(index>=temp.size())
//             return profit;
//         int case0 = helper(temp,index+1,profit);
//         int case1 = helper(temp,index+2,profit+temp[index]);
//         return max(case0, case1);
//     }
//     int deleteAndEarn(vector<int>& nums) {
//         int i,maxi=INT_MIN;
//         for(i=0;i<nums.size();i++)
//             maxi=max(maxi,nums[i]);
//         vector<int> temp(maxi+1,0);
//         for(i=0;i<nums.size();i++)
//             temp[nums[i]] += nums[i]; 
//         return helper(temp, 0, 0);
//     }
// };