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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // If the list is empty or has one element, it's already sorted.

        // Use a vector to extract all node values
        vector<int> values; // No need for `std::` here
        ListNode* temp = head;
        while (temp != nullptr) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        // Sort the vector
        sort(values.begin(), values.end()); // No need for `std::` here

        // Reassign the sorted values back to the list
        temp = head;
        for (int val : values) {
            temp->val = val;
            temp = temp->next;
        }

        return head;
    }
};