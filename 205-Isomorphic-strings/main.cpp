// https://leetcode.com/problems/isomorphic-strings/

// 205. Isomorphic Strings

//Time Complexity = O(N)
//Space Comlexity = O(1) 


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length()==0) {
            return false;
        }
        map <char,char> smap;
        map <char,char> tmap;
        for (int i=0; i<s.length(); i++) {
            char schar = s.at(i);
            char tchar = t.at(i);
            
        auto it = smap.find(schar); 
        if (it == smap.end()) {
            smap.insert({ schar, tchar });
        }
            
        // if (it->second != tchar) {
        //     return false;
        // }
        else if (it->second != tchar) {
            return false;
        }
            
        auto it2 = tmap.find(tchar); 
        if (it2 == tmap.end()) {
            tmap.insert({ tchar, schar });
           
        }
        //else 
        else if (it2->second != schar){
             return false;
        }
        }
        return true;  
    }
};

// Output on debugger Why is char and ascii value both stored in key of map??

// schar: 'g'
// tchar: 'd'
// it: {first = 103 'g', second = 'd'}
// it2: {first = 100 'd', second = 'g'}
// i: 2
// s: "egg"
// t: "add"
// smap: {[101 'e'] = 'a', [103 'g'] = 'd'}
// tmap: {[97 'a'] = 'e', [100 'd'] = 'g'}