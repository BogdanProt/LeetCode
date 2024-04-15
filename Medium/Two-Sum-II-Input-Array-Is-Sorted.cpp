#include <vector>
using namespace std;

class Solution
{
public:
   vector<int> twoSum(vector<int> &numbers, int target)
   {
      int l = 0, r = numbers.size() - 1;
      vector<int> answer;
      while (l < r)
      {
         int numSum = numbers[l] + numbers[r];
         if (numSum > target)
         {
            r--;
         }
         else if (numSum < target)
         {
            l++;
         }
         else
         {
            answer.push_back(l + 1);
            answer.push_back(r + 1);
            return answer;
         }
      }
      return answer;
   }
};

// Two pointers problem. If the sum of the current 2 numbers is greater than target, we need to decrease the right pointer (so that the sum gets smaller). If the sum is smaller, we need to increase the left pointer (so that the sum get bigger).