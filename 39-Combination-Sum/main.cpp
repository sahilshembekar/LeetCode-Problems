//No backtracking //pass by value

/*
Time Complexity = Exponential
Space Complexity = Exponential
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> path;
        //null
        if (candidates.size() == 0) return result;
        helper(candidates,0,target, path);
        return result;
    }
    
    void helper (vector <int> candidates, int index, int target, vector <int> path) { //pass by value here
        //base case
        if (target==0) {
            // we have a valid path 
            result.push_back(path);
            return;
        }
        if(index ==candidates.size() || target<0) {
            // if we reach the end or if the target becomes negative that is an invalid case
            // i.e. return nothing
            return;
        }
        
        
        //logic
        
        //Not choose case
        
        helper(candidates,index+1,target, path); 
        //not chosen hence we move to next index and target unchanged
        
        //Chooose case
        path.push_back(candidates[index]);
        
        helper(candidates,index,target- candidates[index], path);
        //noUnlimited supply hence same index and target reduced by number by chosen
        
        
    }
};


//Backtracking //pass by reference

/*
Time Complexity = Exponential
Space Complexity = Exponential
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> path;
        //null
        if (candidates.size() == 0) return result;
        helper(candidates,0,target, path);
        return result;
    }
    
    void helper (vector <int> candidates, int index, int target, vector <int> &path) { //pass by reference here
        //base case
        if (target==0) {
            // we have a valid path 
            result.push_back(path);
            return;
        }
        if(index ==candidates.size() || target<0) {
            // if we reach the end or if the target becomes negative that is an invalid case
            // i.e. return nothing
            return;
        }
        
        
        //logic
        
        //Not choose case
        
        helper(candidates,index+1,target, path); 
        //not chosen hence we move to next index and target unchanged
        
        //Choose case
        
        //action
        path.push_back(candidates[index]);
        //recurse
        helper(candidates,index,target- candidates[index], path);
        //Unlimited supply hence same index and target reduced by number by chosen
        
        //backtrack
        path.pop_back();
        
    }
};


//No backtracking //pass by value

//for loop recurse

/*
Time Complexity = Exponential
Space Complexity = Exponential
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> path;
        //null
        if (candidates.size() == 0) return result;
        helper(candidates,0,target, path);
        return result;
    }
    
    void helper (vector <int> candidates, int index, int target, vector <int> path) { //pass by value here
        //base case
        if (target==0) {
            // we have a valid path 
            result.push_back(path);
            return;
        }
        if(target<0) { //candidates.size() checked in for loop 
            // if we reach the end or if the target becomes negative that is an invalid case
            // i.e. return nothing
            return;
        }
        
        
        //logic
        
        for(int i=index;i<candidates.size();i++) { //Start at pivot i.e. where we stopped previously
            //action
            
            vector<int> copyOfPath(path);
            copyOfPath.push_back(candidates[i]);
            helper(candidates,i,target-candidates[i], copyOfPath);
        }
        
    }
};


//backtracking //pass by reference

//for loop recurse

/*
Time Complexity = Exponential
Space Complexity = Exponential
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> path;
        //null
        if (candidates.size() == 0) return result;
        helper(candidates,0,target, path);
        return result;
    }
    
    void helper (vector <int> candidates, int index, int target, vector <int> &path) { //pass by reference here
        //base case
        if (target==0) {
            // we have a valid path 
            result.push_back(path);
            return;
        }
        if(target<0) { //candidates.size() checked in for loop 
            // if we reach the end or if the target becomes negative that is an invalid case
            // i.e. return nothing
            return;
        }
        
        
        //logic
        
        for(int i=index;i<candidates.size();i++) { //Start at pivot i.e. where we stopped previously
            //action
            
            path.push_back(candidates[i]);
            //recurse
            helper(candidates,i,target-candidates[i], path);
            
            //backtrack
            path.pop_back();
            
        }
        
    }
};


