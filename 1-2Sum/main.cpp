//Time Complexity = O(N)
//Space Complexity = O(N)
//Where N is the size of vector nums.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        map <int,int> m;
        for (int i=0;i<nums.size();i++) {
            m.insert({nums[i],i});
        }
        for (int i=0;i<nums.size();i++) {
            int compliment = target-nums[i];
            if (m.find(compliment) != m.end() && m[compliment] != i) {
                result.push_back(i);
                result.push_back(m[compliment]);
                break;
            }
        }
        return result;
    }
};


//in 1 for loop itself

//Time Complexity = O(N)
//Space Complexity = O(N)
//Where N is the size of vector nums.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};

// 2pointers

//Time Complexity = O(NlogN)
//Space Complexity = O(N)
//Where N is the size of vector nums.
class Solution {
public:
    vector < int> twoSum(vector< int>& nums, int target) {
        int low=0,high=nums.size()-1,n1,n2;
        vector< int> v,nums2;
        nums2=nums;
        sort(nums2.begin(),nums2.end());
        while (low<high){
            if (nums2[low]+nums2[high]<target) {
			low++;
            }
            
            else if(nums2[low]+nums2[high]>target){
                high--;
            }
            else {   //nums2[low]+nums2[high]==target
                n1=nums2[low]; 
			    n2=nums2[high];
			    break;
 		    } 
 	    }
	
        for (int i=0;i< nums.size() ; i++){
            if (nums[i]==n1) {
                v.push_back(i); 
            }
            else if (nums[i]==n2) {
                v.push_back(i);
            }
            
		 }
        return v;
    }
};