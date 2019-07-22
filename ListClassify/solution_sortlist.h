#ifndef __SOLUTION_SORT_LIST_H_
#define __SOLUTION_SORT_LIST_H_

#include "ListNode.h"
#include <ISolutionBase.h>
using namespace std;
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

    SolutionSortList(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionSortList(){}
    
    ListNode * merge(ListNode* l1,ListNode* l2);
    
    ListNode*__merge_sort(ListNode* l1,int beg,int end);
    
    ListNode* sortList(ListNode* head);

    ListNode * mergeII(ListNode* l1,ListNode* l2,int len);

    ListNode* sortListII(ListNode* head);
    void answer();
 

};

#endif
