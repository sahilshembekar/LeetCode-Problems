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


/*
TC = O(n^4)
SC = O(l)
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
        
        int n = s.length();
        
        vector <bool> dp(n+1, false);
        
        dp[0] = true; //root node i.e. first node is a valid split
        
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if(dp[j]) { //If we have a 1 /true here that means the characters before this contain a valid split
                    if (st.find(s.substr(j,i-j)) != st.end()) {
                        // the remaining characters from the j to i also generate a valid string which is present in set
                        dp[i] = true; 
                        break; //No need to check again/remaining
                    }   
                }
            }   
        }
        return dp[n]; //return the value at last
    }
        
};