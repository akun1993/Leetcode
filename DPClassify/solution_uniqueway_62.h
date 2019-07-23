
#ifndef __SOLUTION_UNIQUE_WAY_H_
#define __SOLUTION_UNIQUE_WAY_H_

#include <vector>
#include <ISolution.h>
using namespace std;

//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//问总共有多少条不同的路径？

class SolutionUniqueWay : public ISolution
{
public:

    SolutionUniqueWay(){}
    ~SolutionUniqueWay(){}

    int uniquePaths(int m, int n);

    void answer();
};

#endif // __SOLUTION_UNIQUE_WAY_H_
