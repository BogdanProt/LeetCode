#include <vector>
#include <stack>
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution
{
public:
   int evalRPN(vector<string> &tokens)
   {
      stack<int> nums;
      for (auto c : tokens)
      {
         if (c == "+")
         {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            nums.push(num1 + num2);
         }
         else if (c == "-")
         {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            nums.push(num2 - num1);
         }
         else if (c == "/")
         {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            nums.push(num2 / num1);
         }
         else if (c == "*")
         {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            nums.push(num1 * num2);
         }
         else
         {
            nums.push(stoi(c));
         }
      }
      return nums.top();
   }
};

/*
Iterate through the tokens. If we have a number, push it to the stack. Whenever we get an operator, pop the last 2 values
, apply the operator on them and push the result back to the stack.
*/