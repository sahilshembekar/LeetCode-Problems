/*
Time Complexity = O(m*n)^2
Space Complexity = O(1)
where m is the number of rows and n is the number of coloumns in the matrix. 
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool flag = false;
        int curr;
        int maxi=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                //check if we have a '1'
                if (matrix[i][j] == '1') {
                    flag = true;
                    curr = 1;
                    
                    //go diagonally
                    while(i+curr<m && j+curr<n && flag) {
                        //if anywhere we hit the flag as false we come out of the loop
                        
                        //same row for j+curr
                        
                        //traverse the row
                        for (int k =j; k<=j+curr; k++) {
                            if (matrix[i+curr][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int k =i; k<=i+curr; k++) {
                            if (matrix[k][j+curr] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        
                        if(flag) {
                            curr++;
                        }
                    }
                    maxi= max(maxi,curr);
                }       
            }
        }
        return maxi*maxi;
    }
};


/*
Time Complexity = O(m*n)
Space Complexity = O(m*n)
where m is the number of rows and n is the number of coloumns in the matrix. 
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool flag = false;
        int i,j;
        int maxi=0;
        int dp[m+1][n+1]; //or can declare a vector
        //Make dummy row and column
        for (i=0;i<=m;i++) {
            //Make first column 0
            dp[i][0] = 0;
        }
        for (i=0;i<=n;i++) {
            //Make first row 0
            dp[0][i] = 0;
        }
        for(i=1; i<=m;i++) {
            for(j=1;j<=n;j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
                    // dp[i-1][j-1]-> Diagonal top
                    // dp[i-1][j]-> Top
                    // dp[i][j-1]-> Left
                }
                else {
                    dp[i][j] = 0;
                }
                maxi = max(maxi,dp[i][j]);
            }
        }
        return maxi*maxi;
    }
};

/*
Time Complexity = O(m*n)
Space Complexity = O(n)
where m is the number of rows and n is the number of coloumns in the matrix. 
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i,j;
        int maxi=0,prev=0,diagUp=0;
        int dp[n+1]; //or can declare a vector
        //Make first dummy row
        for (i=0;i<=n;i++) {
            //Make first row 0
            dp[i] = 0;
        }
        for(i=1; i<=m;i++) {
            for(j=1;j<=n;j++) {
                prev = dp[j];
                if (matrix[i-1][j-1] == '1') {
                    dp[j] = min(diagUp, min(dp[j],dp[j-1])) + 1;
                }
                else {
                    //basically if we encounter a 0 we do this
                    //since we use the same array again and again
                    dp[j] =0;
                }
                maxi = max(maxi,dp[j]);
                diagUp = prev;
            }
        }
        return maxi*maxi;
    }
};