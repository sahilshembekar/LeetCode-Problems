/*
Time Complexity = O(m*n* 3^L)
Space Complexity = O(L)
where m is the number of rows and n is the number of coloumns and L is the length of string word.
*/

class Solution {
public:
    int m,n;
    vector <vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};

    bool exist(vector<vector<char>>& board, string word) {
        //null case
        if (board.size() == 0) return false;
        m = board.size();
        n = board[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (backtrack(board,word, i,j,0)) return true;
            }
        }
        return false;
    }
    
    bool backtrack(vector<vector<char>>& board, string word, int i,int j, int index) {
        //base
        if (word.size() == index) return true; //that is we reach the last element of the word basically we finished the word and found it
        
        
        if(i<0 || j<0 || i ==m || j==n || word[index]!= board[i][j]) { 
            return false;
        }
        
         
        
        //Special case for 1 character word
        
        if (index == word.size()-1) return true;
       
        
        //logic
        //action
        if (word[index] == board[i][j]) {
            //if we get the wordwhile traversing
            char ch = board[i][j]; // store the character from that location into ch
            board[i][j] = '#'; //Basically marking it as visited
            
            //recurse
            for (int k =0; k<dirs.size(); k++) {
                int r = i + dirs[k][0];
                int c = j + dirs[k][1];
                if (backtrack (board,word,r,c,index+1)) return true; //go to the next char of the word
                // if the whole word is found then we return true and backtrack one by one 
                // this true will actually be returned to function call of main function!?
            }

            //backtrack
            board[i][j] = ch; // restore the character
        }
        return false; //if from none of the neighours we are able to get the next char of the word then return false 
    }
};