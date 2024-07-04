#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// I used 2 stacks. The 2nd stack is used to get the minimum value in O(1). Each level of the stack will have its
// minimum value, that updates with each push/pop.
class MinStack
{
public:
   vector<int> stack;
   vector<int> minStack;
   MinStack()
   {
   }

   void push(int val)
   {
      stack.push_back(val);
      int minVal;
      if (!minStack.empty())
         minVal = min(val, minStack[minStack.size() - 1]);
      // if the minStack isn't empty, update the min value on this level
      else
         minVal = val;
      minStack.push_back(minVal);
   }

   void pop()
   {
      stack.pop_back();
      minStack.pop_back();
   }

   int top()
   {
      return stack[stack.size() - 1];
   }

   int getMin()
   {
      return minStack[minStack.size() - 1];
   }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */