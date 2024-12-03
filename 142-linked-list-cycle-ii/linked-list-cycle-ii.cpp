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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        unordered_map<ListNode*,int> mpp;
        ListNode* temp= head;
        while(temp)
        {
            
         if(mpp.find(temp)!=mpp.end())
         {
            return temp;
         }
         mpp[temp]=1;
        temp=temp->next;
        }
        return NULL;
    }
};