#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
   int maxArea(vector<int> &height)
   {
      int l = 0, r = height.size() - 1;
      int result = 0;

      while (l < r)
      {
         int area = (r - l) * min(height[l], height[r]);
         result = max(result, area);

         if (height[l] < height[r])
            l++;
         else
            r--;
      }
      return result;
   }
};

// Left pointer and right pointer. Calculate the area of each step and update the result. Updating the pointers depend on which height is bigger, because we want to keep the bigger height. If the heights are equal, it doesn't matter which pointer we update.