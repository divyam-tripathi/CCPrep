/* 

Question 20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order. 

Accepted | Runtime : 0ms | Memory 6.4 MB

*/

#include<iostream>
#include<stack>
#include<map>

using namespace std;

class Solution {
    map<char, char> brackets_map = {
        {'}', '{'},
        {']', '['},
        {')', '('}
    }; 
public:
    bool isValid(string s) {
        if(s.empty() || isEndBracket(s.at(0))) {
            return false;
        }
        stack<char> s_stack;
        for(char s_char : s) {
            if(!isEndBracket(s_char) || s_stack.empty()) {
                s_stack.push(s_char);
            } else {
                if(s_stack.top() == brackets_map[s_char]) {
                        s_stack.pop();
                } else {
                    return false;
                }
            }
        }
        if(s_stack.empty()) {
            return true;
        }
        return false; 
    }

    bool isEndBracket(char c) {
        return c == '}' || c == ']' || c == ')' ;
    }
};

int main()
{
    Solution sol;
    cout << sol.isValid("(){}}{") << endl;
    return 0;
}
