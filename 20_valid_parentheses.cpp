#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {   
        stack<char> stk;
        for(uint i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] =='[') stk.push(s[i]);
            else {
                if(!stk.empty()) {
                    if(stk.top() == '(' && s[i] == ')') stk.pop();
                    else if (stk.top() == '{' && s[i] == '}') stk.pop();
                    else if (stk.top() == '[' && s[i] == ']') stk.pop();
                }
                else return false;
            }
        }
        return stk.empty();
    }
};

int main()
{
    string s = "(])";
    Solution solution;
    cout << solution.isValid(s) << endl;
    return 0;
}
