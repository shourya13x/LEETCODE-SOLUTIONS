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
     ListNode* reverseList(ListNode* head, int k) {
        if (!head) {
            return head;
        }
        ListNode* prev;
        ListNode* curr;
        ListNode* n;
        prev = head;
        curr = head->next;
        n = head->next;

        while(n && --k) {
            n = n->next;
            curr->next = prev;
            if (prev == head) {
                prev->next = NULL;
            }
            prev = curr;
            curr = n;
        }

        ListNode* temp = prev;
        if(n)
        {
            while(temp -> next)
            {
                temp = temp -> next;
            }
            temp -> next = n;
        }
        return prev;
    }

    int listSize(ListNode* node){
        int n = 0; 
        while(node)
        {
            n++;
            node = node -> next;
        }

        return n;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        
        int n = listSize(head);
        int nodeCount = 0;
        int remain = n % k;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* temp = dummy;
        while(temp && nodeCount != n - remain)
        {
            temp -> next = reverseList(temp -> next, k);
            int i = 0;
            while(temp && i < k)
            {
                temp = temp -> next;
                i++;
            }
            nodeCount += k;
        }


        return dummy -> next;
    }
};