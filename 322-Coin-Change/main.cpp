// https://leetcode.com/problems/coin-change/submissions/

// 322. Coin Change

//Time Complexity = O(M*N)
//Space Complexity = O(M*N)
//Where M is the amount and N is the length of the vector coins.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size()==0) {
            return 0;
        }
        int dp [coins.size()+1][amount+1];  // Row is coins + dummy row and column is amount starting from 0
        //Top row-Dummy row
        for (int j=1; j<amount+1;j++) { //123456789 10 11
            dp[0][j] = amount+1;  //Value greater than the amount // cannot use infinity as we it will throw out of bound error if 1 is added
        }
        for(int i=0;i<=coins.size();i++)            //Assigning the first coloumn(coloumn with amount 0) to 0 . Other language will have defalut value as 0. cpp has garbage value.
            dp[i][0]=0;
        
        //Contents of the matrix
        for (int i=1; i<coins.size()+1;i++) { // Traverse the rows 1
            for (int j=1; j<amount+1; j++) { // Traverse the columns
                
                if (j < coins[i-1]) { // if we have not reached the amount equal to the denomination of the coin // i-1 since we have an extra dummy row
                    // j=3 and coin[i-1]=coins[3-1]=coins[2]=5
                    dp[i][j] = dp[i-1][j]; //Take the value from the upper box
                }
                else {
                    dp[i][j] = min(dp[i-1][j],1+ dp[i][j - coins[i-1]]);
                }
            }
        }
        if (dp[coins.size()][amount] > amount) {
            return -1;
        }
        else {
            return dp[coins.size()][amount];
        }
    }
}; 

// coins: {1, 2, 5}
// amount: 11
// __vla_expr0: 4
// __vla_expr1: 12
// dp: {{0, 12 <repeats 11 times>}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6}, {0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 2, 3}}

// Time Complexity = O(2^N).   EXPONENTIAL
// //Space Complexity = O(N)
// //Where N is the length of the vector coins.
// //Here time limit will exceed.
// //The recursive stack memory is also counted towards the space complexity.
// class Solution {
// public:
//     int helper(vector<int> coins, int amount, int index, int mincoins)
//     {
//         //base case
//         if(amount==0)
//             return mincoins;
//         if(index>=coins.size() || amount<0)
//             return -1;
//         int case0 = helper(coins, amount, index+1, mincoins);
//         int case1 = helper(coins, amount-coins[index], index, mincoins+1);
        
//         if(case0==-1)                                                           //if these two "IF" statement were not used then answer will always be -1.
//             return case1;
//         if(case1==-1)
//             return case0;
//         return min(case0,case1);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         return helper(coins, amount, 0, 0);
//         //here 0 is the index in coins vector.
//     }
// };
