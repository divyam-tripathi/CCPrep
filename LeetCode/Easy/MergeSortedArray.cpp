/* 

Question 88. Merge Sorted Array

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. 
You may assume that nums1 has a size equal to m + n such that 
    it has enough space to hold additional elements from nums2.

Accepted | Runtime : 0ms | Memory Usage : 9.1 MB

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p = nums1.size();
        if (p == 1 && m == 0 && nums1[0] == 0)
        {
            nums1[0] = nums2[0];
            return;
        }
        if (n < 1)
        {
            return;
        }

        p--;
        m--;
        n--;
        while (m >= 0 && n >= 0)
        {
            if (nums1[m] == nums2[n])
            {
                nums1[p] = nums2[n];
                p--;
                m--;
            }
            else if (nums1[m] > nums2[n])
            {
                nums1[p] = nums1[m];
                p--;
                m--;
            }
            else
            {
                nums1[p] = nums2[n];
                p--;
                n--;
            }
        }
        while (n >= 0)
        {
            nums1[p] = nums2[n];
            p--;
            n--;
        }
    }
};

int main()
{
    Solution s;
    vector<int> num1 = {2, 0};
    vector<int> num2 = {1};
    s.merge(num1, 1, num2, 1);

    for (auto num : num1)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}