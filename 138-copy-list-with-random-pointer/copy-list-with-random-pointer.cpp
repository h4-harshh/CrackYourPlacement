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

class Solution {
public:
    // Approach 2
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        //step1->inserting nodes

        Node *curr=head;
        while(curr)
        {
            Node *newNode=new Node(curr->val);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=curr->next==nullptr?nullptr:curr->next->next;
        }

        //step 2 random pointer
        curr=head;
        while(curr && curr->next)
        {
            if(curr->random==nullptr)
            {
                curr->next->random=nullptr;
            }
            else{
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }

        //step 3 seprating

        Node *newHead=head->next;
        Node *newcurr=newHead;

        curr=head;

        while(curr && newcurr)
        {
            curr->next=curr->next==nullptr?nullptr:curr->next->next;

            newcurr->next=newcurr->next==nullptr?nullptr:newcurr->next->next;

            curr=curr->next;
            newcurr=newcurr->next;
        }

        return newHead;
    }
};