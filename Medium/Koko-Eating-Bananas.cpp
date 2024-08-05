#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
   int minEatingSpeed(vector<int> &piles, int h)
   {
      int l = 1, r = *max_element(piles.begin(), piles.end());
      int result = r;

      while (l <= r)
      {
         int k = (l + r) / 2;
         long long hours = 0;
         for (int p : piles)
         {
            double aux = (p + 0.0) / k; // ceil works weird
            hours += ceil(aux);         // hours it took us to eat the pile
         }

         if (hours <= h)
         {
            result = min(result, k);
            r = k - 1;
         }
         else
         {
            l = k + 1;
         }
      }
      return result;
   }
};

/*
Iterate through and compute binary search from 0...max(piles).
If the middle finishes the piles, remove rights side.
If the middle doesn't finish the piles, remove left side.
*/