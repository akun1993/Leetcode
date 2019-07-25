#include "solution_lowest_common_ancestor_236.h"
#include <stddef.h>

TreeNode *SolutionLowestCommonAncestor::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (NULL == q && p == NULL)
        return NULL;
    if (root == q || p == root)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right == NULL)
    {
        return left;
    }

    if (left == NULL && right != NULL)
    {
        return right;
    }

    if (left != NULL && right != NULL)
    {
        return root;
    }
    return NULL;
}

TreeNode *SolutionLowestCommonAncestor::lowestCommonAncestorII(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    TreeNode *ret = NULL;

    deque<TreeNode *> qu;
    qu.push_back(root);

    int k = 1;

    // int cur_depth = 0;

    while (!qu.empty())
    {
        int next_k = 0;

        while (k > 0)
        {
            TreeNode *node = qu.front();
            qu.pop_front();

            if (node)
            {
                // cout << node->val << ", ";

                bool res = TreeNode::CheckNodeIsInTree(node, p);

                if (res)
                    res = TreeNode::CheckNodeIsInTree(node, q);

                if (res)
                {
                    ret = node;
                }

                if (node->left != NULL)
                {
                    qu.push_back(node->left);
                    next_k++;
                }

                if (node->right != NULL)
                {
                    qu.push_back(node->right);
                    next_k++;
                }
            }

            k--;
        }
        //cur_depth++;
        k = next_k;
    }
    return ret;
}

void SolutionLowestCommonAncestor::answer()
{

}
