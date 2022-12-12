//https://leetcode.com/problems/game-of-life/

// 289. Game of Life

//Time Complexity = O(M*N)
//Space Complexity = O(1).         Since we are mutating the given matrix.
//Where M is the number of rows and N is the number of coloumns in matrix board.

class Solution {
    //0->1 = 2
    //1->0 = 3
public:
        int countLive (vector<vector<int>>& board, int i, int j) {
        int result =0;
        vector <vector<int>> dirs {{0,1},
                                   {0,-1},
                                   {1,0},
                                   {1,-1},
                                   {-1,0},
                                   {1,1},
                                   {-1,1},
                                   {-1,-1}
                                            };
        for (int k =0; k< dirs.size(); k++) {
            int nr = i + dirs[k][0];
            int nc = j + dirs[k][1];
            
            
            if (nr >=0 && nr < board.size() && nc>=0 &&  nc < board[0].size()) {
                if (board[nr][nc] == 1 || board[nr][nc] == 3) {
                    result ++;
                }
                
            }
        }
        return result;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0) {
            return;
        }
        int m= board.size();
        int n = board[0].size();
        
        for (int i=0; i< m;i++) {
            for (int j=0;j< n; j++) {
                int count = countLive(board,i,j);
                if (board[i][j] ==1 && (count < 2 || count >3)) {
                    board[i][j] = 3;
                }
                if (board[i][j] == 0 && count == 3) {
                    board[i][j] = 2;
                }
            }
        }
        
        for (int i=0; i< m;i++) {
            for (int j=0; j< n;j++) {
                if ( board [i][j] == 3) {
                    board[i][j] = 0;
                }
                if ( board [i][j] == 2) {
                    board[i][j] = 1;
                }
                
            }
        }
        return;
    }
};


//Time Complexity = O(M*N)
//Space Complexity = O(M*N).         Since we are not mutating the given matrix.
//Where M is the number of rows and N is the number of coloumns in matrix board.

class Solution {
public:
    int countinglife(vector<vector<int>>& board, int i,int j)
    {
        int count=0,r,c;
        vector<vector<int>> dir{
            {0,1},
            {1,0},
            {0,-1},
            {-1,-1},
            {-1,1},
            {-1,0},
            {1,1},
            {1,-1}
        };
        
        for(int k=0;k<dir.size();k++)
        {
            r=i+dir[k][0];
            c=j+dir[k][1];
            if(r>=0 && r<board.size() && c>=0 && c<board[0].size() && board[r][c]==1)
                count++;
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size(), c=board[0].size(),i,j,count;
        int ans[r][c];
        //0->1 = 2
        //1->0 = 3
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                count = countinglife(board,i,j);
                if(board[i][j]==1)
                {
                    if(count<2 || count>3)
                        ans[i][j]=0;
                    else
                        ans[i][j]=board[i][j]; 
                }
                else
                {
                    if(count==3)
                        ans[i][j]=1;
                    else
                        ans[i][j]=board[i][j]; 
                } 
            }
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                board[i][j]=ans[i][j];
    }
};

