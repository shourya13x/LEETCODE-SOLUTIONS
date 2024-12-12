/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0; 
        ListNode* temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        if(count==n)
        {
           ListNode* newhead=head->next;
          delete head;
            return newhead;
        }
      temp =head;
      int res= count-n;
      while(temp){
        
    res--;
    if(res==0)
    { 
        break;
    }
     temp=temp->next;
      }
      ListNode* Deletenode =temp->next;
      temp->next=temp->next->next;
       delete Deletenode;
      return head;




    }
};