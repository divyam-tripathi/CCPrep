/* 

Binary Tree Breadth First Traversal

 */

#include <iostream>
#include <queue>
#include <vector>

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

void bstTraverse(TreeNode *root)
{

    queue<TreeNode *> nodeQueue;

    nodeQueue.push(root);

    int p = 1;
    int c;
    while (!nodeQueue.empty())
    {
        c = 0;
        while (p > 0)
        {
            TreeNode *node = nodeQueue.front();
            cout << node->val << " ";
            nodeQueue.pop();

            if (node->left != nullptr)
            {
                nodeQueue.push(node->left);
                c++;
            }

            if (node->right != nullptr)
            {
                nodeQueue.push(node->right);
                c++;
            }

            p--;
        }
        p = c;
    }
}

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

    vector<int> treeArr = {
        45,
        26,
        82,
        2,
        NULL,
        68,
        88,
        NULL,
        3,
        58,
        79,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        70,
        NULL,
        NULL,
        NULL,
    };

    TreeNode *root = createBinaryTree(treeArr);
    bstTraverse(root);
    cout << endl;
    return 0;
}