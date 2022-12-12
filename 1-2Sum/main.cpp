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
