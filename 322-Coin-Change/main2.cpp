//Time Complexity = O(2^N).   EXPONENTIAL
//Space Complexity = O(N)
//Where N is the length of the vector coins.
//Here time limit will exceed.
//The recursive stack memory is also counted towards the space complexity.
class Solution {
public:
    int helper(vector<int> coins, int amount, int index, int mincoins)
    {
        //base case
        if(amount==0)
            return mincoins;
        if(index>=coins.size() || amount<0)
            return -1;
        int case0 = helper(coins, amount, index+1, mincoins);
        int case1 = helper(coins, amount-coins[index], index, mincoins+1);
        
        if(case0==-1)                                                           //if these two "IF" statement were not used then answer will always be -1.
            return case1;
        if(case1==-1)
            return case0;
        return min(case0,case1);
    }
    int coinChange(vector<int>& coins, int amount) {
        return helper(coins, amount, 0, 0);
        //here 0 is the index in coins vector.
    }
};
