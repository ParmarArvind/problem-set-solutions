/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//method -2 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* temp=head;
        // create new list nodes in the same list and fill the next pointer 
        while(temp)
        {
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }

        // fill the random pointer 
        temp=head;
        while(temp)
        {
            if(!temp->random)
            {
                temp->next->random=nullptr;
            }
            else{
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }

        // seperate the new list nodes from the input list

        temp=head;
        Node* newHead=head->next;
        Node* newTemp=newHead;

        while(temp && newTemp)
        {
            temp->next=temp->next ==NULL ? NULL : temp->next->next;
            newTemp->next=newTemp->next == NULL ? NULL  : newTemp->next->next;
            temp = temp->next;
            newTemp =newTemp->next;
        }

        return newHead;
    }
};


// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node* dummy=new Node(0);
//         unordered_map<Node* ,Node*> mp; // old node -> new node

//         Node * temp1=head;
//         Node* temp2=dummy;
//         while(temp1)
//         {
//             temp2->next=new Node(temp1->val);
//             temp2=temp2->next;
//             mp[temp1]=temp2;
//             temp1=temp1->next;
//         }

//         temp1=head;
//         while(temp1)
//         {
//             Node *oldNode=temp1;
//             if(!oldNode->random) mp[oldNode]->random=nullptr;
//             else {
//                 mp[oldNode]->random = mp[oldNode->random];
//             }

//             temp1=temp1->next;
//         }

//         return dummy->next;


//     }
// };