#ifndef _SOLUTION_TRAVERSE_LEVEL_TREE_H_
#define _SOLUTION_TRAVERSE_LEVEL_TREE_H_

#include <ISolutionBase.h>
#include <TreeNode.h>
#include <math.h>
using namespace std;

class SolutionTraverseLevelTree : public ISolutionBase
{
private:
    /* data */
public:

    SolutionTraverseLevelTree(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionTraverseLevelTree(){}

    struct Record_s
    {
        Record_s(TreeNode *node, int idx, int pos) : node(node), idx(idx), pos(pos) {}
        TreeNode *node;
        int idx;
        int pos;
    };

    void Translevel(TreeNode *root);
    void TranslevelII(TreeNode *root);

};




#endif //  _SOLUTION_TRAVERSE_LEVEL_TREE_H_



