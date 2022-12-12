/*
Time Complexity = O(n+m)
Space Complexity = O(n) = O(1) // max 26 small characters
where n is the length of the string p and m is the length of the string s.
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> result;
        // NULL case + if the string source is smaller than the pattern then no anagram will exist
        if (p.length() == 0 || s.length() < p.length()) {
            return result;
        }
        int match =0;
        int i;
        
        map<char,int> m;
        for (i =0; i<p.length(); i++) {
            //insert alll characters in map as key and count as value]
            m[p[i]]++;
        }
        
        //Window Started
        
        for (i =0; i<s.length(); i++) { //Acts like a fast pointer
            if(m.find(s[i]) != m.end()) {
                //for incoming character if its exists in the map for e.g. e will not exist
                
                int count = m[s[i]]; //value from map
                count--;
                if (count ==0) {
                    //for count =0 we have a perfect match therefore match found
                    match++;
                }
                m[s[i]] = count;
            }
            
            //Outgoing elements will only start once we reach the pattern p.length() and onwards
            if (i >= p.length()) {
                if (m.find(s[i- p.length()]) !=  m.end()) {
                    // i- p.length() will give us the location of outgoing char which is 1 before the start of the actual window
                    int count = m[s[i- p.length()]];
                    count++;
                    if (count == 1) {
                        //if count becomes 1 we lose the match
                        match--;
                    }
                    m[s[i- p.length()]] = count;
                }
            }
            if (match == m.size()) {
                // if we have matched all unique characters that m.size = match
                result.push_back(i- p.length() +1); //location of slow pointer is outgoing_char +1 i.e. i- p.length()+1
            }
        }
        return result;
    }
};