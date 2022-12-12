// BFS
/*
Time Complexity = O(M*N)
Space Complexity = O(M*N)
where M is the number of rows and N is the number of coloumns in the matrix.
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector <vector<int>> dirs{{0,1},{1,0},{-1,0},{0,-1}};
        int count = 0;
        //Traverse the grid
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    //if we come across 1 it is an island
                    count++;
                    grid[i][j] = '0'; //make the element itself '0'
                    queue <vector<int>> q;
                    q.push({i,j}); // add the coords to queue and go to neighbours
                    while(!q.empty()) {
                        // we do not need size var
                        //All '1's have to made '0's 
                        //No new action after each level all action are same i.e. 1 to 0
                        
                        vector <int> temp{q.front()};
                        q.pop();
                        for (int k=0; k<dirs.size(); k++) {
                            //check the neighbours
                            int r = temp[0] + dirs[k][0];
                            int c = temp[1] + dirs[k][1];
                            
                            //check edge cases and make the 1 neighbours as 0 as they are part of the same island
                            //also push them to the queue to check their corresponding neigbours // babies babies babies and so on
                            if(r>=0 && r <m && c>=0 && c<n && grid[r][c] == '1') {
                                q.push({r,c});
                                grid[r][c] = '0';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};