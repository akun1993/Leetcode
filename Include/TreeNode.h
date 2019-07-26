#ifndef __TREE_NODE_H_
#define __TREE_NODE_H_

#include <vector>
#include <deque>
#include "my_types.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    static int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int depth_left, depth_right;
        depth_left = 1 + maxDepth(root->left);
        depth_right = 1 + maxDepth(root->right);

        return depth_left > depth_right ? depth_left : depth_right;
    }

    static TreeNode *GenerateTree(std::vector<int> &val_list)
    {
        if (val_list.empty() || val_list[0] == 0)
            return nullptr;

        TreeNode *head = new TreeNode(0);

        head->val = val_list[0];

        std::deque<TreeNode *> qu;
        qu.push_back(head);

        int k = 1;
        int val_idx = 1;

        while (!qu.empty())
        {
            int next_k = 0;
            while (k > 0)
            {
                TreeNode *node = qu.front();
                qu.pop_front();
                for (u32 i = 0; val_idx + i < val_list.size() && i < 2; ++i)
                {
                    if (val_list[val_idx + i] != 0)
                    {
                        TreeNode *new_node = new TreeNode(val_list[val_idx + i]);

                        if (i == 0)
                            node->left = new_node;
                        else
                            node->right = new_node;

                        qu.push_back(new_node);
                        next_k++;
                    }
                }
                val_idx += 2;
                k--;
            }
            k = next_k;
        }
        return head;
    }
    static TreeNode *FindNodeByVal(TreeNode *root, int val)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == val)
            return root;

        TreeNode *res = FindNodeByVal(root->left, val);

        if (!res)
            res = FindNodeByVal(root->right, val);

        return res;
    }

    static bool CheckNodeIsInTree(TreeNode *root, TreeNode *node)
    {
        if (root == nullptr)
            return false;
        if (root == node)
            return false;

        bool res = CheckNodeIsInTree(root->left, node);

        if (!res)
            res = CheckNodeIsInTree(root->right, node);

        return res;
    }
};


#endif // 

