class Solution(object):
    def twoSum(self, nums, target):
        num_map = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_map:
                return [num_map[complement], i]
            num_map[num] = i
        return []

if __name__ == "__main__":
    sol = Solution()
    print("Test Case 1 Output:", sol.twoSum([2, 7, 11, 15], 9)) # Expected: [0, 1]
    print("Test Case 2 Output:", sol.twoSum([3, 2, 4], 6))      # Expected: [1, 2]
    print("Test Case 3 Output:", sol.twoSum([3, 3], 6))         # Expected: [0, 1]