//BFS approach


/*
Time Complexity = O(M*N)
Space Complexity = O(M*N)
Where M is the number of rows and n is the number of coloumns in the matrix.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.size() == 0) return mat;
        
        int m = mat.size();
        int n = mat[0].size();
        
        queue <vector<int>> q;
        for (int i =0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i,j}); //take the independents in the queue
                }
                else { //mat consists of only 0 and 1
                    mat[i][j] = -1; //change the value from 1 to -1 
                    // to differentiate from the distance from 0 which can also be 1 and also to avoid overwriting because they can be neigbours of 2 zeros 
                    // and we need to update it only once
                }
            }
        }
        int dist = 1; // 1
        vector<vector<int>> dirs{{0,1},{1,0},{-1,0},{0,-1}};
        
        while (!q.empty()) {
                int size = q.size(); // 2
                for (int i =0; i< size; i++) { // 3 for loop
                    vector <int> temp{q.front()};
                    q.pop();

                    for(int j=0; j<dirs.size(); j++) {
                        int r = temp[0] + dirs[j][0];
                        int c = temp[1] + dirs[j][1];
                        if (r>=0 && r<m && c>=0 && c<n && mat[r][c] == -1) { 
                            //1 changed to -1 previously will be checked only once and when found it will be replaced with dist
                            mat[r][c]= dist; // 7

                            q.push({r,c});

                        }
                    }

                } //3 for loop or 4
            dist++; // 5 
        }
        return mat;
    }
};

// Can also do without 1~5 
//And instead of 7 use  mat[r][c]= mat[r][c] + 1; // probably this is correct -> mat[r][c]= mat[temp[0]][temp[1]] + 1 ??
//basically babies will be 1 + whatever it is coming from