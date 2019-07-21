
#ifndef _LEETCODE_STRING_EXIST_H__
#define _LEETCODE_STRING_EXIST_H__

#include <iostream>
#include <vector>
#include <string>
#include <my_types.h>
#include "ISolutionBase.h"


class SolutionStringExist: public ISolutionBase
{
public:
    SolutionStringExist(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionStringExist(){}

    bool exist(std::vector<std::vector<char>>& board, std::string word);
    bool dfs(std::vector<std::vector<char>>& board,std::string &word,int idx,int x,int y,std::vector<std::vector<bool>> &visit);
    void answer();
};

extern SolutionStringExist string_exist;

#endif
