#include "solution_traverse_inorder_tree.h"


vector<int> SolutionTraverseInorderTree::inorderTraversal(TreeNode *root)
{

    vector<int> res;
    if (root == NULL)
        return res;
    stack<TreeNode *> st;

    while (root)
    {
        /* code */
        st.push(root);
        root = root->left;
    }

    while (!st.empty())
    {
        TreeNode *visit = st.top();
        st.pop();
        if (visit && visit->right)
        {
            st.push(visit->right);
            TreeNode *node = visit->right->left;
            while (node)
            {
                st.push(node);
                node = node->left;
            }
        }
        //TreeNode *visit = st.top();
        res.push_back(visit->val);
        //cout << visit->val << " ";
        /* code */
    }
    return res;
}

vector<int> SolutionTraverseInorderTree::inorderTraversalII(TreeNode *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    stack<TreeNode *> st;
    st.push(root);

    TreeNode *next = root;

    while (!st.empty())
    {
        if (next)
        {
            TreeNode *node = next->left;
            while (node)
            {
                st.push(node);
                node = node->left;
            }
        }
        TreeNode *visit = st.top();
        st.pop();
        res.push_back(visit->val);
        next = visit->right;
        if (visit->right)
        {
            st.push(visit->right);
        }
    }
    return res;
}

void SolutionTraverseInorderTree::answer()
{
    
}
