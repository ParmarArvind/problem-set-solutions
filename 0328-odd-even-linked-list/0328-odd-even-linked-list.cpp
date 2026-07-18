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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

       vector<int>arr;
       ListNode* temp=head;
       while(temp)
       {
        arr.push_back(temp->val);
        temp=temp->next;
       } 

       temp=head;
       for(int i=0;i<arr.size();i+=2)
       {
        temp->val=arr[i];
        temp=temp->next;
       }

       for(int i=1;i<arr.size();i+=2)
       {
        temp->val=arr[i];
        temp=temp->next;
       }

       return head;
    }
};