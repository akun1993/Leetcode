
#ifndef __SOLUTION_SYMMERTIC_TREE_H_
#define __SOLUTION_SYMMERTIC_TREE_H_

#include "my_types.h"
#include <ISolutionBase.h>
#include "TreeNode.h"

class SolutionSymmertic : public ISolutionBase
{
public:
    bool isSymmetric(TreeNode *root);
    bool __Symmetric(TreeNode *lnode, TreeNode *rnode);
    bool SymmetricIterator(TreeNode *root);

    void answer();
};

#endif // __SOLUTION_FLATTEN_TREE_H_
