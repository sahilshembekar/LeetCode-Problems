// https://leetcode.com/problems/group-anagrams/submissions/

// 49. Group Anagrams

//Time Complexity = O(NKlogK)          
//Space Complexity = O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.empty()) {
            return ans;
        }
        map <string,vector<string>> map1;
        // vector<char> v;
        // string sorted;
        for (auto str : strs) {
            //copy(str.begin(), str.end(), back_inserter(v));
            string a= str; //a is the word 
            sort(str.begin(), str.end()); //Directly Sorting the word 
           auto it = map1.find(str);
            if (it==map1.end()) {
                map1[str].push_back(a);// The syntax is map_name[key].push_back(whatToInsert)    
            }
            else {
                it->second.push_back(a);
            }     
        }
        for (auto i: map1) {
                ans.push_back(i.second);
            }
        return ans;

    }
        
};

// Output
// strs: {"eat", "tea", "tan", "ate", "nat", "bat"}
// ans: {{"bat"}, {"eat", "tea", "ate"}, {"tan", "nat"}}
// map1: {["abt"] = {"bat"}, ["aet"] = {"eat", "tea", "ate"}, ["ant"] = {"tan", "nat"}}