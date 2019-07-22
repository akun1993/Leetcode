#ifndef _SOLUTION_TRAVERSE_INORDER_TREE_H_
#define _SOLUTION_TRAVERSE_INORDER_TREE_H_

#include <vector>
#include <stack>
#include <TreeNode.h>
#include <ISolutionBase.h>

using namespace std;

class SolutionTraverseInorderTree : public ISolutionBase
{
private:
    /* data */
public:
    SolutionTraverseInorderTree(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionTraverseInorderTree(){}

    vector<int> inorderTraversal(TreeNode *root);
    vector<int> inorderTraversalII(TreeNode *root);
    void answer();

};

#endif //  _SOLUTION_TRAVERSE_INORDER_TREE_H_
