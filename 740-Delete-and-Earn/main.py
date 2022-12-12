"""
 Time Complexity = O(Maximum_Element+1) or O(N)
Space Complexity = O(Maximum_Element+1)
Where N is the size of the vector nums.
"""

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        maxi = 0
        
        for num in nums:
            maxi = max(maxi, num)
        
        # List from 0 to maxi+1
        data = [0 for i in range(maxi+1)]
            
        for num in nums:
            data[num] = data[num] + num
        
        skip = 0
        take = data[0]
        
        for i in range(1, len(data)):
            previousSkip = skip
            
            # Not choose case
            skip = max(skip, take)
            
            # choose case
            take = previousSkip + data[i]
            
        
        return max(skip,take)