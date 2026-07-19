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

 // method 1
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        ListNode* curr=head;

        while(curr)
        {
            if(curr->val<x) {
                temp->next=new ListNode(curr->val);
                temp=temp->next;
            }
            curr=curr->next;
        }
        curr=head;
        while(curr)
        {
            if(curr->val>=x) {
                temp->next=new ListNode(curr->val);
                temp=temp->next;
            }
            curr=curr->next;
        }

        return dummy->next;
    }
};