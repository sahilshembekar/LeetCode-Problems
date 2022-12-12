# Time Complexity: O(n); n is the size of the nums list
# Space Complexity: O(1)

# Creates a list containing 5 lists, each of 8 items, all set to 0
# w, h = 8, 5
# Matrix = [[0 for x in range(w)] for y in range(h)] 

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        skip = 0
        take = nums[0]
        
        for i in range(1, len(nums)):
            
            previousSkip = skip
            
            # Not choose case
            skip = max(skip, take)
            
            # Choose case
            take = previousSkip + nums[i]
            
        return max(skip,take)
        
        