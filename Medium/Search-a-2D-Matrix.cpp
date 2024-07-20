#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   bool searchMatrix(vector<vector<int>> &matrix, int target)
   {
      int rows = matrix.size(), cols = matrix[0].size();
      int l = 0, r = rows - 1, row;
      while (l <= r) // binary search to find the row
      {
         int mid = l + ((r - l) / 2);
         if (target > matrix[mid][cols - 1])
            l = mid + 1;
         else if (target < matrix[mid][0])
            r = mid - 1;
         else
         {
            row = mid;
            break;
         }
      }

      l = 0, r = cols - 1;
      while (l <= r) // binary search to find the element
      {
         int mid = l + ((r - l) / 2);
         if (target > matrix[row][mid])
            l = mid + 1;
         else if (target < matrix[row][mid])
            r = mid - 1;
         else
            return true;
      }
      return false;
   }
};