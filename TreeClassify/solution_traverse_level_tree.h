#ifndef _SOLUTION_TRAVERSE_LEVEL_TREE_H_
#define _SOLUTION_TRAVERSE_LEVEL_TREE_H_

#include <ISolution.h>
#include <TreeNode.h>
#include <math.h>
using namespace std;

class SolutionTraverseLevelTree : public ISolution
{
private:
    /* data */
public:

    SolutionTraverseLevelTree(){}
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



