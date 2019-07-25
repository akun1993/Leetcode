#ifndef __SOLUTION_FINDCYCLE_INDEX_
#define __SOLUTION_FINDCYCLE_INDEX_

#include "ListNode.h"
#include <ISolution.h>
using namespace std;

class SolutionFindCycleIndex : public ISolution
{
public:

    SolutionFindCycleIndex(){}

    ~SolutionFindCycleIndex(){}

    ListNode*FindCycle(ListNode* head);
    void answer();
};

#endif
     
   