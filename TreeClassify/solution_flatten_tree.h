#ifndef __SOLUTION_FLATTEN_TREE_H_
#define __SOLUTION_FLATTEN_TREE_H_

#include <vector>
#include "my_types.h"
#include <ISolutionBase.h>
#include "TreeNode.h"


class SolutionFlatten : public ISolutionBase
{
public:

    bool flatten(TreeNode *root, int dir, TreeNode *left_root, TreeNode *right_root);

    void answer();
};

#endif // __SOLUTION_FLATTEN_TREE_H_
