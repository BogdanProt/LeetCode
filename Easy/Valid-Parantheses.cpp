#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
   bool isValid(string s)
   {
      stack<char> st;
      unordered_map<char, char> paranteze = {
          {')', '('},
          {']', '['},
          {'}', '{'}};

      for (char c : s)
      {
         if (paranteze[c])
         {
            if (!st.empty() && st.top() == paranteze[c])
            {
               st.pop();
            }
            else
            {
               return false;
            }
         }
         else
            st.push(c);
      }

      if (!st.empty())
         return false;
      return true;
   }
};

/*
I use the stack only for the opening parentheses, and when the current character is a closing parentheses,
I check whether or not it corresponds to the top of the stack. If it does, then it is a good iteration and I pop
the top element from the stack. For every other case, it is invalid.
*/