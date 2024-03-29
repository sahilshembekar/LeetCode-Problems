// https://leetcode.com/problems/longest-palindrome/

// 409. Longest Palindrome

//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.length()==0) {
            return 0;
        }
        int count = 0;
        set <char> set1;
        for (int i=0; i<s.length(); i++) {
            char c = s.at(i);
            auto it = set1.find(c);
            if (it == set1.end()) {
                set1.insert(c);
            }
            else {
                count = count+2;
                set1.erase(c);
            }
        }
        // Check if set is empty, if not empty count+1 for 1 char at the centre
        if (!set1.empty()) {
            count++;
        }
            
        return count;
    }
};
// Can Also be done like below:

				    
//   for(int i=0;i<s.size();i++)
//         {
//             if(cc.find(s[i])==cc.end())
//                 cc.insert(s[i]);
//             else
//             {
//                 cc.erase(s[i]);
//                 count+=2;
//             }
	
// s: "abccccdd"
// count: 7
// set1: {[0] = 'a', [1] = 'b'}	


//Time Complexity = O(N)
//Space Complexity = O(N)
//Where N is the number of characters in the string.
class Solution {
public:
    int longestPalindrome(string s) {
        set<char> cc;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(cc.find(s[i])==cc.end())
                cc.insert(s[i]);
            else
            {
                cc.erase(s[i]);
                count+=2;
            }
        }
        if(!cc.empty())
            count+=1;
        return count;
    }
};
