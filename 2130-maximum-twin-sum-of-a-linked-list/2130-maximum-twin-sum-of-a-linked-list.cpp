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
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        vector<int>arr;
        while(temp)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int j=arr.size()-1;
        int result=0;
        while(i<j)
        {
            result=max(result,arr[i]+arr[j]);
            i++;
            j--;
        }

        return result;
    }
};