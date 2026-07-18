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

 // method -2  Reservoir Sampling
class Solution {
public:
    ListNode* Head;
    Solution(ListNode* head) {
        Head=head;
    }
    
    int getRandom() {
        int count=1;
        int result=0;
        ListNode* temp=Head;
        while(temp)
        {
            if(rand()%count < 1.0/count)
            {
                result=temp->val;
            }
            temp=temp->next;
            count++;
        }

        return result;
    }
};



// class Solution {
// public:
//     vector<int> arr;
//     int n;

//     Solution(ListNode* head) {
//         ListNode* temp = head;

//         while (temp) {
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }

//         n = arr.size();

//         srand(time(0));      // Seed only once
//     }

//     int getRandom() {
//         int idx = rand() % n;
//         return arr[idx];
//     }
// };