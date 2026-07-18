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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast=head;
        ListNode* first=nullptr;
        ListNode* second=head;
        int n=k;
        while(k--) {
            first=fast;
            fast=fast->next;
        }
        
        while(fast)
        {
            second=second->next;
            fast=fast->next;
        }

        // swap
        int value=first->val;
        first->val=second->val;
        second->val=value;

        return head;

    }
};