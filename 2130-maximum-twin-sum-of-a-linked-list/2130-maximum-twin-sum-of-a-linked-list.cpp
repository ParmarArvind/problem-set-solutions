// method -2 using stack
class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;
        stack<int>st;

        while(fast && fast->next)
        {
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        // now remove the st top and add it to the current nodes val i.e. its twin pair 
        int result=0;
        while(slow)
        {
            int currSum=st.top()+slow->val;
            st.pop();
            result=max(result,currSum);

            slow=slow->next;
        }        

        return result;

    }
};

// method -1
// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         ListNode* temp=head;
//         vector<int>arr;
//         while(temp)
//         {
//             arr.push_back(temp->val);
//             temp=temp->next;
//         }
//         int i=0;
//         int j=arr.size()-1;
//         int result=0;
//         while(i<j)
//         {
//             result=max(result,arr[i]+arr[j]);
//             i++;
//             j--;
//         }

//         return result;
//     }
// };