
#ifndef __SOLUTION_SYMMERTIC_TREE_H_
#define __SOLUTION_SYMMERTIC_TREE_H_

#include "my_types.h"
#include <ISolution.h>
#include "TreeNode.h"

using namespace std;

class SolutionSymmertic : public ISolution
{
public:
    
    SolutionSymmertic(){}
    ~SolutionSymmertic(){}

    bool isSymmetric(TreeNode *root);
    bool __Symmetric(TreeNode *lnode, TreeNode *rnode);
    bool SymmetricIterator(TreeNode *root);

    void answer();
};

#endif // __SOLUTION_FLATTEN_TREE_H_
