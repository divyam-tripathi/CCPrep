/* 

Question 35. Search Insert Position

Given a sorted array of distinct integers and a target value, 
    return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Accepted | Runtime : 4ms | Memory Usage 9.7 MB

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        int len = nums.size();
        int high = len;
        int low = 0;
        int mid = -1;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if (mid >= len)
            {
                return high;
            }
            else if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 5};
    cout << "Position to insert : " << s.searchInsert({nums}, 4) << endl;
    return 0;
}
