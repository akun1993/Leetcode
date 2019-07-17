#ifndef __SOLUTION_SORT_LIST_H_
#define __SOLUTION_SORT_LIST_H_

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionSortList {
public:
    
    ListNode * merge(ListNode* l1,ListNode* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* head;
        
        if(l1->val > l2->val)
        {
            head = l2;
            
            head->next = merge(l1,l2->next);
        }
        else
        {
            head = l1;
            
            head->next = merge(l1->next,l2);
        }
        return head;
    }
    
    ListNode*__merge_sort(ListNode* l1,int beg,int end)
    {
        //if(l1 == NULL) return NULL;
        if(beg == end ) return l1;
       // cout << "beg is " << beg << " end is " << end << endl;
        if(beg + 1 == end)
        {
          //  cout << l1->next << endl;
            if(l1->val > l1->next->val)
            {
                ListNode* tmp = l1->next;
                l1->next = NULL;
                tmp->next = l1;
                l1 = tmp;
            }    
            return l1;
        }
        
        ListNode* l2 = l1;
        ListNode* before = NULL;
        
        int mid = beg + (end - beg) / 2;
        
        int i = beg;
        
        while(i < mid)
        {
            before = l2;
            l2 = l2->next;
            ++i;
        }
        if(before) before->next = NULL;
        
        l1 = __merge_sort(l1,beg,mid -1);
        l2 = __merge_sort(l2,mid,end);
        
        return merge(l1,l2);
        
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL) return head;
        
        int cnt = 0;
        
        ListNode* tmp = head;
        while(tmp)
        {
            tmp = tmp->next;
            ++cnt;
        }
        
        return __merge_sort(head,0,cnt - 1);
    }

    ListNode* sortList(ListNode* head) {
        
        if(head == NULL) return head;
        
        int cnt = 0;
        
        ListNode* tmp = head;
        while(tmp)
        {
            tmp = tmp->next;
            ++cnt;
        }
        
        return __merge_sort(head,0,cnt - 1);
    }


    ListNode * mergeII(ListNode* l1,ListNode* l2,int len)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(len == 0) return NULL;

        ListNode* head;
        
        if(l1->val > l2->val)
        {
            head = l2;
            
            head->next = mergeII(l1,l2->next,len - 1);
        }
        else
        {
            head = l1;
            
            head->next = mergeII(l1->next,l2,len - 1);
        }
        return head;
    }

    ListNode* sortListII(ListNode* head) {
        
        if(head == NULL) return head;
        
        deque<ListNode*> qu;
        
        ListNode* tmp = head;
        while(tmp)
        {
            qu.push_back(tmp);
            tmp = tmp->next;
        }
        
        //int step = 1;
        for(int step = 1; step < qu.size() / 2; step *= 2 )
        {
            int times = 0;
            int len = 2 * step;
            while(times + step <  qu.size())
            {
                mergeII(qu[times],qu[times + step],len);
                
                times += len;
            }
            
        }

        return qu[0];
    }
 

};

#endif
