#ifndef _SOLUTION_TRAVERSE_INORDER_TREE_H_
#define _SOLUTION_TRAVERSE_INORDER_TREE_H_

#include <vector>
#include <stack>
#include <TreeNode.h>
#include <ISolution.h>

using namespace std;

class SolutionTraverseInorderTree : public ISolution
{
private:
    /* data */
public:
    SolutionTraverseInorderTree(){}
    ~SolutionTraverseInorderTree(){}

    vector<int> inorderTraversal(TreeNode *root);
    vector<int> inorderTraversalII(TreeNode *root);
    void answer();

};

#endif //  _SOLUTION_TRAVERSE_INORDER_TREE_H_
