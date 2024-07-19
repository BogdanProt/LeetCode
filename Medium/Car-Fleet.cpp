#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
   int carFleet(int target, vector<int> &position, vector<int> &speed)
   {
      int n = position.size();
      vector<pair<int, double>> calcTimes;
      for (int i = 0; i < n; i++)
      {
         // time of arrival = (target - position) / speed
         double time = double(target - position[i]) / (double)speed[i];
         calcTimes.push_back({position[i], time});
      }

      sort(calcTimes.begin(), calcTimes.end());
      vector<double> cars;

      // sort cars by time of arrival and iterate backwards
      for (int i = n - 1; i >= 0; i--)
      {
         cars.push_back(calcTimes[i].second);
         if (cars.size() >= 2 && cars[cars.size() - 1] <= cars[cars.size() - 2])
            cars.pop_back();
      }

      return cars.size();
   }
};