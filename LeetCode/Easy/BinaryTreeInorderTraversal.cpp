/* 

Question 94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Accepted | Runtime : 0ms | Memory usage : 8.2 MB

 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorderArr;
        stack<TreeNode *> nodeStack;

        TreeNode *node = root;

        while (node != nullptr || !nodeStack.empty())
        {
            while (node != nullptr)
            {
                nodeStack.push(node);
                node = node->left;
            }

            node = nodeStack.top();
            nodeStack.pop();

            inorderArr.push_back(node->val);

            node = node->right;
        }
        return inorderArr;
    }
};

int main()
{
    Solution s;

    TreeNode *lNode = new TreeNode(1);
    TreeNode *rNode = new TreeNode(3);
    TreeNode *rootNode = new TreeNode(2, lNode, rNode);

    vector<int> inorderArr = s.inorderTraversal(rootNode);

    for (auto val : inorderArr)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}