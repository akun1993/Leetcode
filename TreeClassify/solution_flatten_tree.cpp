
#include "solution_flatten_tree.h"

void SolutionFlatten::flatten(TreeNode *root)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        TreeNode *right = root->right;

        root->right = root->left;
        root->left = NULL;

        TreeNode *tmp = root;
        while (tmp->right)
            tmp = tmp->right;

        tmp->right = right;
    }
    flatten(root->right);
}

void SolutionFlatten::answer()
{
    
}
