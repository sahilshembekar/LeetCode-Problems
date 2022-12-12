//backtrack

// Time Complexity : exponential
// Space Complexity :exponential

class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        if(s.empty() || s.size()== 0) return result;
        
        vector<string> path;
        helper(s,0,path);
        return result;
    }
    
    void helper (string s, int index, vector <string> &path) {
        //base
        if (index == s.size()) {
            result.push_back(path);
            return;
        }
        
        //logic 
        for (int i =index; i<s.size(); i++) { //start from the pivot that is the index and check the next char
            if (isPalindrome(s,index,i)) { // Only check its babies if it is itself palindrome,otherwise skip
                //action
                path.push_back(s.substr(index,i-index+1));
                
                //recurse
                helper(s,i+1,path); // it is i+1 not index+1
                
                //backtrack
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int l, int r) {
        while(l<r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};