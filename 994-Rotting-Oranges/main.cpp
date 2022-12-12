class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        
        queue <vector <int>> q;
        int fresh=0;
        for (int i=0; i<m; i++) {
            for (int j=0;j<n;j++) {
                //Traverse the grid
                if(grid[i][j] == 1) {
                    fresh++; //count incremented // for check later
                }
                else if(grid[i][j] ==2) {
                    vector <int> x{i,j}; //coordinates of the elements added to vector // can also use pair\
                    q.push(x); //the location/coordinates are pushed in the queue
                }
            }
        }
        if (fresh == 0)  return 0; //if there are no fresh oranges then there is nothing to rot // Like null case
        //if (q.empty()) return -1;
        
        vector <vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}}; //Make a directions vector to check neigbours //only 4 adjacent no diagonals
        
        int time =0; //updated at each level
        while(!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) { //traverse the queue
                vector <int> temp{q.front()}; //add the vector from the queue to the temp
                q.pop();
                for (int j=0; j<dir.size(); j++) {//Traverse in 4 directions
                    int r = temp[0] + dir[j][0]; //add the x coords
                    int c = temp[1] + dir[j][1]; //add the y coords
                    
                    if (r >=0 && r < m && c>=0 && c< n && grid[r][c] == 1 ) { //check edge cases // check if it is fresh
                        grid[r][c] = 2; //make it rotten
                        vector<int> vec{r,c}; //add the coords of the new rotten
                        q.push(vec); //add to the queue
                        fresh--;
                    }
                }
            }
            time++; //level completed a minute is added
        }
        cout << fresh<<endl;
        cout <<time;
        if (fresh > 0) {
            return -1; //we are unable to make all of them rotten
        }
        else {
            return (time-1);
        }
    }
};