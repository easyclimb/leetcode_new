#include<string>
#include<unordered_map>
#include<vector>
#include<iostream>

using namespace std;

/*
 * edge case: 
 * 1. " "
 *
 * test cases:
 * 2. "dvdf"
 * 3. "bbb"
 * 4. "abcabcbb"
 * 5. "pwwkew"
 * 6. "abba"
 */

class Solution {
public:
  int lengthOfLongestSubstring_wrong_answer(string s) {
    if(s.empty()) return 0;
    unordered_map<char, int> record;
    vector<int> dp(s.size());
    dp[0] = 1;
    record.insert(make_pair(s[0], 0));
    int max = 1;
    for(unsigned i = 1; i < s.size(); i++) {
      if(record.find(s[i]) != record.end()) {
        dp[i] = i - record.at(s[i]);
        record.clear();
        record[s[i]] = i;
      }
      else {
        dp[i] = dp[i-1] + 1;
        record.insert(make_pair(s[i], i));
      }
      if(dp[i] > max)
        max = dp[i];
    }
    return max;
  } 

  /*
   * the above one is wrong answer
   * The correct one is using double-pointers
   */

  int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    vector<bool> record(256, false);
    for(unsigned start = 0, end = 0; end < s.size(); end++) {
      while(start <= end && record[s[end]]) {
        record[s[start++]] = false;
      }
      record[s[end]] = true;
      int len = end - start + 1;
      if(len > maxLen) maxLen = len;
    }
    return maxLen;
  }
};

int main()
{
  string str("abcabcbb");
  Solution s;
  cout << s.lengthOfLongestSubstring(str) << endl;
  return 0;
}
