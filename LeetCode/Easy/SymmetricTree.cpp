/* 

Question 101. Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Accepted | Runtime : 4ms | Memory Usage 16.5 MB

 */

#include <iostream>
#include <vector>
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

bool checkSymmetric(vector<int> elements)
{
    int end = elements.size();
    if (!end % 2 != 0)
    {
        return false;
    }
    int halfPoint = end / 2;
    end--;
    int i = 0;
    while (i < halfPoint)
    {
        if (elements.at(i) != elements.at(end))
        {
            return false;
        }
        i++;
        end--;
    }
    return true;
}

bool isSymmetric(TreeNode *root)
{

    queue<TreeNode *> nodeQueue;

    nodeQueue.push(root);

    int p = 1;
    int c;
    vector<int> elements;
    while (!nodeQueue.empty())
    {
        c = 0;
        elements.clear();
        while (p > 0)
        {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            if (node->left != nullptr)
            {
                nodeQueue.push(node->left);
                elements.push_back(node->left->val);
                c++;
            }
            else
            {
                elements.push_back(INT16_MIN);
            }

            if (node->right != nullptr)
            {
                nodeQueue.push(node->right);
                elements.push_back(node->right->val);
                c++;
            }
            else
            {
                elements.push_back(INT16_MIN);
            }

            p--;
        }
        p = c;
        if (!elements.empty() && !checkSymmetric(elements))
        {
            return false;
        }
    }
    return true;
}

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

    vector<int> treeArr = {1, 2, 2, NULL, 3, NULL, 3};
    TreeNode *root = createBinaryTree(treeArr);
    bstTraverse(root);
    cout << endl;
    bool symmetric = isSymmetric(root);
    cout << "isSemmtric : " << symmetric;
    cout << endl;
    return 0;
}