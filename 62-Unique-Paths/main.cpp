/*
Time Complexity = exponential
Space Complexity = exponential
where m is the number of rows and n is the number of coloumns.
*/
//Recursive 
class Solution {
public:
    int uniquePaths(int m, int n) {
        //NULL case
        if(m == 0 && n == 0) return 0;
        return dfs(m,n,0,0); //0,0 start indices
    }
    
    int dfs(int m, int n, int i, int j) {
        //base case
        if(i==m || j ==n) {
            return 0; //To keep it in bounds
        }
        if(i ==m-1 && j ==n-1) {
            return 1; //Last element/index has nothing put 1 hence return 1
        }
        
        //logic
        return dfs(m,n,i+1,j) + dfs(m,n,i,j+1); // right (column+1) + bottom (row+1)
    }
};

/*
Time Complexity = O(m*n)
Space Complexity = O(m*n)
where m is the number of rows and n is the number of coloumns.
*/

//Bottom up DP

class Solution {
public:
    int uniquePaths(int m, int n) {
        //NULL case
        if(m == 0 && n == 0) return 0;
        //Made a dummy row and column
        // can be also done without a dummy stuff. just add (a) and reove (b)
        vector<vector<int>> dp(m+1,vector<int> (n+1,0)); //Declaring 2d vector with m rows and n columns
        
        dp[m-1][n-1] = 1; //Last Element is made 1
        for (int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                // if(i == m-1 || j == n-1) { dp[i][j] = 1; //Last row and column directly made 1}
                if(i == m-1 && j == n-1) { //(b)
                    continue; //that is don't do anything for the last element
                }
                
                dp[i][j] = dp[i+1][j] + dp[i][j+1]; //Add element from the bottom and right
            }
        }
        return dp[0][0];
    }
};

/*
Time Complexity = O(m*n)
Space Complexity = O(n)
where m is the number of rows and n is the number of coloumns.
*/

//Overwrite the row/array

class Solution {
public:
    int uniquePaths(int m, int n) {
        //NULL case
        if(m == 0 && n == 0) return 0;
        
        vector<int> dp(n,1); //Declaring a vector n columns/elements
        
        
        for (int i=m-2; i>=0; i--) { //start from 2nd last // last already taken care of
            for(int j=n-2; j>=0; j--) {
                dp[j] = dp[j] + dp[j+1]; //old value will behave like bottom element and right will come from dp[j+1] 
            }
        }
        return dp[0];
    }
};