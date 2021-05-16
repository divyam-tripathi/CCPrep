/* 

Question 53. Maximum Subarray

Given an integer array nums, 
    find the contiguous subarray (containing at least one number) 
    which has the largest sum and return its sum.

Accepted | Runtime : 4 ms | Memory usage : 13.1 MB

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int num_len = nums.size();
        if(num_len < 2) {
            return nums[num_len - 1];
        }
        int max_current;
        int max_global;
        max_current = max_global = nums[0];
        for (int i = 1; i < num_len; i++)
        {
            max_current = max(nums[i], max_current + nums[i]);
            if(max_current > max_global) {
                max_global = max_current;
            }
        }
        return max_global;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;
    vector<int> nums2 = {1};
    cout << s.maxSubArray(nums2) << endl;
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << s.maxSubArray(nums3) << endl;
    return 0;
}
