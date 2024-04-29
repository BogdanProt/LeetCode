#include <string>
#include <map>
#include <climits>
using namespace std;

class Solution
{
public:
   string minWindow(string s, string t)
   {
      if (t == "")
         return "";

      map<char, int> countT, window;

      for (auto c : t)
         countT[c]++;

      int have = 0, need = countT.size();
      pair<int, int> res = {-1, -1};
      int resLength = INT_MAX;
      int l = 0;
      for (int r = 0; r < s.size(); r++)
      {
         char c = s[r];
         window[c]++;

         if (countT[c] && window[c] == countT[c])
            have++;

         while (have == need)
         {
            if (r - l + 1 < resLength)
            {
               res = {l, r};
               resLength = r - l + 1;
            }
            // minimize our window
            window[s[l]]--;
            if (countT[s[l]] && window[s[l]] < countT[s[l]])
               have--;
            l++;
         }
      }
      if (resLength == INT_MAX)
         return "";
      else
         return s.substr(res.first, resLength);
   }
};

/*
We keep a hashMap for t that holds the count of each character. We iterate through s and update the hashMap of our current
window. If the counts of 2 chars are equal, increment the have variable, and keep updating the length and borders of the window until we get to
a character that breaks our counts.
*/