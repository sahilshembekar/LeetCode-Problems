//Hashmap Solution

/*
Time Complexity = O(n+m)
Space Complexity = O(n)
where n1 is the number of elements in array nums1 and n2 is the number of elements in the array nums2.
*/


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int i;
        map <int,int> m;
        vector <int> result;
        for (i=0; i<n1; i++) {
            if(m.find(nums1[i]) == m.end()) {
                //if we reach the end and dont find 
                //add the count (at start count is 1) for this element
                m.insert({nums1[i],1}); // use/check syntax
            }
            else {
                m[nums1[i]]++; //else simply increase the count
            }
        }
        
        for (i=0 ;i<n2; i++) {
            if(m.find(nums2[i]) != m.end()) {
                //basically if we find that element in the map
                if (m[nums2[i]] != 0) {
                    //and if it not equal to 0
                    m[nums2[i]]--;
                    result.push_back(nums2[i]); //add the number in the result since it was found
                }
            }
        }
        return result;
    }
};