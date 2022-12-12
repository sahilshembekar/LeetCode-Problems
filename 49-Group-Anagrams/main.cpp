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




//Time Complexity = O(NK)          
//Space Complexity = O(NK)
//Where N is the length of the vector of string and K is the average length of the invidual string.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <unsigned long long int, vector<string>> str;
        unsigned long long int key;
        int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        
        for(int i=0 ;i <strs.size(); i++)
        {
            key=1;
            for(int j=0; j<strs[i].size();j++ )
                key = key * prime[strs[i][j] - 'a'];
                
            str[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it: str)
            ans.push_back(it.second);
        return ans;
    }
};
