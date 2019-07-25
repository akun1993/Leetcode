
#ifndef _LEETCODE_STRING_EXIST_H__
#define _LEETCODE_STRING_EXIST_H__

#include <iostream>
#include <vector>
#include <string>
#include <my_types.h>
#include <ISolution.h>

// "给定的字符串是否在字符数组的一个序列\n"
// "例如 {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};\n"
// "可以看作是 'A','B','C','E','S','F','C','S','A','D','E','E'\n"
// "其中\"ABCCED\" 是上面序列的一个子序列\n"
// "解法： 使用深度优先搜索，并使用visit 数组记录是否被搜索过\n"

class SolutionStringExist : public ISolution
{
public:
    SolutionStringExist(){}
    ~SolutionStringExist(){}

    bool exist(std::vector<std::vector<char>>& board, std::string word);
    bool dfs(std::vector<std::vector<char>>& board,std::string &word,int idx,int x,int y,std::vector<std::vector<bool>> &visit);
    void answer();
};

extern SolutionStringExist string_exist;

#endif
