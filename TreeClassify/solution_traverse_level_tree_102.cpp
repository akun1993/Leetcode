
#include "solution_traverse_level_tree_102.h"
#include <iostream>

void SolutionTraverseLevelTree::TranslevelII(TreeNode *root)
{
    if (root == NULL)
        return;

    int max_depth = TreeNode::maxDepth(root);

    int max_cnt = pow(2, max_depth + 1);

    deque<Record_s> qu;
    qu.push_back(Record_s(root, 1, max_cnt / 2));

    int k = 1;
    int null_cnt = 0;
    int cur_depth = 0;

    while (!qu.empty() && null_cnt != (int)qu.size())
    {
        int next_k = 0;

        null_cnt = 0;

        int out_idx = 0;

        bool is_left = true;

        while (k > 0)
        {
            Record_s record = qu.front();
            qu.pop_front();
            int idx = record.idx;

            int real_idx;
            int parent_pos = record.pos;

            if (cur_depth != 0)
            {
                if (is_left)
                    real_idx = parent_pos - max_depth + cur_depth;
                else
                    real_idx = parent_pos + max_depth - cur_depth;
                is_left = !is_left;
            }
            else
            {
                real_idx = parent_pos;
            }

            real_idx = real_idx < out_idx ? out_idx : real_idx;
            // cout << "idx and  real_idx " << idx <<"," << real_idx << endl;

            //cout << "mid and  real_idx  and  max_cnt " << mid <<","  << real_idx  <<"," << max_cnt << endl;
            for (int i = out_idx; i < max_cnt; ++i)
            {
                if (i == real_idx)
                {
                    if (record.node)
                    {
                        TreeNode *node = record.node;
                        cout << node->val;

                        qu.push_back(Record_s(node->left, 2 * idx - 1, i));
                        next_k++;
                        qu.push_back(Record_s(node->right, 2 * idx, i));
                        next_k++;

                        if (node->left == NULL)
                            null_cnt++;
                        if (node->right == NULL)
                            null_cnt++;
                    }
                    else
                    {
                        cout << "N";
                    }
                    out_idx++;
                    //cout <<"  " ;
                    break;
                }
                else
                {
                    out_idx++;
                    cout << "  ";
                }
            }
            k--;
        }
        cout << endl
             << endl;
        cur_depth++;
        k = next_k;
    }
    return;
}

void SolutionTraverseLevelTree::Translevel(TreeNode *root)
{
    if (root == NULL)
        return;
    deque<TreeNode *> qu;
    qu.push_back(root);

    int k = 1;
    int null_cnt = 0;

    // int cur_depth = 0;

    while (!qu.empty() && null_cnt != (int)qu.size())
    {
        int next_k = 0;

        null_cnt = 0;

        while (k > 0)
        {
            TreeNode *node = qu.front();
            qu.pop_front();

            if (node)
            {
                cout << node->val << ", ";
                qu.push_back(node->left);
                next_k++;
                qu.push_back(node->right);
                next_k++;

                if (node->left == NULL)
                    null_cnt++;
                if (node->right == NULL)
                    null_cnt++;
            }
            else
            {
                cout << "NULL"
                     << ", ";
            }

            k--;
        }
        //cur_depth++;
        k = next_k;
    }
    return;
}
