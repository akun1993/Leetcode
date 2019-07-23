
#ifndef _LEETCODE_STRING_EXIST_H__
#define _LEETCODE_STRING_EXIST_H__

#include <iostream>
#include <vector>
#include <string>
#include <my_types.h>
#include <ISolution.h>

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
