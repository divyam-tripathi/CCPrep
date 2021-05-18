/* 

Question 83. Remove Duplicates from Sorted Linked List

Given the head of a sorted linked list, 
    delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

Accepted | Runtime : 4ms | Memory Usage : 12.3 MB

 */

#include <iostream>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    map<int, int> num_count_map;

public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *node = head;
        ListNode *prev;
        do
        {
            num_count_map[node->val]++;

            if (node->next != nullptr)
            {
                if (num_count_map[node->val] > 1)
                {
                    prev->next = node->next;
                }
                else
                {
                    prev = node;
                }
                node = node->next;
                if (node->next == nullptr && (num_count_map[node->val] + 1) > 1)
                {
                    prev->next = nullptr;
                }
            }
        } while (node->next != nullptr);

        return head;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *prev;
    int nums[9] = {1, 2, 2, 3, 3, 4, 4, 5, 5};
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        ListNode *node = new ListNode(nums[i]);
        if (i == 0)
        {
            head->next = node;
            prev = node;
            continue;
        }
        prev->next = node;
        prev = node;
    }

    ListNode *node = s.deleteDuplicates(head);
    do
    {
        cout << node->val << " ";
        if (node->next != nullptr)
        {
            node = node->next;
            if (node->next == nullptr)
            {
                cout << node->val << endl;
            }
        }
    } while (node->next != nullptr);
    cout << endl;
    return 0;
}