/* 

Question 26. Remove Duplicates from Sorted Array

Given a sorted array nums, 
 remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, 
 you must do this by modifying the input array in-place with O(1) extra memory.

Accepted | Runtime : 136ms | Memory Usage : 13.6 MB

 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        if(nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1)
        {
            return 1;
        }

        auto itr = nums.begin()++;
        int i = 1;
        while (i < nums.size())
        {
            if (nums[i] == nums[i - 1])
            {
                nums.erase(itr);
            }
            else
            {
                i++;
                itr++;
            }
        }

        return nums.size();
    }
};

void test(vector<int> nums)
{
    Solution s;
    int len = s.removeDuplicates(nums);
    for (auto itr = nums.begin(); itr < nums.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

int main()
{
    test({1, 1, 2});
    test({5, 5, 10, 10, 10, 20, 20, 30, 30, 40});
    return 0;
}