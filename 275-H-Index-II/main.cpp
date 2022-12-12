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