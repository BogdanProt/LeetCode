#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
   vector<string> generateParenthesis(int n)
   {
      // add open if openCount < n
      // add closing if closeCount < openCount
      // valid iif open == close == n
      vector<char> parentheses;
      vector<string> result;
      backtracking(n, 0, 0, parentheses, result);
      return result;
   }

   void backtracking(int n, int openCount, int closeCount, vector<char> &parentheses, vector<string> &result)
   {
      if (openCount == closeCount && openCount == n)
      {
         string outputStr(parentheses.begin(), parentheses.end());
         result.push_back(outputStr);
         return;
      }

      if (openCount < n)
      {
         parentheses.push_back('(');
         backtracking(n, openCount + 1, closeCount, parentheses, result);
         parentheses.pop_back();
      }

      if (closeCount < openCount)
      {
         parentheses.push_back(')');
         backtracking(n, openCount, closeCount + 1, parentheses, result);
         parentheses.pop_back();
      }
   }
};