# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        result = list()
        
        for i in range(0, len(nums)):
            idx = abs(nums[i]) - 1
            if nums[idx] > 0:
                nums[idx] = nums[idx] * (-1)
             
        for i in range(0, len(nums)):
             if nums[i] < 0:
                nums[i] = nums[i] * (-1)
             
             else :
                result.append(i+1)
             
        return result
        