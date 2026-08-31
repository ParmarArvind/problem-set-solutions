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


 

// method -2 TC=O(n) SC=O(1)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* temp=head->next;

        int prevVal=head->val;
        int i=1;
        
        int minIdx=-1;
        int maxIdx=-1;
        int prevIdx=-1;
        vector<int>result={INT_MAX , INT_MIN};

        while(temp && temp->next)
        {
            int currVal=temp->val;
            int nextVal=temp->next->val;
            temp=temp->next;

            if((currVal > prevVal && currVal > nextVal) || 
                (currVal< prevVal && currVal < nextVal) )
            {
                // calculate min distance
                if(prevIdx !=-1){
                    result[0]=min(result[0] ,i-prevIdx);
                }

                prevIdx=i;

                // update the minIdx , maxIdx and prevIdx
                if(minIdx==-1){
                    minIdx=i;
                }
                else {
                    maxIdx=i;
                }

                // calculate maximum distance
                if(minIdx != -1 && maxIdx !=-1 ) 
                {
                    result[1]=max(result[1] ,maxIdx-minIdx);
                }
            }
            i++;
            prevVal=currVal;
        }

        if(minIdx ==-1 || prevIdx ==-1 || maxIdx ==-1) return {-1,-1};
        return result;
    }
};


// // method -1 TC=O(n) SC=O(n)
// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int>arr;
//         ListNode* temp=head;

//         while(temp)
//         {
//             arr.push_back(temp->val);
//             temp=temp->next;
//         }

//         int minIdx=-1;
//         int maxIdx=-1;
//         int prevIdx=-1;
//         vector<int>result={INT_MAX , INT_MIN};
//         for(int i=1;i<arr.size()-1;i++)
//         {
//             if((arr[i] > arr[i-1] && arr[i] > arr[i+1]) || 
//                 (arr[i] < arr[i-1] && arr[i] < arr[i+1]) )
//             {
//                 // calculate min distance
//                 if(prevIdx !=-1){
//                     result[0]=min(result[0] ,i-prevIdx);
//                 }
                
//                 prevIdx=i;

//                 // update the minIdx , maxIdx and prevIdx
//                 if(minIdx==-1){
//                     minIdx=i;
//                 }
//                 else {
//                     maxIdx=i;
//                 }

//                 // calculate maximum distance
//                 if(minIdx != -1 && maxIdx !=-1 ) 
//                 {
//                     result[1]=max(result[1] ,maxIdx-minIdx);
//                 }
                
//             }
//         }

//         if(minIdx ==-1 || prevIdx ==-1 || maxIdx ==-1) return {-1,-1};
//         return result;
//     }
// };