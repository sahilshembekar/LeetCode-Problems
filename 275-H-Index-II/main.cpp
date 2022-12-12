//Linear Search 

/*
Time Complexity = O(n)
Space Complexity = O(1)
where n is the number of elements in the vector.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        for (int i=0; i<n; i++) {
            if (citations[i] >= n-i) {
                return n-i;
            }
        }
        return 0;
    }
};

//Binary Search

/*
Time Complexity = O(logn)
Space Complexity = O(1)
where n is the number of elements in the vector.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        //Need the NULL case here
        if (citations.size() == 0) return 0;
        
        int n = citations.size();
        int low =0;
        int high = n-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (citations[mid] == n-mid) {
                return n-mid;
            }
            else if (citations[mid] < n-mid) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return n-low;
    }
};