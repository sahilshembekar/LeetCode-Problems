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
 // pass by reference

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
// For loop
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
        //no if since size is already checked
        
        result.push_back(path);
        
        //logic
        
        for (int i = index; i <nums.size(); i++) {
            vector <int> temp(path); // Make new vector at each node
            temp.push_back(nums[i]);
            helper(nums,i+1,temp); //Call the helper using the new path
        }
    }
};

// For loop //backtrack
// pass by reference

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
        //no if since size is already checked
        
        result.push_back(path);
        
        //logic
        
        for (int i = index; i <nums.size(); i++) {
            //action
            path.push_back(nums[i]);
            //recurse
            helper(nums,i+1,path); 
            //backtrack
            path.pop_back();
            
        }
    }
};

// Without recursing
//Special solution only for this prob
/*
Time Complexity = Exponential
Space Complexity = Exponential
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> result;
        vector <int> temp;
        result.push_back(temp); //Add empty list to list of lists
        
        for (int i =0; i<nums.size(); i++) {
            int size = result.size(); //Move till size of result not size of nums
            for (int k=0; k<size; k++) {
                //Take each list from list of list and make a new list using it
                vector <int> temp(result[k]); 
                //Add each new element we are traversing through i and it to the new list made above
                temp.push_back(nums[i]);
                //Add the new list to the list of lists
                result.push_back(temp);
                //keep the original list the same and all new lists as extras separately
            }
        }
        return result;
    }
};