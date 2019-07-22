#ifndef __SOLUTION_LOWEST_COMMON_ACCESTOR_TREE_H_
#define __SOLUTION_LOWEST_COMMON_ACCESTOR_TREE_H_

#include <vector>
#include "my_types.h"
#include <ISolutionBase.h>
#include "TreeNode.h"

using namespace std;

class SolutionLowestCommonAncestor : public ISolutionBase
{
public:

    SolutionLowestCommonAncestor(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionLowestCommonAncestor(){}

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
    TreeNode *lowestCommonAncestorII(TreeNode *root, TreeNode *p, TreeNode *q);

    void answer();
};

#endif // __SOLUTION_LOWEST_COMMON_ACCESTOR_TREE_H_