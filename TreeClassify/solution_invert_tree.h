#ifndef __INVERT_TREE_H_
#define __INVERT_TREE_H_

#include "TreeNode.h"
#include <deque>
#include <ISolutionBase.h>
using namespace std;

/* 翻转一棵二叉树。

// 示例：

// 输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
// 输出：

      4
     /  \
   7     2
  / \   / \
 9   6 3   1
*/
class SolutionInvertTree : public ISolutionBase
{
public:

    SolutionInvertTree(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionInvertTree(){}

    TreeNode* invertTreeI(TreeNode* root) ;
    TreeNode* invertTreeII(TreeNode* root); 
    void answer();

};

#endif
