# Time Complexity: O(m); no. of houses= m
# Space Complexity: O(n); -> No of rows

class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        
        dp = [[0 for j in range (3)] for i in range (len(costs))]
        
        for j in range (3):
            dp[len(costs) - 1][j] = costs[len(costs) - 1][j]
           
        # Method for looping backwards takes a 3rd parameter in python
        for i in range(len(costs)-2, -1, -1):
            dp[i][0] = costs[i][0] + min(dp[i + 1][1], dp[i + 1][2])
            dp[i][1] = costs[i][1] + min(dp[i + 1][0], dp[i + 1][2])
            dp[i][2] = costs[i][2] + min(dp[i + 1][0], dp[i + 1][1])
        
        
        return min(dp[0][0], dp[0][1], dp[0][2])
        