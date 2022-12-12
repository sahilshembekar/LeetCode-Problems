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