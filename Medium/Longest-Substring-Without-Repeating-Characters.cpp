#include <set>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
   int lengthOfLongestSubstring(string s)
   {
      set<char> charSet;
      int l = 0, result = 0;

      for (int r = 0; r < s.size(); r++)
      {
         while (charSet.count(s[r]) != 0)
         { // duplicate
            charSet.erase(s[l]);
            l++;
         }
         charSet.insert(s[r]);
         result = max(result, r - l + 1);
      }

      return result;
   }
};

// We move through the string with our pointers and use a set for the substrings. When we find a duplicate, we move our left pointer until there are no duplicates in the set, insert the current element in the set, check for the size of the new substring and update the result if necessary.