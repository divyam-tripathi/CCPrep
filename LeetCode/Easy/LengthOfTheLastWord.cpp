/* 

Question 58. Length of Last Word

Given a string s consists of some words separated by spaces, 
    return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

Accepted | Runtime : 0ms | Memory Usage : 6.5MB

 */

#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = s.length();
        if (len < 1)
        {
            return len;
        }
        int lastWordStartIndex = 0;
        int lastWordEndIndex = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (lastWordStartIndex != 0 && lastWordEndIndex != 0)
            {
                break;
            }
            else
            {
                if (lastWordStartIndex == 0 && s.at(i) != ' ')
                {
                    lastWordStartIndex = i + 1;
                }
                if ((lastWordEndIndex == 0 && lastWordStartIndex != 0) && s.at(i) == ' ')
                {
                    lastWordEndIndex = i + 1;
                }
            }
        }
        return (lastWordStartIndex - lastWordEndIndex);
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLastWord("Hello World") << endl;
    cout << s.lengthOfLastWord("Hello World ") << endl;
    cout << s.lengthOfLastWord("H") << endl;
    cout << s.lengthOfLastWord(" ") << endl;
    cout << s.lengthOfLastWord("") << endl;
    return 0;
}