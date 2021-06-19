/* 

Question 100. Same Tree

Given the roots of two binary trees p and q, 
    write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, 
    and the nodes have the same value.

Accepted | Runtime : 4ms | Memory Usage : 10.3 MB

 */

#include <iostream>
#include <queue>

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
    bool checkBaseCondition(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p != nullptr && q == nullptr)
        {
            return false;
        }
        else if (p == nullptr && q != nullptr)
        {
            return false;
        }
        else if (p->val != q->val)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        if (!checkBaseCondition(p, q))
        {
            return false;
        }

        queue<TreeNode *> nodeQueue1;
        queue<TreeNode *> nodeQueue2;

        nodeQueue1.push(p);
        nodeQueue2.push(q);

        int p1, p2;
        p1 = p2 = 1;
        int c1, c2;

        while (!nodeQueue1.empty() || !nodeQueue2.empty())
        {
            c1 = 0;
            c2 = 0;
            if (p1 != p2)
            {
                return false;
            }
            while (p1 > 0 && p2 > 0)
            {
                TreeNode *node1 = nodeQueue1.front();
                TreeNode *node2 = nodeQueue2.front();
                if (node1->val != node2->val)
                {
                    return false;
                }
                nodeQueue1.pop();
                nodeQueue2.pop();

                if (!checkBaseCondition(node1->left, node2->left) ||
                    !checkBaseCondition(node1->right, node2->right))
                {
                    return false;
                }

                if (node1->left != nullptr)
                {
                    nodeQueue1.push(node1->left);
                    c1++;
                }
                if (node1->right != nullptr)
                {
                    nodeQueue1.push(node1->right);
                    c1++;
                }

                if (node2->left != nullptr)
                {
                    nodeQueue2.push(node2->left);
                    c2++;
                }
                if (node2->right != nullptr)
                {
                    nodeQueue2.push(node2->right);
                    c2++;
                }

                p1--;
                p2--;
            }
            p1 = c1;
            p2 = c2;
        }

        return true;
    }
};

TreeNode *createBinaryTree(vector<int> treeArr)
{
    TreeNode *root = new TreeNode(treeArr[0]);
    queue<TreeNode *> nodeQueue;

    nodeQueue.push(root);

    int arrLen = treeArr.size() - 1;

    int i = 0;
    while (true)
    {
        int c = (i * 2) + 1;
        if (c > arrLen)
        {
            break;
        }

        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (node != nullptr)
        {
            TreeNode *lNode = new TreeNode(treeArr[c]);
            TreeNode *rNode = new TreeNode(treeArr[c + 1]);

            node->left = lNode;
            node->right = rNode;

            nodeQueue.push(lNode);
            nodeQueue.push(rNode);
        }

        i++;
    }

    return root;
}

int main()
{
    Solution s;

    TreeNode *tree1 = createBinaryTree({1, 2, 1});
    TreeNode *tree2 = createBinaryTree({1, 1, 2});

    cout << s.isSameTree(tree1, tree2) << endl;

    return 0;
}