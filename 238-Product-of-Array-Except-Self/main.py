# Time Complexity = O(N)
# Space Complexity = O(1)

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        result = [1 for i in range(len(nums))]
        
        rp = 1
        
        result[0] = rp
        
        for i in range(1, len(nums)):
            rp = rp * nums[i-1]
            result[i] = rp
            
        rp = 1
        
        for i in range(len(nums) - 2, -1, -1):
            rp = rp * nums[i+1]
            result[i] = rp * result[i]
        
        return result
         