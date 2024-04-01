class Solution(object):
    def groupAnagrams(self, strs):
        res = defaultdict(list)

        for s in strs:
            count = [0] * 26 # letters in the alphabet
            for char in s:
                count[ord(char) - ord('a')] += 1
            res[tuple(count)].append(s)

        return res.values()

# Iterate through each string and count the frequency of each letter. Add the string to the dictionary key that has its specific count and return the values of the dictionary.