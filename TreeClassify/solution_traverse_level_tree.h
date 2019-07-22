#ifndef _SOLUTION_TRAVERSE_LEVEL_TREE_H_
#define _SOLUTION_TRAVERSE_LEVEL_TREE_H_

#include <ISolutionBase.h>
#include <TreeNode.h>

class SolutionTraverseLevelTree : public ISolutionBase
{
private:
    /* data */
public:
    struct Record_s
    {
        Record_s(TreeNode *node, int idx, int pos) : node(node), idx(idx), pos(pos) {}
        TreeNode *node;
        int idx;
        int pos;
    };

    void Translevel(TreeNode *root);
    void TranslevelII(TreeNode *root);
    SolutionTraverseLevelTree(/* args */){};
    ~SolutionTraverseLevelTree(){};
};




#endif //  _SOLUTION_TRAVERSE_LEVEL_TREE_H_



