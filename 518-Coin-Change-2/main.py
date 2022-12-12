# Time complexity: O(m*n)
# Space complexity:O(m*n)
# m is the length of coins
# n is the amount

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        rows = len(coins) + 1
        columns = amount + 1
        
        dp = [[0 for j in range(amount + 1)] for i in range(len(coins) + 1)]
        
        for i in range(len(dp)):
            dp[i][0] = 1
            
        for i in range(1,len(dp)):
            for j in range(1,len(dp[0])):
                
                if j < coins[i-1]:
                    # till we have not reached the denomination of the coin
                    dp[i][j] = dp[i-1][j]
                    
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]
        
        return dp[len(dp) - 1][len(dp[0]) - 1]