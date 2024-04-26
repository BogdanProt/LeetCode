#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
   bool checkInclusion(string s1, string s2)
   {
      int matches = 0;
      if (s1.size() > s2.size())
         return false;
      vector<int> s1Freq(26), s2Freq(26);

      for (int i = 0; i < s1.size(); i++)
      {
         s1Freq[(int)s1[i] - 'a']++;
         s2Freq[(int)s2[i] - 'a']++;
      }
      // put each letter on corresponding position in array
      for (int i = 0; i < 26; i++)
      {
         if (s1Freq[i] == s2Freq[i])
            matches++;
      }
      // calculate the number of letters matching in the first window (s1 sized)
      // for each missing letter, we subtract 1 from 26 basically
      // given the example s1 = "ab" and s2 = "eidbaooo", we start off with 22 matches (a, b, e, i don't match)
      int l = 0;
      for (int r = s1.size(); r < s2.size(); r++)
      {
         if (matches == 26)
            return true;

         int index = (int)s2[r] - 'a';
         s2Freq[index]++;
         if (s1Freq[index] == s2Freq[index])
            matches++;
         else if (s1Freq[index] + 1 == s2Freq[index])
            matches--;

         // add the new char

         index = (int)s2[l] - 'a';
         s2Freq[index]--;
         if (s1Freq[index] == s2Freq[index])
            matches++;
         else if (s1Freq[index] - 1 == s2Freq[index])
            matches--;

         // remove the first char
         // now we have a window of size s1.size() again

         l++;
      }
      return matches == 26;
   }
};

// Iterate through s2 in substrings of s1 size, and check for matches. We have to find perfect matches (26) for the permutation
// string to equal the current substring. For each missing letter that doesn't have a match, we decrement 1.