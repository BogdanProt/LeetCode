class Solution(object):
    def productExceptSelf(self, nums):
        answer = [1] * len(nums)
        prefix = 1
        for i in range(len(nums)):
            answer[i] = prefix
            prefix *= nums[i]
        postfix = 1
        for i in range(len(nums)-1, -1, -1):
            answer[i] *= postfix
            postfix *= nums[i]
        return answer
    

# Done in O(n) time. First add the prefixes to the answer list (the prefix is the product of all numbers to the left of the current number). Then iterate through nums in descending order and multiply the value of the current answer[i] with the postfix (the postfix is the product of all numbers to the right of the current number)