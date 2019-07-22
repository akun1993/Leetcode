#ifndef __INVERT_TREE_H_
#define __INVERT_TREE_H_

#include "TreeNode.h"
#include <deque>
#include <ISolutionBase.h>

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
    TreeNode* invertTreeI(TreeNode* root) ;
    TreeNode* invertTreeII(TreeNode* root); 
    void answer();

};

#endif
