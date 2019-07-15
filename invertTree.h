#ifndef __INVERT_TREE_H_
#define __INVERT_TREE_H_

#include "TreeNode.h"
#include <deque>

/* 翻转一棵二叉树。

// 示例：

// 输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
// 输出：

      4
     /  \
   7     2
  / \   / \
 9   6 3   1
*/
class SolutionInvertTree {
public:
    TreeNode* invertTreeI(TreeNode* root) {
        if(root == NULL) return root;

        TreeNode *node = root->left;

        root->left = root->right;

        root->right = node;

        if(root->left) invertTreeI(root->left);

        if(root->right) invertTreeI(root->right);

        return root;
    }

    TreeNode* invertTreeII(TreeNode* root) 
    {
        if(root == NULL) return root;

        deque<TreeNode*> record;
        
        record.push_back(root);
        int k = 1;

        while (!record.empty())
        {
            /* code */
            deque<TreeNode*>::iterator iter;
            int next_k = 0;
            while (k-- > 0)
            {
                /* code */
                TreeNode* node =  record.front();

                TreeNode *tmp = node->left;
                node->left = node->right;
                node->right = tmp;

                if(node->left) { record.push_back(node->left); ++next_k;}
                if(node->right) { record.push_back(node->right); ++next_k;}

                record.pop_front();
            }
            k = next_k;
        }
        


        return root;

    }

    void answer()
    {

    }
};

#endif
