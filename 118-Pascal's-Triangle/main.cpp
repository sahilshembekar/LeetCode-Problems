// Time Complexity : O(n2)
// Space Complexity : O(n2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows); // Initiliaze numRows 
        for (int i=0; i<numRows; i++) {
            result[i] = vector<int> (i+1,1);  // ith row(0-indexed) has i+1 elements //and make all elements as 1
            for (int j=1; j<i; j++) {
                // 1st and last elements will be 1, rest of them are sum of two elements from the above row
                // can use if case to check first and last elements as well
                // if(j==0 || j==i) {
                //     result[i][j];
                // }
                //else {
                result[i][j] = result[i-1][j] + result[i-1][j-1]; 
                //}
            }
        }
        return result;
    }
};