#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
   int trap(vector<int> &height)
   {
      if (height.size() == 0)
         return 0;
      int l = 0, r = height.size() - 1;
      int lMax = height[l], rMax = height[r], total = 0;

      while (l < r)
      {
         if (lMax < rMax)
         {
            l++;
            lMax = max(lMax, height[l]);
            total += lMax - height[l];
         }
         else
         {
            r--;
            rMax = max(rMax, height[r]);
            total += rMax - height[r];
         }
      }

      return total;
   }
};

// Use pointers to save the maximum height to the left of the current element and maximum height to the right.
// For each element, we use left/rightMax - height[l/r] and add it to the total. That is how we check how much water can be trapped in O(1) space, O(n) time.