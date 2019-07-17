#ifndef __SOLUTION_FINDCYCLE_INDEX_
#define __SOLUTION_FINDCYCLE_INDEX_

#include "ListNode.h"

class SolutionFindCycleIndex
{
public:

    ListNode*FindCycle(ListNode* head)
    {
        if (!head || !head->next) return NULL;
        ListNode* slow = head, *fast = head;
        bool a = false;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) 
            {
                a = true;
                break;
            }
        }
        if (!a) return NULL;
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }

    void answer()
    {
        
    }

};

#endif
     
   