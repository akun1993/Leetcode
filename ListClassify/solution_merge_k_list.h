
#ifndef __LEET_LIST_H_
#define __LEET_LIST_H_

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include "ListNode.h"
#include <ISolutionBase.h>

using namespace std;

class SolutionMergeKList : public ISolutionBase
{
public:
    SolutionMergeKList(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionMergeKList(){}

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    ListNode* mergeTwoListsII(ListNode* l1, ListNode* l2);

    ListNode *mergeTwoListsIII(ListNode *l1, ListNode *l2);


    ListNode* mergeKLists(vector<ListNode*>& lists);

    ListNode* removeNthFromEnd(ListNode* head, int n);

    ListNode* removeNthFromEndII(ListNode *head, int n);

    void answer();


};

#endif

