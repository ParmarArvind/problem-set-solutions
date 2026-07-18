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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head->next && head->val==0) return nullptr;

        unordered_map<int,ListNode*>mp;
        int prefix=0;
        ListNode* dummy=new ListNode(0);
        mp[0]=dummy;

        dummy->next=head;
        
        while(head)
        {
            prefix += head->val;
            if(mp.find(prefix)!=mp.end())
            {
                int pSum=prefix;
                ListNode* temp=mp[prefix];

                while( temp!=head)
                {
                    temp=temp->next;
                    pSum+=temp->val;

                    if(temp!=head) 
                        mp.erase(pSum);
                }

                temp=mp[prefix];
                temp->next=head->next;
            }
            else{
                mp[prefix]=head;
            }
            head=head->next;
        }

        return dummy->next;

    }
};