
#ifndef __LIST_NODE_H_
#define __LIST_NODE_H_

  //Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x) : val(x), next(nullptr) {}
 };

#endif
