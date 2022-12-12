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


//2 pointer Solution

/*
if array is not sorted already.
Time Complexity = O(nlogn + mlogm)
Space Complexity = O(1)

if array is already sorted.
Time Complexity = O(n + m)
Space Complexity = O(1)
where n1 is the number of elements in array nums1 and n2 is the number of elements in the array nums2.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int i;
        
        vector <int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(),nums2.end());
        int p1=0, p2=0;
        while(p1<n1 && p2<n2) {
            if (nums1[p1] == nums2[p2]) {
                //when the common number is found push it in result
                result.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else if (nums1[p1] < nums2[p2]) {
                //Move the p1 pointer if because value there is smaller
                p1++;
            }
            else {
                p2++;
            }
        }
        return result;
        
    }
};



//Binary Search Solution

/*
Time Complexity = O(nlogm)
Space Complexity = O(1)
where n1 is the number of elements in array nums1 and n2 is the number of elements in the array nums2.
*/

class Solution {
public:
    int binarySearch (vector<int> nums, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) {
                // to make sure we find first occurence of element
                if (mid == low || nums[mid-1] < nums[mid]) {
                    return mid;
                }
                //move to the left since this is not the first instance maybe there are multiple 4's
                high = mid-1;
            }
            else if(nums[mid] < target) {
                // Move towards the target which on the right side
                low = mid+1;
            }
            else {
                high =  mid-1;
            }
        }
        return -1; //else when the element is not found
    }
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1>n2) {
            intersect(nums2,nums1); //nums2 is smaller than nums1
        }
        int i;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        
        int low = 0;
        int high = nums2.size()-1;
        //The nums2 array is bigger hence we do binary search on that one
        for (i=0; i<n1; i++) {
            int index = binarySearch(nums2, nums1[i], low, high);
            if (index != -1) {
                result.push_back(nums1[i]);
                //Skip all the elements including this one
                low = index+1;
            }
        }
        return result;
    }
};