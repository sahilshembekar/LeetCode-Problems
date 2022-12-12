// https://leetcode.com/problems/coin-change-2/
// 518. Coin Change 2
//Time Complexity = Exponential
//Space Complexity = O(N)
//Where N is the size of the vector coins. This space complexity is due to the recursive stack memory used during recursion.
class Solution {
int helper (vector<int>& coins, int amount, int index) {
//base
if (amount==0) {
return 1; // The amount becomes 0 means that this way is OK hence we return 1. i.e 1 way possible
}
if (index == coins.size() || amount < 0) {
// In case we reach the last index or when the amount goes to negative For e.g we need amount 2 with only coin 5 then amount becomes -3
//Not acceptable hence return 0

return 0;
}

//Not choose
int Case1 = helper(coins, amount, index +1); // We didnt choose any coin so amount unchanged and we have to move to next
// because we are rejecting this coin for future use

//Choose
int Case2 = helper(coins,amount - coins.at(index), index); // We choose this coin and hence we subtact that value from amount
// there is unlimited suplly of coin hence we keep the index same

return (Case1 + Case2); //Find total number of possible ways to make the amount hence addition
}
public:
int change(int amount, vector<int>& coins) {
if (coins.size()==0) {
return 0;
}
return helper(coins, amount, 0); //start at 0 index
}
};


//Time Complexity = O(M*N)
        //Space Complexity = O(M*N)
        //Where M is the size of the vector coins and N is the amount.

        class Solution {
        public:
        int change(int amount, vector<int>& coins) {
        int rows = coins.size()+1;
        int columns = amount +1;
        int value = 0;
        vector <vector <int>> dp (rows,vector <int> (columns, value)); //Initilizaing a 2d vector/Matrix with all 0
        // Can also use a 2D array

        for (int i = 1; i < rows; i++) {
        dp.at(i).at(0) = 1;
        }
        for (int i = 1; i< rows ; i++) {
        for (int j=1; j < columns; j++) {
        if (j < coins.at(i-1)) { // Till j i.e. amount is less than denomination of the coin
        dp.at(i).at(j) = dp.at(i-1).at(j);
        }
        else { // No of ways fromabove and from the denomination times steps back
        dp.at(i).at(j) = dp.at(i-1).at(j) + dp.at(i).at(j-coins.at(i-1));
        }  

        }
        }
        return dp.at(rows-1).at(columns-1);

        }
        };