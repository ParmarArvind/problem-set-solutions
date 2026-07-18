class Solution {
public:
    vector<int> arr;
    int n;

    Solution(ListNode* head) {
        ListNode* temp = head;

        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        n = arr.size();

        srand(time(0));      // Seed only once
    }

    int getRandom() {
        int idx = rand() % n;
        return arr[idx];
    }
};