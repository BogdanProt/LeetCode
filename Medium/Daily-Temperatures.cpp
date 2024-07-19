#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
   vector<int> dailyTemperatures(vector<int> &temperatures)
   {
      vector<int> answer(temperatures.size(), 0);
      stack<int> tempsIndex; // stack for indeces

      for (int i = 0; i < temperatures.size(); i++)
      {
         while (!tempsIndex.empty() && temperatures[tempsIndex.top()] < temperatures[i])
         {
            /*
            while the stack is not empty and we find a temperature greater than the top of our stack,
            update the answer with the difference of indeces and pop
            */
            answer[tempsIndex.top()] = i - tempsIndex.top();
            tempsIndex.pop();
         }
         tempsIndex.push(i); // push each temperature on the stack
      }

      return answer;
   }
};