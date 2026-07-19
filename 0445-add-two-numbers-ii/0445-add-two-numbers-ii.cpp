class Solution {
public:
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseLL(l1);
        l2=reverseLL(l2);

        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        int carry=0;
        while(l1 && l2)
        {
            int sum=l1->val+l2->val+carry;
            head->next=new ListNode(sum%10);
            head=head->next;
            carry = sum/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            int sum=l1->val+carry;
            head->next=new ListNode(sum%10);
            head=head->next;
            carry = sum/10;
            l1=l1->next;
        }
        while(l2)
        {
            int sum=l2->val+carry;
            head->next=new ListNode(sum%10);
            head=head->next;
            carry = sum/10;
            l2=l2->next;
        }
        if(carry) head->next=new ListNode(carry);
        
        dummy=reverseLL(dummy->next);
        return dummy;

    }
};