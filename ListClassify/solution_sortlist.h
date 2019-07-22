#ifndef __SOLUTION_SORT_LIST_H_
#define __SOLUTION_SORT_LIST_H_

#include "ListNode.h"
#include <ISolutionBase.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionSortList : public ISolutionBase
{
public:
    
    ListNode * merge(ListNode* l1,ListNode* l2);
    
    ListNode*__merge_sort(ListNode* l1,int beg,int end);
    
    ListNode* sortList(ListNode* head);

    ListNode * mergeII(ListNode* l1,ListNode* l2,int len);

    ListNode* sortListII(ListNode* head);
    void answer();
 

};

#endif
