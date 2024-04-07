class Solution(object):
    def longestConsecutive(self, nums):
        numSet = set(nums)
        longest = 0

        for n in nums:
            #Check if it has a left neighbour (if n-1 exists)
            if (n-1) not in numSet:
                length=0
                while (n + length) in numSet:
                    length += 1
                longest = max(length, longest)
        return longest

# Firstly, I transform the array into a set, then I check for each number if it has a left neighbour, and if it doesn't then it is a start of a new sequence. If it is a new sequence, keep checking if the numbers that come consecutively are in the set and increase the length of the sequence.