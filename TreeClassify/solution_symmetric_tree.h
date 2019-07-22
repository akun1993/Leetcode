
#ifndef __SOLUTION_SYMMERTIC_TREE_H_
#define __SOLUTION_SYMMERTIC_TREE_H_

#include "my_types.h"
#include <ISolutionBase.h>
#include "TreeNode.h"

using namespace std;

class SolutionSymmertic : public ISolutionBase
{
public:
    
    SolutionSymmertic(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionSymmertic(){}

    bool isSymmetric(TreeNode *root);
    bool __Symmetric(TreeNode *lnode, TreeNode *rnode);
    bool SymmetricIterator(TreeNode *root);

    void answer();
};

#endif // __SOLUTION_FLATTEN_TREE_H_
