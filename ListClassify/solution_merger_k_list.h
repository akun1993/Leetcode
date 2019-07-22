
#ifndef __LEET_LIST_H_
#define __LEET_LIST_H_

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include "ListNode.h"
#include <ISolutionBase.h>

using namespace std;

class SolutionList : public ISolutionBase
{
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    ListNode* mergeTwoListsII(ListNode* l1, ListNode* l2);

    ListNode *mergeTwoListsIII(ListNode *l1, ListNode *l2);


    ListNode* mergeKLists(vector<ListNode*>& lists);

    ListNode* removeNthFromEnd(ListNode* head, int n);

    ListNode* removeNthFromEndII(ListNode *head, int n);

    void answer();


};

#endif

