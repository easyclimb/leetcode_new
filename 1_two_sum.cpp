#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * c++ STL container's usage
 */
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    unordered_map<int, int> record;
    for(unsigned int i = 0; i < nums.size(); i++) {
      int rest = target - nums[i];
      if(record.find(rest) != record.end()) {
        ret.push_back(record[rest]);
        ret.push_back(i);
      }
      else
        record.insert(make_pair(nums[i], i));
    }
    return ret;
  }
};

int main()
{
  vector<int> nums(2, 7, 11, 15);

  return 0;
}
