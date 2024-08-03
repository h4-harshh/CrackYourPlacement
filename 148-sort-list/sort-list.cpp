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
    ListNode *find_middle(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *left,ListNode *right)
    {
        ListNode *dummy=new ListNode(0);
        ListNode *curr=dummy;

        while(left && right)
        {
            if(left->val<=right->val)
            {
                curr->next=left;
                curr=curr->next;
                left=left->next;
            }
            else
            {
                curr->next=right;
                curr=curr->next;
                right=right->next;
            }
        }
        if(left) curr->next=left;
        else curr->next=right;

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {

        if(head==nullptr || head->next==nullptr) return head;

        ListNode *middle=find_middle(head);

        ListNode *right=middle->next;
        middle->next=nullptr;
        ListNode *left=head;

        left=sortList(left);
        right=sortList(right);

        return merge(left,right);      
    }
};