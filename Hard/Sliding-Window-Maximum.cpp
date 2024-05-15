// Monotonically Decreasing Queue
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Solution
{
public:
   vector<int> maxSlidingWindow(vector<int> &nums, int k)
   {
      vector<int> result;
      int l = 0, r = 0;
      deque<int> dq; // contains indexes not numbers

      while (r < nums.size())
      {
         while (dq.size() && nums[dq.back()] < nums[r]) // pop the smaller numbers
            dq.pop_back();
         dq.push_back(r);

         if (l > dq.front()) // pop the left value from window
            dq.pop_front();

         if (r + 1 >= k) // we reached our window size k, and only then increment left pointer
         {
            result.push_back(nums[dq.front()]);
            l++;
         }

         r++;
      }
      return result;
   }
};

//