// https://leetcode.com/problems/paint-house/

// 256. Paint House

//Time Complexity =O(2^(N))
//Space Complexity = O(1)
//Where N is the number of rows in matrix. 

class Solution {
int helper (vector<vector<int>>& costs, int row, int CurrentColour, int minCost) {
//base case
if (row == costs.size()) {
return minCost;
}

//logic
if (CurrentColour == 0) {
return min(helper(costs, row+1, 1, minCost+costs.at(row).at(0)),helper(costs, row+1, 2, minCost+costs.at(row).at(0)));
}
if (CurrentColour == 1) {
return min(helper(costs, row+1, 0, minCost+costs.at(row).at(1)),helper(costs, row+1, 2, minCost+costs.at(row).at(1)));
}
if (CurrentColour == 2) {
return min (helper(costs, row+1, 0, minCost+costs.at(row).at(2)),helper(costs, row+1, 1, minCost+costs.at(row).at(2)));
}
return 1234; //Random number

}
public:
int minCost(vector<vector<int>>& costs) {
if (costs.size() == 0) {
return 0;
}

int Case1 = helper(costs, 0,0,0);
int Case2 = helper(costs, 0,1,0);
int Case3 = helper(costs, 0,2,0);
return min(Case1, min(Case2,Case3));

}
};

//Time Complexity =O(N)
//Space Complexity = O(1)        if interviewer tell us that we can change the given matrix.
//Where N is the number of rows in matrix. 
class Solution {
public:
int minCost(vector<vector<int>>& costs) {

for (int i = costs.size()-2; i >=0; i--) {
costs[i][0] = costs[i][0] + min ( costs[i+1][1] , costs[i+1][2]);
costs[i][1] = costs[i][1] + min ( costs[i+1][0] , costs[i+1][2]);
costs[i][2] = costs[i][2] + min ( costs[i+1][0] , costs[i+1][1]);
}
return min(costs[0][0], min(costs[0][1],costs[0][2]));
}
};


//Time Complexity = O(N)
//Space Complexity = O(1)
//Where N is the number of rows in matrix. 

class Solution {
public:
int minCost(vector<vector<int>>& costs) {
//vector <vector<int>> dp[costs.size()][3]; //Make a new matrix
int rows = costs.size();
int columns = 3;
int value = 0;
vector <vector <int>> dp (rows,vector <int> (columns, value));

for (int j= 0; j< 3; j++) {
dp[rows-1][j] = costs[costs.size()-1][j];
}

for (int i = costs.size()-2; i >=0; i--) {
dp[i][0] = costs[i][0] + min ( dp[i+1][1] , dp[i+1][2]);
dp[i][1] = costs[i][1] + min ( dp[i+1][0] , dp[i+1][2]);
dp[i][2] = costs[i][2] + min ( dp[i+1][0] , dp[i+1][1]);
}
return min(dp[0][0], min(dp[0][1],dp[0][2]));
}
};