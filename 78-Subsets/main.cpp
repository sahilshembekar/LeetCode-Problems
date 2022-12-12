// Recursive 
//New path at each node // pass by value

/*
Time Complexity = Exponential = 2 raise to n // 2 because 2 options
Space Complexity = Exponential
*/

class Solution {
public:
    vector <vector <int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return result;
        vector <int> path;
        helper(nums,0,path);
        return result;
    }
    void helper(vector<int>& nums, int index, vector <int> path) {
        //base
        if (index == nums.size()) { //store the path in the result only when we reach the leaf node
            result.push_back(path);
            return;
        }
        //Not choose
        helper (nums,index+1,path);
        
        //choose
        //we need to add it if we choose it
        //action
        path.push_back(nums[index]);
        helper (nums,index+1,path);
    }
};

// Recursive //backtrack
//New path at each node // pass by reference

/*
Time Complexity = Exponential = 2 raise to n // 2 because 2 options
Space Complexity = Exponential
*/

class Solution {
public:
    vector <vector <int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return result;
        vector <int> path;
        helper(nums,0,path);
        return result;
    }
    void helper(vector<int>& nums, int index, vector <int> &path) {
        //base
        if (index == nums.size()) { //store the path in the result only when we reach the leaf node
            result.push_back(path);
            return;
        }
        //Not choose
        helper (nums,index+1,path);
        
        //choose
        //we need to add it if we choose it
        //action
        path.push_back(nums[index]);
        //recurse
        helper (nums,index+1,path);
        
        //backtrack
        path.pop_back();
    }
};