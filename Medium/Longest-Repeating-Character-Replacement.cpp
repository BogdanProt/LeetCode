#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
// Either use a hash map for frequencies or a variable maxF that holds the maximum
// frequency.

/* HASH MAP SOLUTION
class Solution
{
public:
   int maxFrequencyMap(unordered_map<char, int> freq)
   {
      int maximum = -1;

      for (const auto &i : freq)
      {
         if (i.second > maximum)
         {
            maximum = i.second;
         }
      }
      return maximum;
   }

   int characterReplacement(string s, int k)
   {
      unordered_map<char, int> freqMap;
      int result = 0, l = 0;

      for (int r = 0; r < s.size(); r++)
      {
         if (!freqMap[s[r]])
            freqMap[s[r]] = 0;
         freqMap[s[r]]++;
         while ((r - l + 1) - maxFrequencyMap(freqMap) > k)
         {
            freqMap[s[l]]--;
            l++;
         }
         result = max(result, r - l + 1);
      }
      return result;
   }
};
*/

/*
We use a hash map for the frequencies of each character, and check if the length of the current window - the maximum
frequency in the hashmap is bigger than k. If it is, our window is not valid, because it needs to be < than k. We then
decrement it from the frequency and move our left pointer. Only update result if we find a valid window.
*/

// Variable solution maxF
class Solution
{
public:
   int characterReplacement(string s, int k)
   {
      unordered_map<char, int> freqMap;
      int result = 0, l = 0, maxF = 0;

      for (int r = 0; r < s.size(); r++)
      {
         if (!freqMap[s[r]])
            freqMap[s[r]] = 0;
         freqMap[s[r]]++;
         maxF = max(maxF, freqMap[s[r]]);
         while ((r - l + 1) - maxF > k)
         {
            freqMap[s[l]]--;
            l++;
         }
         result = max(result, r - l + 1);
      }
      return result;
   }
};

/*
We don't need to update the frequency each time, because we only care when it is at its maximum value. If we find a new
maximum value, then the result updates as well.
*/