class Solution(object):
    def twoSum(self, nums, target):
        myMap = {} # value : index
        for i, num in enumerate(nums):
            diff = target-num
            if diff in myMap:
                return [myMap[diff], i]
            myMap[num] = i
        return 

# Iterate through nums and check if the difference of the target number minus the current number is already in the map(the map holds value : index). If it is, return its index and the current index, else add the current number with its specific index to the map