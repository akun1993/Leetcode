#ifndef __SOLUTION_FINDCYCLE_INDEX_
#define __SOLUTION_FINDCYCLE_INDEX_

#include "ListNode.h"
#include <ISolutionBase.h>
using namespace std;

class SolutionFindCycleIndex : public ISolutionBase
{
public:

    SolutionFindCycleIndex(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionFindCycleIndex(){}

    ListNode*FindCycle(ListNode* head);
    void answer();
};

#endif
     
   