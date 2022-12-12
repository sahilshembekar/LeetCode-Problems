class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        n = len(mat[0])
        result = [0] * (m * n)
        # result = [0 in range(m*n)] --> Does not work #Debug
        
        i = 0;
        row = 0;
        column = 0;
        
        dir = 1;
        
        while i < (m*n):
            result[i] = mat[row][column]
            i+=1
            
            if dir == 1 :
                # bottom to top 
                if column == n-1 :
                    row+=1
                    dir = 0
                elif row == 0 :
                    column+=1
                    dir = 0
                else :
                    row-=1
                    column+=1
            else :
                # top to bottom 
                if row == m-1 :
                    column+=1
                    dir = 1
                elif column == 0 :
                    row+=1
                    dir = 1
                else :
                    row+=1
                    column-=1
        
        return result
        