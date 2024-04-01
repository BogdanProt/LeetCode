class Solution(object):
    def containsDuplicate(self, nums):
        hashSet = set()
        for num in nums:
            if num in hashSet:
                return True
            hashSet.add(num)
        return False

# Iterate through nums and check if the current number is already in the hashSet. If it is, return True, else keep iterating until the end. If the condition hasn't been met, return False.