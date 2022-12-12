// https://leetcode.com/problems/search-a-2d-matrix-ii/

// 240. Search a 2D Matrix II	
// Time complexity: O(m+n)				      

class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
if (matrix.size()==0) {
return -1;
}
int n = matrix.size();   //rows
int m = matrix.at(0).size(); //columns

// start from the [first row, last column] element
int i=0;
int j= m-1;

while (i<n && j>=0) {
if (matrix.at(i).at(j) == target) {
return true;
}
else if (matrix.at(i).at(j) > target) { //target is smaller, go leftwards
j--; // decrease the column index
}
else { // target is larger, go downwards
i++; // increase the row index
}
}
return false;
}
};