class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        mapT = {}
        mapS = {}
        for i in range(len(s)):
            mapS[s[i]] = 1 + mapS.get(s[i], 0)
            mapT[t[i]] = 1 + mapT.get(t[i], 0)
        for character in mapS:
            if mapS[character] != mapT.get(character, 0):
                return False
        return True

        
# First check if the lengths are equal. If true, create a Map for each string, that contains the frequencies of each character. If the frequencies are not equal for each character in s, return False.