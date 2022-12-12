class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        
        map <int,int> map1;
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        //int count = 1;
        
        //Make a frequency map of the occcurence of elements
        //Traverse the matrix
        for(int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (map1.find(mat[i][j]) != map1.end()) {
                    map1[mat[i][j]]++;
                }
                else {
                    map1[mat[i][j]] =1;
                }
            }
        }
        
        //Mapp will be sorted based in asvending order of the keys
        //keys is nothing but the elements of matrix
        //First element which occurs which has the frequency equal to number of rows will be smallest common element in all rows
        
        for(auto &it :map1) {
            if(it.second == m) {
                result =it.first;
                break;
            }
            else {
                result = -1;
            }
            
        }
        
        return result;
        
    }
};