#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
   int maxProfit(vector<int> &prices)
   {
      int l = 0, r = 1, maxProfit = 0;
      while (r < prices.size())
      {
         if (prices[l] < prices[r])
         {
            int profit = prices[r] - prices[l];
            maxProfit = max(profit, maxProfit);
         } // profit
         else
         {
            l = r;
         }
         r++;
      }
      return maxProfit;
   }
};

// We use two pointers for this problem. First check if the trade is profitable, and update the maxProfit if possible. The right pointer start 1 position in front of the left pointer and keeps going further until the loop ends, or we find a value smaller than the left pointer, in which case we update the left pointer to that value.