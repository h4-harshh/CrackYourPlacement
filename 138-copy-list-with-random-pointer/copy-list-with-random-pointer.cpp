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
    // Approach 1 by simply copying
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        unordered_map<Node *,Node*>mp;
        Node *newHead=nullptr;
        Node *prev=nullptr;

        Node *curr=head;
        while(curr)
        {
            Node *newNode=new Node(curr->val);
            mp[curr]=newNode;

            if(!newHead)
            {
                newHead=newNode;
                prev=newHead;
            }
            else{
                prev->next=newNode;
                prev=newNode;
            }

            curr=curr->next;
        }

        curr=head;
        Node *newcurr=newHead;
        while(curr)
        {
            if(curr->random==nullptr)
            {
                newcurr->random=nullptr;
            }
            else{
                newcurr->random=mp[curr->random];
            }
            curr=curr->next;
            newcurr=newcurr->next;
        }
        return newHead;
    }
};