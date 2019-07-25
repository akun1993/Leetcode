#include "solution_symmetric_tree_101.h"

bool SolutionSymmertic::__Symmetric(TreeNode *lnode, TreeNode *rnode)
{
    if (lnode == NULL && rnode == NULL)
        return true;

    if (!(lnode && rnode))
        return false;

    if (lnode->val != rnode->val)
        return false;

    return __Symmetric(lnode->left, rnode->right) && __Symmetric(lnode->right, rnode->left);
}

bool SolutionSymmertic::SymmetricIterator(TreeNode *root)
{
    if (root == NULL)
        return true;

    bool res = true;

    deque<TreeNode *> qu;

    if (root->left == NULL && root->right == NULL)
        return true;

    if (!(root->left && root->right))
        return false;

    qu.push_back(root->left);
    qu.push_back(root->right);

    int k = 1;

    while (!qu.empty() && res)
    {
        int next_k = 0;

        while (k > 0)
        {
            TreeNode *lnode = qu.front();
            qu.pop_front();

            TreeNode *rnode = qu.front();
            qu.pop_front();

            if (lnode->val != rnode->val)
            {
                res = false;
                break;
            }

            if ((lnode->left == NULL && rnode->right != NULL) || (lnode->left != NULL && rnode->right == NULL) || (lnode->right == NULL && rnode->left != NULL) || (lnode->right != NULL && rnode->left == NULL))
            {
                res = false;
                break;
            }

            if (lnode->left && rnode->right)
            {
                // cout << node->val << ", ";
                qu.push_back(lnode->left);
                qu.push_back(rnode->right);
                next_k++;
            }

            if (lnode->right && rnode->left)
            {
                // cout << node->val << ", ";
                qu.push_back(lnode->right);
                qu.push_back(rnode->left);
                next_k++;
            }
            k--;
        }
        //cur_depth++;
        k = next_k;
    }
    return res;
}

//是否是对称二叉树
bool SolutionSymmertic::isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;

    return __Symmetric(root->left, root->right);
}
