#include "solution_isvalidbfs.h"

bool SolutionValidBfs::dfs(TreeNode *root, int dir, TreeNode *left_root, TreeNode *right_root)
{
    if (NULL == root)
        return true;

    if (root->left && root->left->val >= root->val)
        return false;

    if (root->right && root->right->val <= root->val)
        return false;

    if (left_root && root->val >= left_root->val)
        return false;

    if (right_root && root->val <= right_root->val)
        return false;

    bool res = true;
    if (dir == LEFT_LEFT)
    {
        if (res)
            res = dfs(root->left, LEFT_LEFT, root, right_root);
        if (res)
            res = dfs(root->right, LEFT_RIGHT, left_root, root);
    }

    if (dir == LEFT_RIGHT)
    {
        if (res)
            res = dfs(root->left, RIGHT_LEFT, root, right_root);
        if (res)
            res = dfs(root->right, RIGHT_RIGHT, left_root, root);
    }

    if (dir == RIGHT_LEFT)
    {
        if (res)
            res = dfs(root->left, LEFT_LEFT, root, right_root);
        if (res)
            res = dfs(root->right, LEFT_RIGHT, left_root, root);
    }

    if (dir == RIGHT_RIGHT)
    {
        if (res)
            res = dfs(root->left, RIGHT_LEFT, root, right_root);
        if (res)
            res = dfs(root->right, RIGHT_RIGHT, left_root, root);
    }

    return res;
}
bool SolutionValidBfs::dfsII(TreeNode *root, TreeNode *left_root, TreeNode *right_root)
{
    if (NULL == root)
        return true;

    if (root->left && root->left->val >= root->val)
        return false;

    if (root->right && root->right->val <= root->val)
        return false;

    if (left_root && root->val >= left_root->val)
        return false;

    if (right_root && root->val <= right_root->val)
        return false;

    bool res = dfsII(root->left, root, right_root);
    if (res)
        res = dfsII(root->right, left_root, root);
    return res;
}

bool SolutionValidBfs::IsValidBfs(TreeNode *root)
{
    if (root == NULL)
        return true;

    bool res = true;
    if (root->left)
    {
        if (root->left->val >= root->val)
            return false;
        res = dfsII(root->left, root, NULL);
    }
    if (root->right)
    {
        if (root->right->val <= root->val)
            return false;
        if (res)
            res = dfsII(root->right, NULL, root);
    }

    return res;
}

void SolutionValidBfs::answer()
{
    vector<int> case_1 = {5, 1, 4, NULL, NULL, 3, 6};

    vector<int> case_2 = {2, 1, 3};

    vector<int> case_3 = {3, NULL, 30, 10, NULL, NULL, 15, 1, 45}; //false

    vector<int> case_4 = {7, 1, 5, NULL, 2, 4, 6, NULL, NULL, NULL, 3}; //预锟节ｏ拷false
    vector<int> case_5 = {1, 2, 2, 5, 4, 4, 3};
    vector<vector<int> *> arr = {&case_1, &case_2, &case_3, &case_4, &case_5};

    TreeNode tree(0);

    for (int i = 0; i < (int)arr.size(); ++i)
    {
        vector<int> &tmp = *arr[i];
        TreeNode *head = tree.GenerateTree(tmp);

        tree.TranslevelII(head);

        //bool res = IsValidBfs(head);

        //int depth = tree.maxDepth(head);

        // bool is_symmetric = tree.SymmetricIterator(head);
        //tree.inorderTraversalII(head);
        TreeNode *p = tree.FindNodeByVal(head, 1);
        TreeNode *q = tree.FindNodeByVal(head, 3);

        TreeNode *res = tree.lowestCommonAncestorII(head, p, q);
        if (res)
            cout << endl
                 << "res is " << res->val << endl;
        else
            cout << endl
                 << "res is NULL" << endl;

        tree.flatten(head);

        tree.TranslevelII(head);

        //cout<< endl << "is valid dfs "<< res << endl
        //<< "depth is " << depth << endl <<"isSymmetric " << is_symmetric << endl;
    }
}

void SolutionValidBfs::answer()
{
}
