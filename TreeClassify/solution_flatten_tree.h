#ifndef __SOLUTION_FLATTEN_TREE_H_
#define __SOLUTION_FLATTEN_TREE_H_

#include <vector>
#include "my_types.h"
#include <ISolutionBase.h>
#include "TreeNode.h"
using namespace std;


class SolutionFlatten : public ISolutionBase
{
public:
    SolutionFlatten(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionFlatten(){}
    void flatten(TreeNode *root);

    void answer();
};

#endif // __SOLUTION_FLATTEN_TREE_H_
