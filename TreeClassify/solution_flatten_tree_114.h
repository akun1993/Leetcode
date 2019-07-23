#ifndef __SOLUTION_FLATTEN_TREE_H_
#define __SOLUTION_FLATTEN_TREE_H_

#include <vector>
#include "my_types.h"
#include <ISolution.h>
#include "TreeNode.h"
using namespace std;

class SolutionFlatten : public ISolution
{
public:
    SolutionFlatten(){}
    ~SolutionFlatten(){}
    void flatten(TreeNode *root);

    void answer();
};

#endif // __SOLUTION_FLATTEN_TREE_H_
