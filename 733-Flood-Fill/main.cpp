//BFS approach

/*
Time Complexity = O(M*N)
Space Complexity =O(M*N)
Where M is the number of rows and N is the number of columns in the matrix.
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        
        if (image.size() ==0 || image[sr][sc] == newColor) { //if the source already is of the desired color then
            return image;
        }
        int m = image.size();
        int n = image[0].size();
        
        vector <vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        queue <vector<int>> q; //can also use 2 queues
        
        q.push({sr,sc}); //Add the source to the queue first
        image[sr][sc] = newColor; //Change the color of the source
        
        while(!q.empty()) {
            //we can also take size = q.size() // not needed here
            vector <int> temp{q.front()};
            q.pop();
            
            for (int j=0; j<dirs.size();j++) { //Add the coordinates and check neighbours
                int nr = temp[0] + dirs[j][0]; 
                int nc = temp[1] + dirs[j][1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc] == color) {
                    // Check edge cases always
                    //other condition to change the color of only the items which have color to newColor
                    image[nr][nc]= newColor;
                    q.push({nr,nc}); //Add the coordinates of the newly changed colors because before they were color
                }
            }
        }
        return image;
    }
};


//DFS approach

/*
Time Complexity = O(M*N)
Space Complexity =O(M*N)
Where M is the number of rows and N is the number of columns in the matrix.
*/
class Solution {
public:
    int m,n,color;
    vector <vector<int>> dirs{{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size() == 0 || image[sr][sc] == newColor) {
            return image;
        }
        color = image[sr][sc];
        m = image.size();
        n = image[0].size();
        dfs(image,sr,sc,newColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //base
        if(sr<0 || sr>=m || sc<0 || sc>=n || image[sr][sc] != color) { //if it is ou of bound or if the not the desired base color don't do anything
            return;
        }
        //logic
        image[sr][sc] = newColor; //if the color matches and it is in bound then change color to newColor
        for (int j=0 ;j<dirs.size(); j++) {
            int nr = sr + dirs[j][0];
            int nc = sc + dirs[j][1];
            dfs(image,nr,nc,newColor);
        }
        
    }
    
    
};