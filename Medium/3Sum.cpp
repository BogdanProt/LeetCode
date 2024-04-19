#include <vector>
using namespace std;

class Solution
{
public:
   vector<vector<int>> threeSum(vector<int> &nums)
   {
      sort(nums.begin(), nums.end());
      vector<vector<int>> answer;
      for (int i = 0; i < nums.size(); i++)
      {
         if (i > 0 && nums[i] == nums[i - 1])
            continue;

         int l = i + 1;
         int r = nums.size() - 1;

         while (l < r)
         {
            int currentSum = nums[i] + nums[l] + nums[r];
            if (currentSum > 0)
               r--;
            else if (currentSum < 0)
               l++;
            else // they are equal
            {

               answer.push_back({nums[i], nums[l], nums[r]});
               l++;
               while (nums[l] == nums[l - 1] && l < r) // skip the duplicates in the sorted array
               {
                  l++;
               }
            }
         }
      }
      return answer;
   }
};

// A combination of solutions between two-sum and two-sum-2 (two pointers). Sort the array at first and then check for duplicates. After that, start the two pointers solution in which we only need to update 1 pointer at the end, as the other will update itself.