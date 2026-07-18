class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenDummy=new ListNode(0);
        ListNode* oddDummy=new ListNode(0);
        ListNode* temp=head;
        ListNode* even=evenDummy;
        ListNode* odd=oddDummy;
        int i=0;
        while(temp)
        {
            if(i%2==0) {
                even->next=new ListNode(temp->val);
                even=even->next;
            }
            else{
                odd->next=new ListNode(temp->val);
                odd=odd->next;
            }

            i++;
            temp=temp->next;
        }
        even->next=oddDummy->next;

    return evenDummy->next;
    }
};


// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if(!head || !head->next) return head;

//        vector<int>arr;
//        ListNode* temp=head;
//        while(temp)
//        {
//         arr.push_back(temp->val);
//         temp=temp->next;
//        } 

//        temp=head;
//        for(int i=0;i<arr.size();i+=2)
//        {
//         temp->val=arr[i];
//         temp=temp->next;
//        }

//        for(int i=1;i<arr.size();i+=2)
//        {
//         temp->val=arr[i];
//         temp=temp->next;
//        }

//        return head;
//     }
// };