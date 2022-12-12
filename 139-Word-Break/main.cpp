/*
TC = Exponential
SC = Exponential
Time limit exceeded
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() != 0 && wordDict.size() == 0) {
            return false;
        }
        
        // Make a hashset from the vector of Dict
        set <string> st; 
        for(int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        
        // Delegate to a function
        return helper(s,st);
    }
    
    bool helper(string s, set <string> st) {
        //base case
        // if we reach the end of the string
        if (s.length() == 0) {
            return true;
        }
        
        //logic
        for (int i = 0; i <=s.length(); i++) {
            
            if(st.find(s.substr(0,i)) != st.end() && helper(s.substr(i),st)) {
                // part a means we look for match 1 by 1 l, le, lee, leet and so on
                // part b is recurse call on the rest (i to end (end is default in substr)) of the string only if part holds true // property of && function
                return true;       
            }
        }   
    return false;
    }
};