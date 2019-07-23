#ifndef __SOLUTION_LOWEST_COMMON_ACCESTOR_TREE_H_
#define __SOLUTION_LOWEST_COMMON_ACCESTOR_TREE_H_

#include <vector>
#include "my_types.h"
#include <ISolution.h>
#include "TreeNode.h"

using namespace std;

class SolutionLowestCommonAncestor : public ISolution
{
public:

    SolutionLowestCommonAncestor(){}
    ~SolutionLowestCommonAncestor(){}

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
    TreeNode *lowestCommonAncestorII(TreeNode *root, TreeNode *p, TreeNode *q);

    void answer();
};

#endif // __SOLUTION_LOWEST_COMMON_ACCESTOR_TREE_H_