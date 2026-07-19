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
    

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>st1;
        stack<int>st2;
        while(l1) {
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2) {
            st2.push(l2->val);
            l2=l2->next;
        }
        ListNode* result=new ListNode(0);
        ListNode* temp;
        int carry=0;
        while(!st1.empty() && !st2.empty())
        {
            temp=result->next;
            
            int sum=st1.top()+st2.top()+carry;
            ListNode* newNode=new ListNode(sum%10);

            newNode->next=temp;
            result->next=newNode;

            carry = sum/10;
            st1.pop();
            st2.pop();
        }
         while(!st1.empty() )
        {
            temp=result->next;

            int sum=st1.top()+carry;
            ListNode* newNode=new ListNode(sum%10);

            newNode->next=temp;
            result->next=newNode;

            carry = sum/10;
            st1.pop();
        }
        while(!st2.empty())
        {
            temp=result->next;
            
            int sum=st2.top()+carry;
            ListNode* newNode=new ListNode(sum%10);

            newNode->next=temp;
            result->next=newNode;

            carry = sum/10;
            st2.pop();
        }
        if(carry) {
            temp=result->next;
            ListNode* newNode=new ListNode(carry);

            newNode->next=temp;
            result->next=newNode;
        }

        return result->next;
        
    }
};


// class Solution {
// public:
//     ListNode* reverseLL(ListNode* head)
//     {
//         ListNode* curr=head;
//         ListNode* prev=nullptr;
//         while(curr)
//         {
//             ListNode* next=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=next;
//         }
//         return prev;
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         l1=reverseLL(l1);
//         l2=reverseLL(l2);

//         ListNode* dummy=new ListNode(0);
//         ListNode* head=dummy;
//         int carry=0;
//         while(l1 && l2)
//         {
//             int sum=l1->val+l2->val+carry;
//             head->next=new ListNode(sum%10);
//             head=head->next;
//             carry = sum/10;
//             l1=l1->next;
//             l2=l2->next;
//         }
//         while(l1)
//         {
//             int sum=l1->val+carry;
//             head->next=new ListNode(sum%10);
//             head=head->next;
//             carry = sum/10;
//             l1=l1->next;
//         }
//         while(l2)
//         {
//             int sum=l2->val+carry;
//             head->next=new ListNode(sum%10);
//             head=head->next;
//             carry = sum/10;
//             l2=l2->next;
//         }
//         if(carry) head->next=new ListNode(carry);
        
//         dummy=reverseLL(dummy->next);
//         return dummy;

//     }
// };