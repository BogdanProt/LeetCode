class Solution:

   def encode(self, strs):
      result = ""
      for s in strs:
         result+= str(len(s)) + "#" + s
      
      return result

   def decode(self, str):
      result = []
      i = 0

      while i < len(str):
         j = i # The length of the first word starts at position i
         while str[j] != "#":
            j+=1
         # Check where the length of the words ends, because it can be a longer integer
         length = int(str[i:j])
         result.append(str[j+1 : j+1+length]) # Passing over the "#" sign
         i = j + 1 + length
      
      return result
         

# Encode the string by the following rule: "[LEN][#]STRING", having the length of the first string go first, then a delimiter, and only then the string. This way, we are able to decode it very easily by first finding out the length and then appending the following string to the final list.