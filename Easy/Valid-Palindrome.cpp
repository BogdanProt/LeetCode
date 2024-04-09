#include <string>
#include <cctype>
using namespace std;
class Solution
{
public:
   bool isPalindrome(string s)
   {
      int start = 0, end = s.size() - 1;
      while (start <= end)
      {
         if (!isalnum(s[start]))
         {
            start++;
            continue;
         }
         if (!isalnum(s[end]))
         {
            end--;
            continue;
         }
         if (tolower(s[start]) != tolower(s[end]))
            return false;
         else
         {
            start++;
            end--;
         }
      }
      return true;
   }
};

// Two pointer problem. Start with a pointer from the beginning of the string, and the other from the end. Check if either of them is not alpha numberical, and increment/decrement the start/end based on which one meets the condition.
// If both of them are, check if they are different. If yes, return false, else move both pointers.