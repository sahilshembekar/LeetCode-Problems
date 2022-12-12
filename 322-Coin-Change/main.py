# Time Complexity: O(m*n)
# Space Complexity: O(m*n)
# m = no. of coins
# n = total amount

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        if len(coins) == 0 or coins is None:
            return 0
        
        m = len(coins)
        n = amount
        
        # Creates a list containing with initial values as 0
        dp = [[0 for i in range(n+1)] for j in range(m+1)] 
        
        # Fill the top dummy row with infinity i.e. value> amount
        for j in range(1,len(dp[0])):
            dp[0][j] = amount+1
        
        for i in range(1,len(dp)):
            for j in range(1, len(dp[0])):
                
                # Traverse the matrix
                
                if j < coins[i-1]:
                    """
                    We have not reached the amount equal to denomination of coin
                    Take the value from the upper box
                    """
                    dp[i][j] = dp[i-1][j]
                
                else:
                    """
                    Use the min of 1 and 2
                    1 = value from the row above 
                    2 = 1 + the value from location of that element - the actual value (denomination) of the coin
                    """
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]])
                    
                
        if dp[m][n] > amount:
            return -1
        
        else:
            return dp[m][n]
                
            
            
        