
#ifndef __LEET_LIST_H_
#define __LEET_LIST_H_

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include "ListNode.h"

using namespace std;

class SolutionList {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* head;

        if(l1->val < l2->val)
        {
            ListNode* tmp = l1->next;
            
            l1->next = l2;
            l2 = l1;   
            l1 = tmp;
        }
        
        head = l2;
        
        while(l1 && l2 )
        {
            if(l2->next == NULL)
            {
               // cout << l2->next << " "<< l2->val << " " << l1->val <<" " <<l1->next << endl;
                l2->next = l1 ;
                //cout << l2->next << " "<< l2->val << " " << l1->val <<" " <<l1->next << endl;
                //l1->next = NULL;
                break;
            }
            else
            {
                if( l1->val >= l2->val && l1->val < l2->next->val)
                {
                    ListNode* tmp2 = l2->next;
                    ListNode* tmp1 =  l1;
                    
                    while(tmp1->next && tmp1->next->val < l2->next->val)
                    {
                        tmp1 = tmp1->next;
                    }

                    l2->next = l1;
                    l1 = tmp1->next;
                    tmp1->next = tmp2;
                
                    l2 = tmp2;
                   // l1 = tmp1->next;
                }
                else
                {
                    l2 =  l2->next;
                }   
            }
        }
        return head;
    }


    ListNode* mergeTwoListsII(ListNode* l1, ListNode* l2) {
       
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* head ;
        if(l1->val > l2->val)
        {
            head = l2;
            l2 = l2->next;
        }
        else
        {
            head = l1;
            l1 = l1->next;
            /* code */
        }
        ListNode *ret = head;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }
            else
            {
                head->next = l1;
                head = l1;
                l1 = l1->next;
                /* code */
            }
        }
        head->next = l1 ? l1 : l2;
    
        return ret;
    }

    ListNode *mergeTwoListsIII(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *head = NULL;
        if (l1->val <= l2->val){
            head = l1;
            head->next = mergeTwoListsIII(l1->next, l2);
        } else {
            head = l2;
            head->next = mergeTwoListsIII(l1, l2->next);
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        
        if(lists.size() == 1) return lists[0];

        deque<ListNode*> qu;

        for(size_t i = 0; i < lists.size();++i)
        {
            qu.push_back(lists[i]);
        }

        while(qu.size() >= 2)
        {
            ListNode *p1 =  qu.front();  
            qu.pop_front();
            ListNode *p2 = qu.front();
            qu.pop_front();

            ListNode *head = mergeTwoListsII(p1,p2);

            qu.push_back(head);
        }
        return qu.front();  
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
       if(head == NULL) return head;

        if(n < 0) return head;

        ListNode *slow = head;
        ListNode *fast = head;
        int cnt = 1;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            ++cnt;
        }
        int node_num;
        if(fast) node_num = 2*cnt - 1;
        else node_num = 2*(cnt - 1) ;

        int node_idx = node_num - n + 1;
        //cout << node_num << " " << node_idx << endl;
        if(node_idx == 1)
        {
            head = head->next;
        }
        else
        {
            /* code */
            ListNode *tmp;
            if(node_idx > cnt)
                tmp = slow;
            else
            {
                cnt = 1;
                tmp = head;
            }
                
            
            while(node_idx - cnt != 1)
            {
                tmp = tmp->next;
                cnt++;
            }
            tmp->next = tmp->next->next;   
        }
        
        return head; 

    }

    ListNode* removeNthFromEndII(ListNode *head, int n) {
        if(head == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        for(int i = 0; i < n && fast != NULL; i++){
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }


    void answer()
    {


    }

};

#endif

