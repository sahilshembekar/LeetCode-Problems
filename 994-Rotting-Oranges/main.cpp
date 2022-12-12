

/*
Time Complexity = O(M*N)
Space Complexity = O(M*N)
Where M is the number of rows and N is the number of coloumns.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int i,j,fresh=0;
        queue<vector<int>> q;
        
        for(i=0;i<r;i++){
            for(j=0;j<c;j++)
                //Traverse the grid
            {
                if(grid[i][j]==1)
                    fresh++; //count incremented // for checking later
                else if(grid[i][j]==2)
                {
                    // vector<int> x{i,j}; //coordinates of the elements added to vector // can also use pair\
                    // q.push(x); //the location/coordinates are pushed in the queue
                    vector<int> x{i,j};
                    q.push(x);
                }
            }
        }    
        if(fresh==0) //if there are no fresh oranges then there is nothing to rot 
            return 0;
        if(q.empty())
            return -1;
        vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}}; //Make a directions vector to check neigbours //only 4 adjacent no diagonals
        int time=0; //updated at each level
        int size;
        while(!q.empty())
        {
            size = q.size();
            for(int k=0;k<size;k++) //traverse the queue 
            {
                vector<int> temp(q.front()); //add the vector from the queue to the temp
                q.pop();
                for(i=0;i<dir.size();i++) //Traverse in 4 directions
                {
                    int row=temp[0]+dir[i][0]; //add the x coords
                    int col=temp[1]+dir[i][1]; //add the y coords
                    if(row>=0 && row<r && col>=0 && col<c && grid[row][col]==1) //check edge cases // check if it is fresh
                    {
                        grid[row][col]=2; //make it rotten
                        vector<int> y{row,col}; //add the coords of the new rotten
                        q.push(y); //add to the queue
                        fresh--;
                    }
                }
            }
            time++; //level completed a minute is added
        }
        if(fresh==0)
            return time-1;;
        return -1; //we are unable to make all of them rotten
    }
};
