#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
   int largestRectangleArea(vector<int> &heights)
   {
      int maxArea = 0;
      int n = heights.size();
      vector<pair<int, int>> st; // index, height

      for (int i = 0; i < n; i++)
      {
         int start = i;
         while (!st.empty() && st[st.size() - 1].second > heights[i])
         {
            pair<int, int> indHei = st[st.size() - 1];
            st.pop_back();
            maxArea = max(maxArea, indHei.second * (i - indHei.first));
            start = indHei.first;
         }
         st.push_back({start, heights[i]});
      }

      /*
      When the condition is met, it means we can't extend our top of the stack
      anymore, so we pop it from the stack and compute its maxArea. Then, we update
      the starting index from the index of the last popped element.
      */

      for (int i = 0; i < st.size(); i++)
      {
         maxArea = max(maxArea, st[i].second * (n - st[i].first));
      }

      /*
      Compute maxArea for the remaining components in the stack that end up
      in ascending order.
      */
      return maxArea;
   }
};