/*
Time Complexity = O(n)
Space COmplexity = O(1)
where n is the number of alphabet in the string.
Here space complexity is 1 because at max in the hashmap there can be only 26 alphabet.
*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Null Case
        if (s.size() == 0) {
            return 0;
        } 
        
        map<char, int> m; //position map
        int slow =0;
        int maxi = INT_MIN; //Can also be set to 0
        //int start,end;
        //Uncomment the above to get the pointers in global scope to mark the position of longest substring
        
        //i is going to the fast pointer here
        for (int i =0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end()) {
                // if we actually have that character in the map
                slow = max(slow, m[s[i]]); //update the slow to the max value 
            }
            m[s[i]] = i+1;//Store the occurance as index + 1
            maxi = max(maxi,i-slow+1); //since we need the length we calculate that using fast (i.e. i) - slow + 1 (for length we need extra 1 because it starts from 1)
            
            
            //Follow up question print the correponding longest string
            //Comment the above line of maxi and uncomment the below loop
            // if (i-slow+1 > maxi) {
            //     maxi = i-slow+1;
            //     start = slow;
            //     end =i;
            // }
        }
        //Uncomment below line to get the actual string
        //cout << s.substr(start,end-start+1);
        return maxi;
    }
};