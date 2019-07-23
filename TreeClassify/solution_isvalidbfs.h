#ifndef __SOLUTION_ISVALID_BFS_H_
#define __SOLUTION_ISVALID_BFS_H_

#include <vector>
#include "my_types.h"
#include <ISolution.h>
#include "TreeNode.h"

using namespace std;

class SolutionValidBfs : public ISolution
{
public:
    SolutionValidBfs(){}
    ~SolutionValidBfs(){}

    enum
    {
        LEFT_LEFT,
        LEFT_RIGHT,
        RIGHT_LEFT,
        RIGHT_RIGHT,
    };
    bool dfs(TreeNode* root,int dir ,TreeNode* left_root,TreeNode* right_root);
    bool dfsII(TreeNode* root,TreeNode* left_root,TreeNode* right_root);
    bool IsValidBfs(TreeNode* root);
    void answer();

};


#endif // __SOLUTION_UNIQUE_WAY_H_
