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

 //method -1 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2== nullptr) return list1;

        ListNode* result;
        if(list1->val < list2->val)
        {
            result=list1;
            result->next=mergeTwoLists(list1->next,list2);
        }
        else {
            result=list2;
            result->next=mergeTwoLists(list1,list2->next);
        }

        return result;
    }
    ListNode* partionAndMerge(int start,int end,vector<ListNode*>& lists)
    {
        if(start>end) return NULL;
        if(start==end) return lists[start];
        
        int mid=start+(end-start)/2;

        ListNode* l1=partionAndMerge(start,mid,lists);
        ListNode* l2=partionAndMerge(mid+1,end,lists);

        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;

        return partionAndMerge(0,k-1,lists);
    }
};