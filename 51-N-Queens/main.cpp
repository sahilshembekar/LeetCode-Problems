/*
Time Complexity = O(!N)
Space Complexity = O(N*N)
where N is the number of rows or the number of coloumns of the matrix.
*/

class Solution {
public:
    vector <vector <bool>> board;
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        bool x=false; // Cant declare as 2d vector with false values at the global level because n is not accessible
        for(int i=0;i<n;i++)
        {
            vector<bool> temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(x);
            }
            board.push_back(temp);
        }
        backtrack(n,0); //can be done by using the global n is it bad is it good?
        return result;
    }
    void backtrack(int n, int row) {
        //base
        if (row == n) { //basically only if we reach the last row only then we have exhausted all option and tried all rows
            vector <string> temp;
            for (int i=0; i<n; i++) {
                string s;
                    for (int j=0; j<n; j++) {
                        if (board[i][j]) {
                            s.push_back('Q');  //use '' only, not ""
                        } 
                        else {
                            s.push_back('.');
                        }
                    }
                temp.push_back(s);
            } 
            result.push_back(temp);
            
        }
        
        
        //logic
        
        for (int j =0;j<n;j++) {
            // just go column by column and check if we can add the queen in that box 
            //no point in checking in the same row therefore just directly iterate
            if(isSafe(n, row, j)) { // if this box is safe i.e. true we will enter this loop
                //if it safe then put the queen here
                board[row][j] = true;
                
                
                //recurse //basically check its babies and see where can put the next queen in the next row now
                //nect row directly because we cant put 2 queens in same row
                backtrack(n,row+1);
                
                //backtrack
                board[row][j] = false;
                
            }
            
        }
    }
    bool isSafe(int n, int row, int column) {
        
        //column check
        for (int i =0; i<row; i++) { //only check the rows in the column j till the row above it 
            //Not check below since we have not done anything there
            if(board[i][column]) { //if there is queen anywhere in this column it will give us true for if statement
                return false; //therefore unsafe to put queen here
            }
        }
        
        //diagonal upper left
        int i = row;
        int j = column;
        while(i>=0 && j>=0) {
            if (board[i][j]) {
                return false;
            }
            i--;
            j--;
            //go back till we reach the upper left corner
        }
                
        //diagonal upper right
        i = row;
        j = column;
        while(i>=0 && j<n) {
            if (board[i][j]) {
                return false;
            }
            i--;
            j++;
            //go till we reach the upper right corner
        }
        return true; //otherwise true since there is no unsafety issue
        
        
    }
};