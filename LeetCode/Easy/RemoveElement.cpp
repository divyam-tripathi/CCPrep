/* 

Question 27. Remove Element

Given an array nums and a value val, 
    remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, 
    you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Accepted | Runtime : 0ms | Memory usage : 8.9 MB

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.size() < 2)
        {
            if (nums.size() == 1 && nums[0] == val)
            {
                return 0;
            }

            return nums.size();
        }

        int last_i = nums.size() - 1;
        int first_i = 0;
        while (first_i < last_i)
        {
            if (nums[first_i] == val)
            {
                while (nums[last_i] == val && last_i > first_i)
                {
                    last_i--;
                }

                if (nums[last_i] != val)
                {
                    int first_i_val = nums[first_i];
                    nums[first_i] = nums[last_i];
                    nums[last_i] = first_i_val;

                    last_i--;
                    first_i++;
                }
            }
            else
            {
                first_i++;
            }
        }

        return nums[first_i] != val ? first_i + 1 : first_i;
    }
};

void checkAnswer(vector<int> nums, int val)
{
    Solution s;
    int len = s.removeElement(nums, val);
    for (int i = 0; i < len; i++)
    {
        cout << nums[i];
    }
    cout << endl;
}

int main()
{
    checkAnswer({}, 1);
    checkAnswer({1}, 1);
    checkAnswer({1, 2}, 1);
    checkAnswer({1, 2, 3}, 1);
    checkAnswer({3, 2, 2, 3}, 3);
    checkAnswer({0, 1, 2, 2, 3, 0, 4, 2}, 2);
    return 0;
}
