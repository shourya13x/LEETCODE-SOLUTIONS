/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   ListNode * Collisonpoint(ListNode* t1,ListNode* t2,int d)
   {
            while(d)
            {
                d--;
                t2=t2->next;
            }
            while(t1!=t2)
            {
                  t1=t1->next;
                    t2=t2->next;
            }
         return t2;


   }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp =headA;
        int n1=0,n2=0;
        while(temp)
        {
             n1++;
            temp=temp->next;
        }
        temp =headB;
        while(temp)
        {
             n2++;
            temp=temp->next;
        }

       if(n1<n2)
       {
        return Collisonpoint(headA,headB,n2-n1);
       }
       else
       {
        return Collisonpoint(headB,headA,n1-n2);
       }







    }
};