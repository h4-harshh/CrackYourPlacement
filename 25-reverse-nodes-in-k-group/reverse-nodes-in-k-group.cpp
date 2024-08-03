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
    ListNode* reverseList(ListNode* head) {
        
        if(!head) return head;

        ListNode *curr=head;
        ListNode *prev=nullptr;
        ListNode *next;

        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode *find_kth(ListNode *curr,int k)
    {
        if(curr==nullptr) return nullptr;

        for(int i=0;i<k-1;i++)
        {
            if(curr)
                curr=curr->next;
            else
                break;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;

        ListNode *curr=head,*prevLast=nullptr;
        while(curr!=nullptr)
        {
            ListNode *kth_node=find_kth(curr,k);
            if(kth_node==nullptr)
            {
                if(prevLast) prevLast->next=curr;
                return head;
            }
            ListNode *nextHead=kth_node->next;
            kth_node->next=nullptr;
            reverseList(curr);

            if(curr==head)
            {
                head=kth_node;
                // continue;
            }
            else{
            prevLast->next=kth_node;}
            prevLast=curr;
            curr=nextHead;
        }
        return head;
    }
};