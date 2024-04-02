class Solution(object):
    def topKFrequent(self, nums, k):
        count = {}
        freq = [[] for i in range(len(nums) + 1)]

        for num in nums:
            count[num] = 1 + count.get(num, 0)
        for num, c in count.items(): # each key : value pair
            freq[c].append(num) # the value num appears c number of times
        
        res = []
        for i in range(len(freq) - 1, 0, -1):
            for num in freq[i]: # iterate through each value that has i number of appearences
                res.append(num)
                if len(res) == k:
                    return res


# For each i in freq, freq[i] holds a list of all the numbers that appear i times. I then iterate through it in descending order and return the result when the condition has been met
        
        