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