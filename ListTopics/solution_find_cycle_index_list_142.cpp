#include "solution_find_cycle_index_list_142.h"

ListNode *SolutionFindCycleIndex::FindCycle(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;
    ListNode *slow = head, *fast = head;
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
    if (!a)
        return nullptr;
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

void SolutionFindCycleIndex::answer()
{
}
